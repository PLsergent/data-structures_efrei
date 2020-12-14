class TreeNode:

    def __init__(self, data):
        self.left = None
        self.right = None
        self.data = data

    def __str__(self):
        return f"TreeNode [value: {self.data}," \
               f"left: {self.left.data if self.left is not None else 'None'}," \
               f"right: {self.right.data if self.right is not None else 'None'}]"

# Insert TreeNode
    def insert(self, data):
        if self.data:
            if data < self.data:
                if self.left is None:
                    self.left = TreeNode(data)
                else:
                    self.left.insert(data)
            elif data > self.data:
                if self.right is None:
                    self.right = TreeNode(data)
                else:
                    self.right.insert(data)
        else:
            self.data = data

# Print the tree
    def print_tree(self):
        if self.left:
            self.left.print_tree()
        print(self.data)
        if self.right:
            self.right.print_tree()

# Inorder traversal
# Left -> Root -> Right
    def inorder_traversal(self, root, obj):
        res = []
        if root:
            res = self.inorder_traversal(root.left, obj)
            res.append(root) if obj else res.append(root.data)
            res = res + self.inorder_traversal(root.right, obj)
        return res

# Preorder traversal
# Root -> Left -> Right
    def preorder_traversal(self, root):
        res = []
        if root:
            res.append(root.data)
            res = res + self.preorder_traversal(root.left)
            res = res + self.preorder_traversal(root.right)
        return res

# Postorder traversal
# Left -> Right -> Root
    def postorder_traversal(self, root):
        res = []
        if root:
            res = self.postorder_traversal(root.left)
            res = res + self.postorder_traversal(root.right)
            res.append(root.data)
        return res


# Min value
    def min_tree(self, root):
        return root.data if root.left is None else self.min_tree(root.left)

# Max value
    def max_tree(self, root):
        return root.data if root.right is None else self.max_tree(root.right)


# Search Node based on value
    def search_tree(self, root, value):
        if root:
            if root.data == value:
                return root
            elif root.data < value:
                return self.search_tree(root.right, value)
            else:
                return self.search_tree(root.left, value)
        return None


# Delete Node based on value
    def remove_tree(self, root, value):
        if root:
            new_root = TreeNode(root.data) # Create new root
            if root.data == value:
                print("Can't delete root node!")
                return [None, None]
            
            nodes = self.inorder_traversal(root, True) # Get all nodes
            del root # Delete old root

            for node in nodes: # For each node
                if node.data == value:
                    deleted = node # get the deleted node
                else:
                    new_root.insert(node.data) # insert the non deleted value to the new tree
                del node # Delete old nodes
        # Return new tree root and the deleted node
        return [new_root, deleted]


# Breadth first traversal of tree
    def breadth_first_search(self, root):
        res = []
        if root:
            to_visit = [root]
            while to_visit:
                current = to_visit.pop(0)
                res.append(current.data)
                if current.left:
                    to_visit.append(current.left)
                if current.right:
                    to_visit.append(current.right)  
        return res         

# Height of the tree
    def height(self, root):
        if root is None:
            return -1
        else:
            return max(self.height(root.left), self.height(root.right)) + 1

# Number of nodes
    def number_of_nodes(self):
        return len(self.inorder_traversal(self, False))

if __name__ == "__main__":
    root = TreeNode(27)
    root.insert(14)
    root.insert(35)
    root.insert(10)
    root.insert(19)
    root.insert(31)
    root.insert(42)

    print("Tree exploring >>>\n")
    print("Inorder :\n", root.inorder_traversal(root, False))
    print("Preorder :\n", root.preorder_traversal(root))
    print("Postorder :\n", root.postorder_traversal(root))
    print("BFS :\n", root.breadth_first_search(root))

    print()

    print("Tree attributs >>>\n")
    print("Min value :", root.min_tree(root))
    print("Max value :", root.max_tree(root))
    print("Height :", root.height(root))
    print("Number of nodes :",root.number_of_nodes())

    print()

    print("Search and delete >>>\n")
    print("Search value 42 :", root.search_tree(root, 42))
    print("Search value 22 :", root.search_tree(root, 22))

    print("Remove value 14:")
    remv = root.remove_tree(root, 14)
    root = remv[0]
    print(remv[1])
    # Check
    print("New tree:", root.inorder_traversal(root, False))

    
