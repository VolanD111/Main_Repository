class Tree:
    def __init__(self, data):
        self.left = None
        self.right = None
        self.data = data
        self.check = True
    def PrintTree(self, level=0, prefix="Root: "):
        #  Вывод дерева с отступами
        print(" " * (level * 4) + prefix + str(self.data))
        if self.left:
            self.left.PrintTree(level + 1, "L--- ")
        if self.right:
            self.right.PrintTree(level + 1, "R--- ")
    def add_value(self, newValue):
        if self.data > newValue:
            if self.left is None:
                self.left = Tree(newValue)
            elif self.right is None:
                self.right = Tree(newValue)
            else:
                if self.check:
                    self.left.add_value(newValue)
                    self.check = False
                else:
                    self.right.add_value(newValue)
                    self.check = True

test = Tree(25)
test.add_value(20)
test.add_value(23)
test.add_value(18)
test.add_value(16)
test.add_value(13)
test.add_value(12)
#test.add_value(11)
print(test.PrintTree())