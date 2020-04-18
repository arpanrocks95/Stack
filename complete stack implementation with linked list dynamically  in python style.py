class stackNode:
    def __init__(self,data):
        self.data = data
        self.next = None

class stack:
    def __init__(self):
        self.head = None
    def push(self,data):
        temp = stackNode(data)
        temp.next = self.head
        self.head = temp
    def peek(self):
        print("data in top is {0}".format(self.head.data))
    def pop(self):
        temp = self.head
        self.head = self.head.next
        print("popped data is {0}".format(temp.data))
        temp = None
if __name__=='__main__':
    MyStack = stack()
    MyStack.push(10)
    MyStack.push(11)
    MyStack.push(12)
    MyStack.push(13)
    MyStack.peek()
    MyStack.pop()
    MyStack.peek()