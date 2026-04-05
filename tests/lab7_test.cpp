#include <gtest/gtest.h>
#include "BinarySearchTree.h"

// =============================================================================
// Lab 7 Test Suite — Leaderboard (Binary Search Tree)
// =============================================================================
//
// Tests cover every public method. Work through the TODOs in BinarySearchTree.cpp
// in order; the tests are grouped to match the recommended implementation order.
//
// Run with: cmake --build . && ctest --output-on-failure
// =============================================================================

// =============================================================================
// Note on tree construction
//
// Standard 7-node balanced BST used throughout these tests:
//
//          50
//        /    \
//      30      70
//     /  \    /  \
//   20   40  60   80
//
// Because copy/move are deleted on BinarySearchTree, each test builds its
// own tree inline with:
//   bst.insert(50); bst.insert(30); bst.insert(70);
//   bst.insert(20); bst.insert(40); bst.insert(60); bst.insert(80);
// =============================================================================

// =============================================================================
// TODO 1 + 2: Constructor & Destructor
// =============================================================================

TEST(BSTTest, DefaultConstructorCreatesEmptyTree)
{
    BinarySearchTree bst;
    EXPECT_TRUE(bst.is_empty());
}

TEST(BSTTest, DestructorFreesAllMemory)
{
    // Sanitizers catch any leak. If the destructor is missing, this test will
    // report memory errors in address-sanitizer mode.
    auto* bst = new BinarySearchTree();
    bst->insert(10);
    bst->insert(5);
    bst->insert(15);
    delete bst;
}

// =============================================================================
// TODO 3 + 4: insert
// =============================================================================

TEST(BSTTest, InsertSingleNode)
{
    BinarySearchTree bst;
    bst.insert(42);
    EXPECT_FALSE(bst.is_empty());
    EXPECT_TRUE(bst.search(42));
}

TEST(BSTTest, InsertMultipleNodes)
{
    BinarySearchTree bst;
    bst.insert(50);
    bst.insert(30);
    bst.insert(70);
    EXPECT_TRUE(bst.search(50));
    EXPECT_TRUE(bst.search(30));
    EXPECT_TRUE(bst.search(70));
}

TEST(BSTTest, InsertDuplicateIgnored)
{
    BinarySearchTree bst;
    bst.insert(10);
    bst.insert(10);
    bst.insert(10);
    EXPECT_EQ(bst.size(), 1);
}

// =============================================================================
// TODO 10 + 11: search
// =============================================================================

TEST(BSTTest, SearchEmptyTreeReturnsFalse)
{
    BinarySearchTree bst;
    EXPECT_FALSE(bst.search(1));
}

TEST(BSTTest, SearchFindsRoot)
{
    BinarySearchTree bst;
    bst.insert(50);
    EXPECT_TRUE(bst.search(50));
}

TEST(BSTTest, SearchFindsLeaf)
{
    BinarySearchTree bst;
    bst.insert(50);
    bst.insert(30);
    bst.insert(70);
    bst.insert(20);
    EXPECT_TRUE(bst.search(20));
}

TEST(BSTTest, SearchMissingValueReturnsFalse)
{
    BinarySearchTree bst;
    bst.insert(50);
    bst.insert(30);
    bst.insert(70);
    EXPECT_FALSE(bst.search(99));
}

// =============================================================================
// TODO 13 + 14: height
// =============================================================================

TEST(BSTTest, HeightEmptyTree)
{
    BinarySearchTree bst;
    EXPECT_EQ(bst.height(), -1);
}

TEST(BSTTest, HeightSingleNode)
{
    BinarySearchTree bst;
    bst.insert(10);
    EXPECT_EQ(bst.height(), 0);
}

TEST(BSTTest, HeightBalancedTree)
{
    // 3-level balanced tree: root, two children, four grandchildren
    BinarySearchTree bst;
    bst.insert(50);
    bst.insert(30);
    bst.insert(70);
    bst.insert(20);
    bst.insert(40);
    bst.insert(60);
    bst.insert(80);
    EXPECT_EQ(bst.height(), 2);
}

TEST(BSTTest, HeightDegenerateTree)
{
    // Sorted insertion → right-skewed chain of height 4
    BinarySearchTree bst;
    bst.insert(10);
    bst.insert(20);
    bst.insert(30);
    bst.insert(40);
    bst.insert(50);
    EXPECT_EQ(bst.height(), 4);
}

// =============================================================================
// TODO 15 + 16: size
// =============================================================================

