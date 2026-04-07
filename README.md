# Lab 7: Leaderboard

## Overview

You are building the backend for an arcade leaderboard. High scores are stored in a **Binary Search Tree (BST)** so the system can quickly add new scores, look up whether a score is on the board, remove disqualified entries, and display all scores in ranked order.

A BST stores values so that every node obeys the BST property: all values in a node's left subtree are smaller than the node's value, and all values in its right subtree are larger. This property gives O(log n) average-case performance for insert, search, and remove.

Your tree stores `int` scores. You will implement:

- **Structural operations** — insert, remove, and clear
- **Queries** — search, is_empty, height, size, and is_balanced
- **Traversals** — inorder, preorder, and postorder

The three lab-only methods (`size`, `is_balanced`, `clear`) were not in the Code-Togethers — read their TODO hints carefully before you start.

## Learning Objectives

By completing this activity, you will be able to:

- Implement recursive BST operations from a clean interface
- Handle all three remove cases: leaf, one child, and two children
- Compute tree height and size using recursive helpers
- Identify whether a BST is height-balanced
- Perform and distinguish all three depth-first traversals

## Project Structure

```
lab7-leaderboard/
├── CMakeLists.txt
├── assignment.json
├── README.md
├── include/
│   └── BinarySearchTree.h      # Interface — do not modify
├── src/
│   ├── BinarySearchTree.cpp    # Your work goes here (TODOs 1–24)
│   └── main.cpp                # Manual verification driver
└── tests/
    └── lab7_test.cpp           # Automated Google Test suite
```

## What You'll Do

All of your work goes in **`src/BinarySearchTree.cpp`**. The header, main.cpp, and tests are provided — do not modify them. Open the `.cpp` file and work through each TODO in order. Follow the recommended teaching order below: constructor first, then insert, then search, then traversals, then height/size/is_balanced, and save remove for last.

## Files

| File | TODOs | Notes |
|------|-------|-------|
| `src/BinarySearchTree.cpp` | 24 | All student work lives here |
| `include/BinarySearchTree.h` | 0 | Read-only interface |
| `src/main.cpp` | 0 | Run to verify output manually |
| `tests/lab7_test.cpp` | 0 | Automated tests — do not modify |

## Grading (130 points)

| Method | Points | What is tested |
|--------|--------|----------------|
| Constructor / Destructor | 10 | Tree starts empty; no memory leaks on delete |
| `insert` | 15 | Single node, multiple nodes, duplicates ignored |
| `search` | 10 | Finds root, leaf, and interior nodes; returns false when missing |
| `is_empty` | 5 | True on empty tree, false after insert |
| `inorder` | 10 | Correct sorted output for 7-node and single-node trees |
| `preorder` | 5 | Correct root-first output |
| `postorder` | 5 | Correct root-last output |
| `height` | 10 | -1 empty, 0 single node, 2 for 7-node balanced tree, 4 for degenerate |
| `size` | 10 | 0 empty, 1 single node, 7 for 7-node tree, unchanged by duplicates |
| `is_balanced` | 10 | True for balanced tree, false for sorted-insertion chain |
| `clear` | 10 | Resets tree; allows reinsertion; no memory leaks |
| `remove` — leaf | 10 | Leaf node removed, size decrements, inorder correct |
| `remove` — one child | 10 | Surviving child promoted correctly |
| `remove` — two children | 10 | In-order successor used; BST property preserved |
| **Total** | **130** | |
