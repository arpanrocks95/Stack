class stack:
    top = -1
    array = []

    def push(self,data):
        self.top = self.top+1
        self.array.append(data)

    def pop(self):
        if self.top == -1:
            print("stack is already empty")
            return
        self.array.pop()
        self.top = self.top - 1
    def peek(self):
        print(self.array[self.top])

if __name__=='__main__':
    MyStack = stack()
    MyStack.push(10)
    MyStack.push(11)
    MyStack.push(12)
    MyStack.push(13)
    MyStack.peek()
    MyStack.pop()
    MyStack.peek()