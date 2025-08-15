class MinStack:

    def __init__(self):
        self.stk = []
        self.mini = 0


    def push(self, val: int) -> None:
        if(not self.stk):
            self.stk.append(0)
            self.mini = val
        else:
            self.stk.append(val-self.mini)
            if(val < self.mini): self.mini = val

    def pop(self) -> None:
        top = self.stk.pop()
        if(top < 0): self.mini = self.mini - top

    def top(self) -> int:
        top = self.stk[-1]

        if(top > 0):
            return top + self.mini
        
        return self.mini

    def getMin(self) -> int:
        return self.mini
