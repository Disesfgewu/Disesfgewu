class Hnode:
    def __init__(self, key, item):
        self.key = key
        self.item = item
        self.parent = None
        self.right = None
        self.left = None

    def getKey(self):
        return self.key

    def getItem(self):
        return self.item

    def getRightChild(self):
        return self.right

    def getLeftChild(self):
        return self.left

    def getParent(self):
        return self.parent

    def hasRightChild(self):
        return (self.right != None)

    def hasLeftChild(self):
        return (self.left != None)

    def isRoot(self):
        return (self.parent == None)

    def isLeaf(self):
        return ((self.right == None) and (self.left == None))

    def isRightChild(self):
        return (self.parent.right == self)

    def isLeftChild(self):
        return (self.parent.left == self)

    def setParent(self, p):
        self.parent = p

    def setKey(self, key):
        self.key = key

    def setItem(self, item):
        self.item = item

    def addRightChild(self, hnode):
        self.right = hnode
        hnode.setParent(self)

    def addLeftChild(self, hnode):
        self.left = hnode
        hnode.setParent(self)

# Heap class


class Heap:
    def __init__(self):
        self.root = None
        self.last = None
        self.size = 0

    def isEmpty(self):
        return (self.size == 0)

    def getSize(self):
        return self.size

    def getRoot(self):
        return self.root

    def getLast(self):
        return self.last

    def getHighestPriority(self):
        return self.root.getKey()

    def setRoot(self, hnode):
        self.root = hnode

    def setLast(self, hnode):
        self.last = hnode
        #
    # downward adjustment from current node
    #

    def downwardHeapify(self, current):
        while 1:
            if current.left == None and current.right == None:
                break
            elif (current.left != None and current.left.key > current.key) and (current.right != None and current.right.key > current.key):
                break
            elif (current.left != None and current.left.key > current.key) and current.right == None:
                break
            elif (current.right != None and current.right.key > current.key) and current.left == None:
                break
            if current.left != None and current.right != None:
                if current.left.key < current.right.key:
                    current.left.key, current.key = current.key, current.left.key
                    current.left.item, current.item = current.item, current.left.item
                else:
                    current.right.key, current.key = current.key, current.right.key
                    current.right.item, current.item = current.item, current.right.item
            elif current.left != None:
                current.left.key, current.key = current.key, current.left.key
                current.left.item, current.item = current.item, current.left.item
            else:
                current.right.key, current.key = current.key, current.right.key
                current.right.item, current.item = current.item, current.right.item

    #
    # upward adjustment toward the root from the current node
    #
    def upwardHeapify(self, current):
        if self.size == 1:
            return
        while current.parent != None and current.parent.key > current.key:
            current.parent.key, current.key = current.key, current.parent.key
            current.parent.item, current.item = current.item, current.parent.item
            current = current.parent
    #
    # The most important operation for a heap, remove_Min (extract_Min())
    #

    def removeMin(self):
        if self.size <= 0:
            print("The heap is empty and no entry can be removed")
            return
        if self.size == 1:
            self.left = None
            self.right = None
            self.size = 0
            self.root = None
            print("The heap is now empty")
            return
        self.last.key, self.root.key = self.root.key, self.last.key
        self.last.item, self.root.item = self.root.item, self.last.item
        self.size -= 1
        if self.last.parent.left == self.last:
            self.last.parent.left = None
            queue = [self.root]
            size = 0
            while 1:
                size += len(queue)
                if size == self.size:
                    break
                new = []
                for i in queue:
                    if i.left != None:
                        new.append(i.left)
                    if i.right != None:
                        new.append(i.right)
                queue = new
            self.last = queue[-1]
        else:
            self.last.parent.right = None
            self.last = self.last.parent.left
        self.downwardHeapify(self.root)

    #
    # Another important operation for a heap, insertion() (add())
    #

    def Insert(self, hnode):
        self.size += 1
        if self.root == None:
            self.root = hnode
            self.last = hnode
        else:
            current = self.root
            arr = [current]
            pos = None
            while 1:
                tmp = []
                for i in arr:
                    if i.left == None:
                        pos = i
                        break
                    else:
                        tmp.append(i.left)
                    if i.right == None:
                        pos = i
                        break
                    else:
                        tmp.append(i.right)
                if pos != None:
                    break
                arr = tmp
            if pos.left == None:
                pos.left = hnode
            else:
                pos.right = hnode
            hnode.parent = pos
            self.last = hnode
            self.upwardHeapify(self.last)
    #
    # For management, print the heap in pre-order
    #

    def printHeapPreOrder(self, i):
        def DFS(i):
            if i.left == None and i.right == None:
                print(f"Leaf [ {i.key} {i.item} ]")
                return
            print(f"Node [ {i.key} {i.item} ]")
            if i.left != None:
                DFS(i.left)
            if i.right != None:
                DFS(i.right)
        DFS(i)
