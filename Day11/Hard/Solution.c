#include <stdio.h>
#include <stdlib.h>

typedef struct { int priority; int userId; int valid; } Task;
typedef struct { int priority; int taskId; } HeapNode;
typedef struct { Task** tasks; int cap; HeapNode** heap; int heapSize; int heapCap; } TaskManager;

HeapNode* createNode(int priority, int taskId) {
    HeapNode* n = (HeapNode*)malloc(sizeof(HeapNode));
    n->priority = priority;
    n->taskId = taskId;
    return n;
}

void swapNode(HeapNode** a, HeapNode** b) {
    HeapNode* t = *a;
    *a = *b;
    *b = t;
}

int cmpNode(HeapNode* a, HeapNode* b) {
    if (a->priority != b->priority) return a->priority > b->priority;
    return a->taskId > b->taskId;
}

void heapPush(TaskManager* obj, HeapNode* node) {
    if (obj->heapSize + 1 > obj->heapCap) {
        obj->heapCap = obj->heapCap * 2;
        if (obj->heapCap < 4) obj->heapCap = 4;
        obj->heap = (HeapNode**)realloc(obj->heap, sizeof(HeapNode*) * (obj->heapCap + 1));
    }
    obj->heap[++obj->heapSize] = node;
    int i = obj->heapSize;
    while (i > 1 && cmpNode(obj->heap[i], obj->heap[i/2])) {
        swapNode(&obj->heap[i], &obj->heap[i/2]);
        i /= 2;
    }
}

HeapNode* heapTop(TaskManager* obj) {
    if (obj->heapSize == 0) return NULL;
    return obj->heap[1];
}

HeapNode* heapPopNode(TaskManager* obj) {
    if (obj->heapSize == 0) return NULL;
    HeapNode* ret = obj->heap[1];
    obj->heap[1] = obj->heap[obj->heapSize--];
    int i = 1;
    while (1) {
        int largest = i;
        int l = 2 * i, r = 2 * i + 1;
        if (l <= obj->heapSize && cmpNode(obj->heap[l], obj->heap[largest])) largest = l;
        if (r <= obj->heapSize && cmpNode(obj->heap[r], obj->heap[largest])) largest = r;
        if (largest != i) {
            swapNode(&obj->heap[i], &obj->heap[largest]);
            i = largest;
        } else break;
    }
    return ret;
}

TaskManager* taskManagerCreate(int** tasks, int tasksSize, int* tasksColSize) {
    TaskManager* obj = (TaskManager*)malloc(sizeof(TaskManager));
    obj->cap = 200005;
    obj->tasks = (Task**)calloc(obj->cap, sizeof(Task*));
    obj->heapCap = tasksSize * 2 + 5;
    if (obj->heapCap < 4) obj->heapCap = 4;
    obj->heap = (HeapNode**)malloc(sizeof(HeapNode*) * (obj->heapCap + 1));
    obj->heapSize = 0;
    for (int i = 0; i < tasksSize; i++) {
        int userId = tasks[i][0];
        int taskId = tasks[i][1];
        int priority = tasks[i][2];
        if (taskId >= obj->cap) {
            int newcap = obj->cap;
            while (taskId >= newcap) newcap *= 2;
            obj->tasks = (Task**)realloc(obj->tasks, sizeof(Task*) * newcap);
            for (int j = obj->cap; j < newcap; j++) obj->tasks[j] = NULL;
            obj->cap = newcap;
        }
        Task* t = (Task*)malloc(sizeof(Task));
        t->priority = priority;
        t->userId = userId;
        t->valid = 1;
        obj->tasks[taskId] = t;
        HeapNode* n = createNode(priority, taskId);
        heapPush(obj, n);
    }
    return obj;
}

void taskManagerAdd(TaskManager* obj, int userId, int taskId, int priority) {
    if (taskId >= obj->cap) {
        int newcap = obj->cap;
        while (taskId >= newcap) newcap *= 2;
        obj->tasks = (Task**)realloc(obj->tasks, sizeof(Task*) * newcap);
        for (int j = obj->cap; j < newcap; j++) obj->tasks[j] = NULL;
        obj->cap = newcap;
    }
    if (obj->tasks[taskId]) free(obj->tasks[taskId]);
    Task* t = (Task*)malloc(sizeof(Task));
    t->priority = priority;
    t->userId = userId;
    t->valid = 1;
    obj->tasks[taskId] = t;
    HeapNode* n = createNode(priority, taskId);
    heapPush(obj, n);
}

void taskManagerEdit(TaskManager* obj, int taskId, int newPriority) {
    if (taskId >= obj->cap) return;
    Task* t = obj->tasks[taskId];
    if (!t || !t->valid) return;
    t->priority = newPriority;
    HeapNode* n = createNode(newPriority, taskId);
    heapPush(obj, n);
}

void taskManagerRmv(TaskManager* obj, int taskId) {
    if (taskId >= obj->cap) return;
    Task* t = obj->tasks[taskId];
    if (!t) return;
    t->valid = 0;
}

int taskManagerExecTop(TaskManager* obj) {
    while (obj->heapSize > 0) {
        HeapNode* top = heapTop(obj);
        Task* t = NULL;
        if (top->taskId < obj->cap) t = obj->tasks[top->taskId];
        if (!t || !t->valid || t->priority != top->priority) {
            HeapNode* rem = heapPopNode(obj);
            free(rem);
            continue;
        }
        int userId = t->userId;
        t->valid = 0;
        HeapNode* rem = heapPopNode(obj);
        free(rem);
        return userId;
    }
    return -1;
}

void taskManagerFree(TaskManager* obj) {
    for (int i = 0; i < obj->cap; i++) if (obj->tasks[i]) free(obj->tasks[i]);
    free(obj->tasks);
    for (int i = 1; i <= obj->heapSize; i++) free(obj->heap[i]);
    free(obj->heap);
    free(obj);
}

int main() {
    int initArr[3][3] = {
        {1, 101, 10},
        {2, 102, 20},
        {3, 103, 15}
    };
    int* initPtrs[3];
    for (int i = 0; i < 3; i++) initPtrs[i] = initArr[i];
    int colSize[3] = {3,3,3};

    TaskManager* tm = taskManagerCreate(initPtrs, 3, colSize);

    taskManagerAdd(tm, 4, 104, 5);
    taskManagerEdit(tm, 102, 8);
    printf("%d\n", taskManagerExecTop(tm));   // expected 3
    taskManagerRmv(tm, 101);
    taskManagerAdd(tm, 5, 105, 15);
    printf("%d\n", taskManagerExecTop(tm));   // expected 5

    taskManagerFree(tm);
    return 0;
}
