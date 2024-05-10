# PCSTree
CODE CONTENTS:

1. INSERTION OF NODE
2. REMOVAL OF ANY NODE
3. PRINTING OF TREE NODES

The Parent-Child-Sibling tree has a structure of a tree where each node has pointers to its parent, its first child, and its next sibling. This representation is especially useful for trees with an arbitrary number of children per node.

Characteristics of the PCS Tree Representation:
1. Parent Node: Each node contains a pointer to its parent node. The root node has its parent pointer set to null.
2. Child Node: Each node has a pointer to its first (leftmost) child. If a node has no children, this pointer is null.
3. Sibling Node: Each node has a pointer to its next sibling (i.e., the next child of its parent). If the node is the last child, this pointer is null.


Advantages of Using a PCS Tree:
1. Flexibility in Tree Structure: This representation can easily handle trees where the number of children per node isn’t fixed, which is a limitation of binary trees.
2. Efficient Space Utilization: Compared to a child list representation where you might need an array or list to store all children, the PCS method can be more space-efficient in some cases, as it only uses three pointers per node regardless of the number of children.
3. Traversal Efficiency: Traversing to find siblings or the parent of a node is direct, which can make certain tree operations faster.



DIAGRAM FOR INSERTED TREE IN THE CODE:
![PCSTreeDiagram](https://github.com/saumyaparmar/PCSTree/assets/18940132/650c7e7d-0f88-4fd7-9855-9b3502fdc40e)



