class StackNode:
  def __init__(self, data):
    self.next = None
    self.data = data
class Stack:
  def __init__(self):
    self.top = None
  def push(self, data):
    item = StackNode(data)
    item.next = self.top
    self.top = item
  def pop(self):
    if self.top is None:
      raise LookupError('stack is empty')
    item = self.top
    self.top = self.top.next
    return item 
  def peek(self):
    if self.top is None:
      raise LookupError('stack is empty')
    return self.top.data
  def isEmpty(self):
    return self.top is None

myStack = Stack()
myStack.push(10)
myStack.push(15)
myStack.push(20)
myStack.push(25)
myStack.pop()
myStack.pop()
print(myStack.peek())
print(myStack.isEmpty())
myStack.pop()
myStack.pop()
print(myStack.isEmpty())
