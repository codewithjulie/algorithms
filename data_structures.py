# Stack

class Stack:
    def __init__(self):
        self.items = []

    def push(self, elem):
        self.items.append(elem)
    
    def pop(self):
        self.items.pop()

    def size(self):
        return len(self.items)
        
stack = Stack()
print(stack)