class Stack:
    def __init__(self):
        self.stack = []
    
    def push(self, inum):
        self.stack.append(inum)

    def pop(self):
        if len(self.stack) == 0:
            print(-1)
        else:
            print(self.stack.pop(-1))

    def size(self):
        print(len(self.stack))

    def empty(self):
        if len(self.stack) == 0:
            print(0)
        else:
            print(1)
    def top(self):
        if len(self.stack) == 0:
            print(-1)
        else:
            print(self.stack[-1])

def main():
    stack = Stack()

    num = input()
    for i in range(int(num)):
        item = str(input()).split(' ')
        if item[0] == 'push':
            stack.push(int(item[1]))
        elif item[0] == 'pop':
            stack.pop()
        elif item[0] == 'size':
            stack.size()
        elif item[0] == 'empty':
            stack.empty()
        elif item[0] == 'top':
            stack.top()
        else:
            print("Invalid input")
if __name__ == "__main__":
    main()
