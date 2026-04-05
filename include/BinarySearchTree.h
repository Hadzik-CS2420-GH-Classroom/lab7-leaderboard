#pragma once

// =============================================================================
// BinarySearchTree.h — Lab 7: Leaderboard
// =============================================================================
//
// A Binary Search Tree (BST) that stores int scores for an arcade leaderboard.
//
// BST property: for every node N,
//   - all values in N's left subtree are < N->data
//   - all values in N's right subtree are > N->data
//
// This lab extends the Code-Together interface with three additional methods:
//   size(), is_balanced(), and clear().
//
// Do NOT modify this file.
// =============================================================================

class BinarySearchTree {
public:
    // -------------------------------------------------------------------------
    // Nested Node struct — each node holds a data value and two child pointers
    // -------------------------------------------------------------------------
    struct Node {
        int   data;
        Node* left;
        Node* right;

        explicit Node(int value) : data(value), left(nullptr), right(nullptr) {}
    };

    // -------------------------------------------------------------------------
    // Constructor & Destructor
    // -------------------------------------------------------------------------
    BinarySearchTree();
    ~BinarySearchTree();

    // Rule of 5: copy/move disabled (no deep-copy needed for this lab)
    BinarySearchTree(const BinarySearchTree&)            = delete;
    BinarySearchTree& operator=(const BinarySearchTree&) = delete;
    BinarySearchTree(BinarySearchTree&&)                 = delete;
    BinarySearchTree& operator=(BinarySearchTree&&)      = delete;

    // -------------------------------------------------------------------------
    // Core Mutators
    // -------------------------------------------------------------------------
    void insert(int value);   // Insert value (ignore duplicates)
    bool remove(int value);   // Remove value; returns true if found, false otherwise
    void clear();             // Remove all nodes; tree becomes empty

    // -------------------------------------------------------------------------
    // Queries
    // -------------------------------------------------------------------------
    bool search(int value)   const;  // True if value exists in the tree
    bool is_empty()          const;  // True if the tree has no nodes
    int  height()            const;  // Height of tree (-1 if empty, 0 if root only)
    int  size()              const;  // Count of all nodes in the tree
    bool is_balanced()       const;  // True if every node has |balance_factor| <= 1

    // -------------------------------------------------------------------------
    // Traversals — print values separated by spaces, followed by newline
    // -------------------------------------------------------------------------
    void inorder()   const;   // Left → Root → Right  (sorted order)
    void preorder()  const;   // Root → Left → Right
    void postorder() const;   // Left → Right → Root

private:
    Node* root_;

    // -------------------------------------------------------------------------
    // Private recursive helpers
    // -------------------------------------------------------------------------
    Node* insert_(Node* node, int value);
    Node* remove_(Node* node, int value, bool& removed);
    Node* find_min_(Node* node) const;   // Smallest node in a subtree
    bool  search_(Node* node, int value) const;
    int   height_(Node* node) const;
    int   size_(Node* node)   const;
    bool  is_balanced_(Node* node) const;
    void  clear_(Node* node);
    void  inorder_(Node* node)   const;
    void  preorder_(Node* node)  const;
    void  postorder_(Node* node) const;
};