TEST(BSTTest, SizeEmptyTree)
{
    BinarySearchTree bst;
    EXPECT_EQ(bst.size(), 0);
}

TEST(BSTTest, SizeSingleNode)
{
    BinarySearchTree bst;
    bst.insert(42);
    EXPECT_EQ(bst.size(), 1);
}

TEST(BSTTest, SizeSevenNodes)
{
    BinarySearchTree bst;
    bst.insert(50);
    bst.insert(30);
    bst.insert(70);
    bst.insert(20);
    bst.insert(40);
    bst.insert(60);
    bst.insert(80);
    EXPECT_EQ(bst.size(), 7);
}

TEST(BSTTest, SizeAfterDuplicateInsert)
{
    BinarySearchTree bst;
    bst.insert(10);
    bst.insert(20);
    bst.insert(10); // duplicate — should not increase size
    EXPECT_EQ(bst.size(), 2);
}

// =============================================================================
// TODO 17 + 18: is_balanced
// =============================================================================

TEST(BSTTest, IsBalancedEmptyTree)
{
    BinarySearchTree bst;
    EXPECT_TRUE(bst.is_balanced());
}

TEST(BSTTest, IsBalancedSingleNode)
{
    BinarySearchTree bst;
    bst.insert(10);
    EXPECT_TRUE(bst.is_balanced());
}

TEST(BSTTest, IsBalancedSevenNodeTree)
{
    BinarySearchTree bst;
    bst.insert(50);
    bst.insert(30);
    bst.insert(70);
    bst.insert(20);
    bst.insert(40);
    bst.insert(60);
    bst.insert(80);
    EXPECT_TRUE(bst.is_balanced());
}

TEST(BSTTest, IsBalancedDegenerateReturnsFalse)
{
    // 5-node sorted insertion → every node is right-skewed → unbalanced
    BinarySearchTree bst;
    bst.insert(10);
    bst.insert(20);
    bst.insert(30);
    bst.insert(40);
    bst.insert(50);
    EXPECT_FALSE(bst.is_balanced());
}

// =============================================================================
// TODO 19-24: Traversals (inorder / preorder / postorder)
// =============================================================================
//
// We capture stdout to verify the printed output.

#include <sstream>

// Helper to capture output of a void member function that takes no args
template<typename Fn>
static std::string capture(Fn fn)
{
    std::ostringstream oss;
    auto* old = std::cout.rdbuf(oss.rdbuf());
    fn();
    std::cout.rdbuf(old);
    return oss.str();
}

TEST(BSTTest, InorderSorted)
{
    BinarySearchTree bst;
    bst.insert(50);
    bst.insert(30);
    bst.insert(70);
    bst.insert(20);
    bst.insert(40);
    bst.insert(60);
    bst.insert(80);
    std::string out = capture([&]{ bst.inorder(); });
    EXPECT_EQ(out, "20 30 40 50 60 70 80 \n");
}

TEST(BSTTest, PreorderRootFirst)
{
    BinarySearchTree bst;
    bst.insert(50);
    bst.insert(30);
    bst.insert(70);
    bst.insert(20);
    bst.insert(40);
    bst.insert(60);
    bst.insert(80);
    std::string out = capture([&]{ bst.preorder(); });
    EXPECT_EQ(out, "50 30 20 40 70 60 80 \n");
}

TEST(BSTTest, PostorderRootLast)
{
    BinarySearchTree bst;
    bst.insert(50);
    bst.insert(30);
    bst.insert(70);
    bst.insert(20);
    bst.insert(40);
    bst.insert(60);
    bst.insert(80);
    std::string out = capture([&]{ bst.postorder(); });
    EXPECT_EQ(out, "20 40 30 60 80 70 50 \n");
}

TEST(BSTTest, TraversalsEmptyTree)
{
    BinarySearchTree bst;
    EXPECT_EQ(capture([&]{ bst.inorder(); }),   "\n");
    EXPECT_EQ(capture([&]{ bst.preorder(); }),  "\n");
    EXPECT_EQ(capture([&]{ bst.postorder(); }), "\n");
}

TEST(BSTTest, TraversalSingleNode)
{
    BinarySearchTree bst;
    bst.insert(42);
    EXPECT_EQ(capture([&]{ bst.inorder(); }),   "42 \n");
    EXPECT_EQ(capture([&]{ bst.preorder(); }),  "42 \n");
    EXPECT_EQ(capture([&]{ bst.postorder(); }), "42 \n");
}

// =============================================================================
// TODO 5 + 6: remove
// =============================================================================

