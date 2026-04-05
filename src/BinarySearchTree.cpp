#include "BinarySearchTree.h"

#include <iostream>
#include <algorithm>   // std::max, std::abs

// =============================================================================
// Lab 7: Leaderboard — BinarySearchTree Implementation
// =============================================================================

// =============================================================================
// Constructor & Destructor
// =============================================================================

// ---------------------------------------------------------------------------
// BinarySearchTree (constructor)
// ---------------------------------------------------------------------------
//
// TODO 1: Initialize root_ to nullptr so the tree starts empty.
//
BinarySearchTree::BinarySearchTree()
{
    // Your code here
}

// ---------------------------------------------------------------------------
// ~BinarySearchTree (destructor)
// ---------------------------------------------------------------------------
//
// TODO 2: Free all heap-allocated nodes to prevent memory leaks.
//
// Hint: call clear() — it already does the recursive cleanup.
//
BinarySearchTree::~BinarySearchTree()
{
    // Your code here
}

// =============================================================================
// Core Mutators
// =============================================================================

// ---------------------------------------------------------------------------
// insert
// ---------------------------------------------------------------------------
//
// TODO 3: Insert value into the BST. Ignore duplicates (do nothing if the
// value is already present).
//
// Hint: delegate to insert_(root_, value) and assign the return value back
// to root_. The recursive helper does the real work.
//
void BinarySearchTree::insert(int value)
{
    // Your code here
}

// ---------------------------------------------------------------------------
// insert_ (private recursive helper)
// ---------------------------------------------------------------------------
//
// TODO 4: Recursively find the correct position for value and insert a new
// Node there.
//
// - Base case: node == nullptr → allocate and return a new Node(value)
// - If value < node->data → recurse left, assign result to node->left
// - If value > node->data → recurse right, assign result to node->right
// - If value == node->data → duplicate; do nothing
// - Always return node at the end so parent links stay intact
//
BinarySearchTree::Node* BinarySearchTree::insert_(Node* node, int value)
{
    // Your code here

    return node; // placeholder — replace this with your implementation
}

// ---------------------------------------------------------------------------
// remove
// ---------------------------------------------------------------------------
//
// TODO 5: Remove value from the BST. Return true if the value was found and
// removed, false otherwise.
//
// Hint: create a local bool removed = false, then delegate to
// remove_(root_, value, removed) and assign the return value back to root_.
// Return removed.
//
bool BinarySearchTree::remove(int value)
{
    // Your code here

    return false; // placeholder
}

// ---------------------------------------------------------------------------
// remove_ (private recursive helper)
// ---------------------------------------------------------------------------
//
// TODO 6: Recursively find and remove the node holding value.
//
// When value is not found (node == nullptr), return nullptr without changing
// removed.
//
// When value matches node->data, set removed = true, then handle THREE cases:
//
// Case 1 — No children (leaf):
//   Delete the node and return nullptr.
//
// Case 2 — One child:
//   Save the non-null child, delete the node, return the saved child.
//
// Case 3 — Two children:
//   Find the in-order successor (smallest node in the RIGHT subtree)
//   using find_min_. Copy its data into the current node. Then recurse
//   into the right subtree to remove that successor node (pass a dummy
//   bool for removed since we already set it).
//
// Always return node at the end so parent links stay intact.
//
BinarySearchTree::Node* BinarySearchTree::remove_(Node* node, int value,
                                                   bool& removed)
{
    // Your code here

    return node; // placeholder — replace this with your implementation
}

// ---------------------------------------------------------------------------
// find_min_ (private helper)
// ---------------------------------------------------------------------------
//
// TODO 7: Return a pointer to the node with the smallest value in the
// subtree rooted at node.
//
// Hint: walk left until left == nullptr; that node is the minimum.
// Assume node != nullptr when this is called.
//
BinarySearchTree::Node* BinarySearchTree::find_min_(Node* node) const
{
    // Your code here

    return node; // placeholder — replace this with your implementation
}

// ---------------------------------------------------------------------------
// clear
// ---------------------------------------------------------------------------
//
// TODO 8: Remove all nodes from the tree, resetting it to empty.
//
// Hint: call clear_(root_) to delete all nodes recursively, then set
// root_ back to nullptr.
//
void BinarySearchTree::clear()
{
    // Your code here
}

// ---------------------------------------------------------------------------
// clear_ (private recursive helper)
// ---------------------------------------------------------------------------
//
// TODO 9: Post-order deletion — delete left subtree, delete right subtree,
// then delete node itself.
//
// Post-order is important here: delete children before the parent so you
// don't lose the child pointers.
//
void BinarySearchTree::clear_(Node* node)
{
    // Your code here
}

// =============================================================================
// Queries
// =============================================================================

// ---------------------------------------------------------------------------
// search
// ---------------------------------------------------------------------------
//
// TODO 10: Return true if value exists in the tree, false otherwise.
//
// Hint: delegate to search_(root_, value).
//
bool BinarySearchTree::search(int value) const
{
    // Your code here

    return false; // placeholder
}

