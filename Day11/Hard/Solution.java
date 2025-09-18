
class TaskManager {
    private Map<Integer, int[]> priorityAndUser;
    private PriorityQueue<int[]> executionOrder;

    public TaskManager(List<List<Integer>> tasks) {
        priorityAndUser = new HashMap<>();
        executionOrder = new PriorityQueue<>((a, b) -> b[0] - a[0]);
        for (List<Integer> task : tasks) {
            int userId = task.get(0);
            int taskId = task.get(1);
            int priority = task.get(2);
            priorityAndUser.put(taskId, new int[]{priority, userId});
            executionOrder.add(new int[]{priority, taskId});
        }
    }

    public void add(int userId, int taskId, int priority) {
        priorityAndUser.put(taskId, new int[]{priority, userId});
        executionOrder.add(new int[]{priority, taskId});
    }

    public void edit(int taskId, int newPriority) {
        if (priorityAndUser.containsKey(taskId)) {
            priorityAndUser.get(taskId)[0] = newPriority;
            executionOrder.add(new int[]{newPriority, taskId});
        }
    }

    public void rmv(int taskId) {
        if (priorityAndUser.containsKey(taskId)) {
            priorityAndUser.get(taskId)[0] = -1;
        }
    }

    public int execTop() {
        while (!executionOrder.isEmpty() &&
               priorityAndUser.get(executionOrder.peek()[1])[0] != executionOrder.peek()[0]) {
            executionOrder.poll();
        }
        if (executionOrder.isEmpty()) {
            return -1;
        }
        int[] p = executionOrder.poll();
        priorityAndUser.get(p[1])[0] = -1;
        return priorityAndUser.get(p[1])[1];
    }
}

public class Main {
    public static void main(String[] args) {
        List<int[]> tasks = new ArrayList<>();
        tasks.add(new int[]{1, 101, 10});
        tasks.add(new int[]{2, 102, 20});
        tasks.add(new int[]{3, 103, 15});

        TaskManager tm = new TaskManager(tasks);

        tm.add(4, 104, 5);
        tm.edit(102, 8);
        System.out.println(tm.execTop());
        tm.rmv(101);
        tm.add(5, 105, 15);
        System.out.println(tm.execTop());
        System.out.println(tm.execTop());
    }
}
