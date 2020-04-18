class queue:
    def __init__(self):
        self.listq = []

    def enQueue(self, data):
        self.listq.append(data)

    def deQueue(self):
        if not self.listq:
            print("queue is empty ")
        else:
            temp = self.listq[0]
            self.listq.pop(0)
            return temp

    def display(self):
        if not self.listq:
            print("queue is empty ")
        else:
            count = 1;
            for i in range(len(self.listq)):
                print("data in pos  {0} is {1}".format(count, self.listq[i]))
                count = count + 1


class stackFromQueue():
    def __init__(self):
        self.top = -1
        self.q1 = queue()

    def push(self, data):
        self.q1.enQueue(data)
        self.top = self.top + 1

    def pop(self):
        q2 = queue()
        for i in range(self.top ):
            q2.enQueue(self.q1.deQueue())
        self.q1 = q2
        self.top = self.top - 1

    def peek(self):
        self.q1.display()


if __name__ == '__main__':
    s1 = stackFromQueue()
    s1.push(10)
    s1.push(11)
    s1.push(12)
    s1.peek()
    s1.pop()
    s1.peek()
