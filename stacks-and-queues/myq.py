class QueueNode:
  def __init__(self, data):
    self.data = data
    self.next = None

class Queue:
  def __init__(self):
    self.first = None
    self.last = None
  
  def add(self, item):
    node = QueueNode(item)
    if self.first is None:
      self.first = node ## handle adding to empty queue
    else:
      self.last.next = node
    self.last = node
    
  def remove(self):
    if self.last is None:
      raise LookupError('Queue is empty')
    item = self.first.data
    self.first = self.first.next

    if self.first is None: ## handle queue being empty after removal
      self.last = None
    return item
  def peek(self):
    if self.last is None:
      raise LookupError('Queue is empty')
    return self.first.data
  def isEmpty(self):
    return self.first is None

q = Queue()
q.add(5)
q.add(10)
q.add(15)
q.add(20)
print(q.peek())
print(q.isEmpty())
q.remove()
q.remove()
print(q.peek())
q.remove()
q.remove()
print(q.isEmpty())