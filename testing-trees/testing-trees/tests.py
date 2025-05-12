import unittest
from tree import BinaryTree, Node

class TestBinaryTree(unittest.TestCase):

    def setUp(self):
        self.tree = BinaryTree()

    def test_insert(self):
        self.tree.insert(10)
        self.assertEqual(self.tree.root.val, 10)
        self.tree.insert(5)
        self.assertEqual(self.tree.root.left.val, 5)
        self.tree.insert(15)
        self.assertEqual(self.tree.root.right.val, 15)

    def test_inorder_traversal(self):
        keys = [10, 5, 15, 3, 7, 12, 18]
        for key in keys:
            self.tree.insert(key)
        self.assertEqual(self.tree.inorder_traversal(self.tree.root), [3, 5, 7, 10, 12, 15, 18])

    def test_preorder_traversal(self):
        keys = [10, 5, 15, 3, 7, 12, 18]
        for key in keys:
            self.tree.insert(key)
        self.assertEqual(self.tree.preorder_traversal(self.tree.root), [10, 5, 3, 7, 15, 12, 18])

    def test_postorder_traversal(self):
        keys = [10, 5, 15, 3, 7, 12, 18]
        for key in keys:
            self.tree.insert(key)
        self.assertEqual(self.tree.postorder_traversal(self.tree.root), [3, 7, 5, 12, 18, 15, 10])

if __name__ == '__main__':
    unittest.main()