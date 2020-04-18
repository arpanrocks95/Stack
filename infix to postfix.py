# stack program
class stackNode:
    def __init__(self, data):
        self.data = data
        self.next = None


class stack:
    def __init__(self):
        self.head = None

    def push(self, data):
        temp = stackNode(data)
        temp.next = self.head
        self.head = temp

    def peek(self):
        if self.head is None:
            print("stack is empty")
        else:
            return self.head.data

    def pop(self):
        temp = self.head
        self.head = self.head.next
        print("popped data is {0}".format(temp.data))
        temp = None

    def isempty(self):
        if self.head is None:
            return True
        else:
            return False


# to check whether its operand or operator

def isoperand(ch):
    if ((ch >= 'a' and ch <= 'z') or (ch >= 'A' and ch <= 'Z')):
        return True
    else:
        return False


# to check operator precedence
def opprecedence(ch):
    dict1 = {'+': 1, '-': 1, '*': 2, '/': 2, '^': 3, '(': -1}
    return dict1[ch]


def infixtopostfix(infix_exp):
    print('hi')
    templist = []
    s1 = stack()
    for i in infix_exp:
        print(i)
        if isoperand(i):
            templist.append(i)
        else:
            if i is '(':
                s1.push(i)
            elif i is ')':
                print('in hell')
                while not s1.isempty() and s1.peek() is not '(':
                    #print('inside hells while')
                    templist.append(s1.peek())
                    s1.pop()
                s1.pop()
            else:
                while not s1.isempty() and opprecedence(i) <= opprecedence(s1.peek()):
                    templist.append(s1.peek())
                    s1.pop()
                s1.push(i)
        print("list is : ", templist)
        print("stack top is : ", s1.peek())
    while not s1.isempty():
        templist.append(s1.peek())
        s1.pop()
    print(templist)

if __name__ == '__main__':
    infixexp = "(L-K/A)*(C/B-A)"
    infixtopostfix(infixexp)