TEST(BSTTest, RemoveFromEmptyTreeIsNoOp)
{
    BinarySearchTree bst;
    EXPECT_FALSE(bst.remove(99));  // not found → returns false
    EXPECT_TRUE(bst.is_empty());
}

TEST(BSTTest, RemoveLeafNode)
{
    BinarySearchTree bst;
    bst.insert(50);
    bst.insert(30);
    bst.insert(70);
    EXPECT_TRUE(bst.remove(30));  // leaf — returns true
    EXPECT_FALSE(bst.search(30));
    EXPECT_EQ(bst.size(), 2);
    EXPECT_EQ(capture([&]{ bst.inorder(); }), "50 70 \n");
}

TEST(BSTTest, RemoveNodeWithOneChild)
{
    // 50 -> 30 -> 20 (right child only at 30 is removed; 20 survives as left)
    BinarySearchTree bst;
    bst.insert(50);
    bst.insert(30);
    bst.insert(20);
    EXPECT_TRUE(bst.remove(30));  // one child (left = 20) — returns true
    EXPECT_FALSE(bst.search(30));
    EXPECT_TRUE(bst.search(20));
    EXPECT_EQ(bst.size(), 2);
    EXPECT_EQ(capture([&]{ bst.inorder(); }), "20 50 \n");
}

TEST(BSTTest, RemoveNodeWithTwoChildren)
{
    BinarySearchTree bst;
    bst.insert(50);
    bst.insert(30);
    bst.insert(70);
    bst.insert(20);
    bst.insert(40);
    bst.insert(60);
    bst.insert(80);
    EXPECT_TRUE(bst.remove(70));  // two children; successor is 80
    EXPECT_FALSE(bst.search(70));
    EXPECT_TRUE(bst.search(80));
    EXPECT_EQ(bst.size(), 6);
    EXPECT_EQ(capture([&]{ bst.inorder(); }), "20 30 40 50 60 80 \n");
}

TEST(BSTTest, RemoveRoot)
{
    BinarySearchTree bst;
    bst.insert(50);
    bst.insert(30);
    bst.insert(70);
    EXPECT_TRUE(bst.remove(50));  // root has two children; successor is 70
    EXPECT_FALSE(bst.search(50));
    EXPECT_EQ(bst.size(), 2);
    // inorder should still be sorted
    EXPECT_EQ(capture([&]{ bst.inorder(); }), "30 70 \n");
}

TEST(BSTTest, RemoveNotFoundIsNoOp)
{
    BinarySearchTree bst;
    bst.insert(50);
    bst.insert(30);
    EXPECT_FALSE(bst.remove(99));  // not in tree → returns false
    EXPECT_EQ(bst.size(), 2);
}

TEST(BSTTest, RemoveOnlyNodeLeavesEmptyTree)
{
    BinarySearchTree bst;
    bst.insert(42);
    EXPECT_TRUE(bst.remove(42));
    EXPECT_TRUE(bst.is_empty());
    EXPECT_EQ(bst.size(), 0);
    EXPECT_EQ(bst.height(), -1);
}

TEST(BSTTest, MultipleRemovesInSequence)
{
    BinarySearchTree bst;
    for (int v : {50, 30, 70, 20, 40, 60, 80}) bst.insert(v);
    bst.remove(20);
    bst.remove(80);
    bst.remove(50);
    EXPECT_EQ(bst.size(), 4);
    EXPECT_EQ(capture([&]{ bst.inorder(); }), "30 40 60 70 \n");
}

// =============================================================================
// TODO 8 + 9: clear
// =============================================================================

TEST(BSTTest, ClearEmptyTreeIsNoOp)
{
    BinarySearchTree bst;
    bst.clear();
    EXPECT_TRUE(bst.is_empty());
    EXPECT_EQ(bst.size(), 0);
    EXPECT_EQ(bst.height(), -1);
}

TEST(BSTTest, ClearResetsTree)
{
    BinarySearchTree bst;
    bst.insert(50);
    bst.insert(30);
    bst.insert(70);
    bst.clear();
    EXPECT_TRUE(bst.is_empty());
    EXPECT_EQ(bst.size(), 0);
    EXPECT_EQ(bst.height(), -1);
}

TEST(BSTTest, ClearAllowsReinsertion)
{
    BinarySearchTree bst;
    bst.insert(50);
    bst.insert(30);
    bst.clear();
    bst.insert(10);
    EXPECT_TRUE(bst.search(10));
    EXPECT_FALSE(bst.search(50));
    EXPECT_EQ(bst.size(), 1);
}
