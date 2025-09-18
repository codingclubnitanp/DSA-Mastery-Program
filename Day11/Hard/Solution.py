import heapq

class TaskManager:
    def __init__(self, tasks):
        self.priorityAndUser = {}
        self.executionOrder = []
        for userId, taskId, priority in tasks:
            self.priorityAndUser[taskId] = [priority, userId]
            heapq.heappush(self.executionOrder, (-priority, taskId))

    def add(self, userId, taskId, priority):
        self.priorityAndUser[taskId] = [priority, userId]
        heapq.heappush(self.executionOrder, (-priority, taskId))

    def edit(self, taskId, newPriority):
        if taskId in self.priorityAndUser:
            self.priorityAndUser[taskId][0] = newPriority
            heapq.heappush(self.executionOrder, (-newPriority, taskId))

    def rmv(self, taskId):
        if taskId in self.priorityAndUser:
            self.priorityAndUser[taskId][0] = -1

    def execTop(self):
        while self.executionOrder and self.priorityAndUser[self.executionOrder[0][1]][0] != -self.executionOrder[0][0]:
            heapq.heappop(self.executionOrder)
        if not self.executionOrder:
            return -1
        priority, taskId = heapq.heappop(self.executionOrder)
        self.priorityAndUser[taskId][0] = -1
        return self.priorityAndUser[taskId][1]


if __name__ == "__main__":
    tasks = [
        [1, 101, 10],
        [2, 102, 20],
        [3, 103, 15]
    ]

    tm = TaskManager(tasks)

    tm.add(4, 104, 5)
    tm.edit(102, 8)
    print(tm.execTop())  # expect 2
    tm.rmv(101)
    tm.add(5, 105, 15)
    print(tm.execTop())  # expect 3
    print(tm.execTop())  # expect 5
    
