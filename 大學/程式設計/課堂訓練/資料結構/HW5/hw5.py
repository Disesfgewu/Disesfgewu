from hw5_constructure import Hnode, Heap

# k = Heap()


def HeapwithEntriesInserted():
    #
    # read the input information from the default input text file into an
    # entry list, entry_list
    #

    #
    # initiating a heap object h
    #
    h = Heap()

    #
    # Do something here to build the heap
    #
    f = open("inFile.txt", "r+", encoding="utf-8")
    get = list(map(lambda x: x.split(), f.read().split("\n")))
    for i in get:
        h.Insert(Hnode(int(i[0]), i[1]))

    # ---------------------Print as the example on the homework sheet --------
    #                       will be adapted with the input
    #
    print("Heap size=", h.getSize(),
          "The highest priority is ", h.getHighestPriority())
    print("pre-order traversal:")
    h.printHeapPreOrder(h.getRoot())

    print("deleteMin")
    h.removeMin()

    print("deleteMin")
    h.removeMin()

    print("deleteMin")
    h.removeMin()

    print("deleteMin")
    h.removeMin()

    print("deleteMin")
    h.removeMin()

    print("insert 35, resume")
    h.Insert(Hnode(35, "resume"))

    print("insert 15, second")
    h.Insert(Hnode(15, "second"))

    print("insert 20, fourth")
    h.Insert(Hnode(20, "fourth"))

    print("Heap size=", h.getSize(),
          "The highest priority is ", h.getHighestPriority())
    print("pre-order traversal:")
    h.printHeapPreOrder(h.getRoot())

    print("deleteMin")
    h.removeMin()

    print("insert 40, nineth")
    h.Insert(Hnode(40, "nineth"))


HeapwithEntriesInserted()
