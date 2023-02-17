class BinaryTreeNode:
  def __init__(self, data):
    self.right = None
    self.left = None
    self.data = data
  def PrintTree(self):
    if self.left:
      self.left.PrintTree()
    print(self.data)
    if self.right:
      self.right.PrintTree()
  def insert(self, data):
    if self.data:
      if self.data > data:
        if self.left is None:
          self.left = BinaryTreeNode(data)
        else:
          self.left.insert(data)
      elif data > self.data:
        if self.right is None:
          self.right = BinaryTreeNode(data)
        else:
          self.right.insert(data)
    else:
      self.data = data
  def inorderTraversal(self, root):
    res = []
    if root:
        res = self.inorderTraversal(root.left)
        res.append(root.data)
        res = res + self.inorderTraversal(root.right)
    return res
  def PreorderTraversal(self, root):
    res = []
    if root:
        res.append(root.data)
        res = res + self.PreorderTraversal(root.left)
        res = res + self.PreorderTraversal(root.right)
    return res
  def PostorderTraversal(self, root):
    res = []
    if root:
      res = self.PostorderTraversal(root.left)
      res = res + self.PostorderTraversal(root.right)
      res.append(root.data)
    return res
  def find(self, key):
    print('Visiting node: ' + str(self.data))
    if self.data == key:
      return str(self.data) + ' Found'
    if key > self.data:
      if self.right is None:
        return str(key) + ' Not Found'
      return self.right.find(key)
    elif key < self.data:
      if self.left is None:
        return str(key) + ' Not Found'
      return self.left.find(key)
  def calculateHeight(self):
    edges = []
    if root:
      edges.append(1)
      edges = edges + self.calculateHeight(root.right)
      edges = edges + self.calculateHeight(root.left)

      
      

root = BinaryTreeNode(27)
root.insert(14)
root.insert(35)
root.insert(10)
root.insert(19)
root.insert(31)
root.insert(42)
#print(root.inorderTraversal(root))
#print(root.PreorderTraversal(root))
#print(root.PostorderTraversal(root))
#root.PrintTree()
print(root.find(31))
print(root.find(3111))