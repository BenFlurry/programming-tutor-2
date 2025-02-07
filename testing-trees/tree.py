class Node:
    def __init__(self, key):
        self.left = None
        self.right = None
        self.val = key

class BinaryTree:
    def __init__(self):
        self.root = None

    def insert(self, key):
        if self.root is None:
            self.root = Node(key)
        else:
            self._insert(self.root, key)

    def _insert(self, root, key):
        if key < root.val:
            if root.left is None:
                root.left = Node(key)
            else:
                self._insert(root.left, key)
        else:
            if root.right is None:
                root.right = Node(key)
            else:
                self._insert(root.right, key)

    def inorder_traversal(self, root):
        traversal = []
        if root:
            traversal = self.inorder_traversal(root.left)
            traversal.append(root.val)
            traversal = traversal + self.inorder_traversal(root.right)
        return traversal

    def preorder_traversal(self, root):
        traversal = []
        if root:
            traversal.append(root.val)
            traversal = traversal + self.preorder_traversal(root.left)
            traversal = traversal + self.preorder_traversal(root.right)
        return traversal

    def postorder_traversal(self, root):
        traversal = []
        if root:
            traversal = self.postorder_traversal(root.left)
            traversal = traversal + self.postorder_traversal(root.right)
            traversal.append(root.val)
        return traversal