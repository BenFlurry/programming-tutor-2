from typing import List

class Node:
    def __init__(self, key: int):
        self.left = None
        self.right = None
        self.val = key

class BinaryTree:
    def __init__(self) -> None:
        """
        Initialise the tree with an empty root
        """
        self.root = None

    def insert(self, key: int) -> None:
        if self.root is None:
            self.root = Node(key)
        else:
            self._insert(self.root, key)

    def _insert(self, root: Node, key: int) -> None:
        """
        create the recursive function which finds the correct location to insert the node, and inserts the node
        """

    def inorder_traversal(self, root: Node) -> List[int]:
        """
        create the function which recursively (or iteratively if you really want) traverses the tree, resulting in an in-order list returned.
        """
        traversal: List[int] = []
        return traversal

    def preorder_traversal(self, root: Node) -> List[int]:
        """
        create the function which recursively (or iteratively if you really want) traverses the tree, resulting in an pre-order list returned.
        """
        traversal: List[int] = []
        return traversal

    def postorder_traversal(self, root: Node) -> List[int]:
        """
        create the function which recursively (or iteratively if you really want) traverses the tree, resulting in an post-order list returned.
        """
        traversal: List[int] = []
        return traversal