// ---------------------------------------------------------------------------
// search_ (private recursive helper)
// ---------------------------------------------------------------------------
//
// TODO 11: Recursively search for value using the BST property.
//
// - Base case: node == nullptr → value not found, return false
// - If value == node->data → found, return true
// - If value < node->data  → recurse left
// - If value > node->data  → recurse right
//
bool BinarySearchTree::search_(Node* node, int value) const
{
    // Your code here

    return false; // placeholder
}

// ---------------------------------------------------------------------------
// is_empty
// ---------------------------------------------------------------------------
//
// TODO 12: Return true if the tree has no nodes (root_ is nullptr).
//
bool BinarySearchTree::is_empty() const
{
    // Your code here

    return true; // placeholder
}

// ---------------------------------------------------------------------------
// height
// ---------------------------------------------------------------------------
//
// TODO 13: Return the height of the tree.
//
// Height is defined as the number of edges on the longest root-to-leaf path:
//   - Empty tree  → -1
//   - Root only   →  0
//   - Root + one child →  1
//
// Hint: delegate to height_(root_).
//
int BinarySearchTree::height() const
{
    // Your code here

    return -1; // placeholder
}

// ---------------------------------------------------------------------------
// height_ (private recursive helper)
// ---------------------------------------------------------------------------
//
// TODO 14: Recursively compute the height of the subtree rooted at node.
//
// - Base case: node == nullptr → return -1
// - Otherwise: return 1 + max(height_(left), height_(right))
//
int BinarySearchTree::height_(Node* node) const
{
    // Your code here

    return -1; // placeholder
}

// ---------------------------------------------------------------------------
// size
// ---------------------------------------------------------------------------
//
// TODO 15: Return the total number of nodes in the tree.
//
// Hint: delegate to size_(root_).
//
int BinarySearchTree::size() const
{
    // Your code here

    return 0; // placeholder
}

// ---------------------------------------------------------------------------
// size_ (private recursive helper)
// ---------------------------------------------------------------------------
//
// TODO 16: Recursively count all nodes in the subtree rooted at node.
//
// - Base case: node == nullptr → return 0
// - Otherwise: return 1 + size_(left) + size_(right)
//
int BinarySearchTree::size_(Node* node) const
{
    // Your code here

    return 0; // placeholder
}

// ---------------------------------------------------------------------------
// is_balanced
// ---------------------------------------------------------------------------
//
// TODO 17: Return true if every node in the tree has a balance factor
// with absolute value <= 1.
//
// Balance factor for a node = height(left subtree) - height(right subtree)
//
// Hint: delegate to is_balanced_(root_). An empty tree is balanced.
//
bool BinarySearchTree::is_balanced() const
{
    // Your code here

    return true; // placeholder
}

// ---------------------------------------------------------------------------
// is_balanced_ (private recursive helper)
// ---------------------------------------------------------------------------
//
// TODO 18: Recursively verify balance for the subtree rooted at node.
//
// - Base case: node == nullptr → return true (an empty subtree is balanced)
// - Compute left_h  = height_(node->left)
// - Compute right_h = height_(node->right)
// - If std::abs(left_h - right_h) > 1 → return false (this node is unbalanced)
// - Otherwise, recurse: return is_balanced_(left) && is_balanced_(right)
//
bool BinarySearchTree::is_balanced_(Node* node) const
{
    // Your code here

    return true; // placeholder
}

// =============================================================================
// Traversals
// =============================================================================

// ---------------------------------------------------------------------------
// inorder
// ---------------------------------------------------------------------------
//
// TODO 19: Print all values in sorted (ascending) order.
//
// Hint: call inorder_(root_), then print a newline.
//
void BinarySearchTree::inorder() const
{
    // Your code here
}

// ---------------------------------------------------------------------------
// inorder_ (private recursive helper)
// ---------------------------------------------------------------------------
//
// TODO 20: Left → Root → Right traversal.
//
// Print node->data followed by a space.
//
void BinarySearchTree::inorder_(Node* node) const
{
    // Your code here
}

// ---------------------------------------------------------------------------
// preorder
// ---------------------------------------------------------------------------
//
// TODO 21: Print values in Root → Left → Right order.
//
// Hint: call preorder_(root_), then print a newline.
//
void BinarySearchTree::preorder() const
{
    // Your code here
}

// ---------------------------------------------------------------------------
// preorder_ (private recursive helper)
// ---------------------------------------------------------------------------
//
// TODO 22: Root → Left → Right traversal.
//
// Print node->data followed by a space.
//
void BinarySearchTree::preorder_(Node* node) const
{
    // Your code here
}

// ---------------------------------------------------------------------------
// postorder
// ---------------------------------------------------------------------------
//
// TODO 23: Print values in Left → Right → Root order.
//
// Hint: call postorder_(root_), then print a newline.
//
void BinarySearchTree::postorder() const
{
    // Your code here
}

// ---------------------------------------------------------------------------
// postorder_ (private recursive helper)
// ---------------------------------------------------------------------------
//
// TODO 24: Left → Right → Root traversal.
//
// Print node->data followed by a space.
//
void BinarySearchTree::postorder_(Node* node) const
{
    // Your code here
}
