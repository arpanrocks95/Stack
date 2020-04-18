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


def postfixtoprefix(prefix_exp):
    s1 = stack()
    for i in prefix_exp:
        if isoperand(i):
            s1.push(i)
        else:
            op1 = s1.peek()
            s1.pop()
            op2 = s1.peek()
            s1.pop()
            temp = i + op2 + op1
            s1.push(temp)
    return s1.peek()


if __name__ == '__main__':
    postfix_exp = "ABC/-AK/L-*"
    print(postfixtoprefix(postfix_exp))
