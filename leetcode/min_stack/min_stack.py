import sys

class MinStack:
    def __init__(self):
        self.minSt = []
        self.st = []
        self.min_st_index = -1

    def push(self, val: int) -> None:
        if len(self.st) == 0:
            self.minSt.append(val)
            self.st.append(val)
            self.min_st_index += 1
        else:
            if val <= self.minSt[self.min_st_index]:
                self.minSt.append(val)
                self.min_st_index += 1
            self.st.append(val)


    def pop(self) -> None:
        if len(self.st) == 0:
            return
        if len(self.minSt) != 0 and self.st[len(self.st) - 1] == self.minSt[self.min_st_index]:
            self.minSt.pop()
            self.min_st_index -= 1
        self.st.pop()


    def top(self) -> int:
        return self.st[len(self.st) - 1]


    def getMin(self) -> int:
        return self.minSt[self.min_st_index]


obj = MinStack()
obj.push(-2)
obj.push(0)
obj.push(-3)
print(obj.getMin())
obj.pop()
print(obj.top())
print(obj.getMin())

