# Array-Based Binary Tree

This repository contains a C++ implementation of an array-based binary tree, providing efficient operations for managing tree nodes and traversing the tree.

## Overview

- **ArrayBinaryTree Class**: Represents the array-based binary tree structure.
  - **Features**:
    - `maxHeight`: Maximum height of the tree.
    - `maxNodes`: Maximum number of nodes in the tree.
    - `data`: Array to store node data.
    - `nodeStatus`: Array to track node presence.
  - **Methods**:
    - `setRoot`: Sets the root node.
    - `setLeftChild`: Sets the left child of a node.
    - `setRightChild`: Sets the right child of a node.
    - Traversal methods: `preOrder`, `postOrder`, `inOrder`.
    - `getRoot`: Returns the root node.
    - `getParent`: Returns the parent node of a given node.
    - `remove`: Removes a node from the tree.
    - `displayAncestors`: Displays ancestors of a given node.
    - `displayDescendents`: Displays descendents of a given node.
    - `heightOfTree`: Returns the height of the tree.
    - `displayLevel`: Displays nodes at a specific level.

## Example Usage

```cpp
int main() {
    // Create a binary tree with max height 4
    ArrayBinaryTree<char> bt(4);
    
    // Set nodes and connections
    bt.setLeftChild('a', 'b');
    bt.setRightChild('a', 'c');
    bt.setLeftChild('b', 'd');
    bt.setRightChild('b', 'e');
    
    // Perform traversals and display node information
    bt.preOrder();
    bt.postOrder();
    bt.inOrder();
    bt.displayAncestors('d');
    bt.displayDescendents('b');
    
    return 0;
}
