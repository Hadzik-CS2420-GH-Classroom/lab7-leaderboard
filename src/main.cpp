#include "BinarySearchTree.h"

#include <iostream>

// =============================================================================
// Lab 7: Leaderboard — Manual Verification Driver
// =============================================================================
//
// Use this file to manually test your implementation. Run it after each
// TODO group and compare your output to the expected output shown in the
// comments below.
//
// Expected output (once all TODOs are complete):
//
// Note: each traversal prints values separated by spaces, with a trailing
// space before the newline — e.g., "6800 7200 7800 \n". This is fine and
// matches the automated tests.
//
//   === Lab 7: Leaderboard ===
//
//   --- Post 7 high scores ---
//   Posting scores: 8500 7200 9300 6800 7800 8800 9600
//
//   --- Leaderboard (traversals) ---
//   Ranked (inorder):   6800 7200 7800 8500 8800 9300 9600
//   Tree order (pre):   8500 7200 6800 7800 9300 8800 9600
//   Cleanup order (post): 6800 7800 7200 8800 9600 9300 8500
//
//   --- Leaderboard stats ---
//   height:      2
//   size:        7
//   is_empty:    false
//   is_balanced: true
//
//   --- Score lookup ---
//   search(7800): on the board
//   search(5000): not found
//
//   --- Remove scores ---
//   remove(6800) [leaf]:
//     ranked: 7200 7800 8500 8800 9300 9600
//   remove(7200) [one child - 7800 promoted]:
//     ranked: 7800 8500 8800 9300 9600
//   remove(9300) [two children - successor 9600 takes over]:
//     ranked: 7800 8500 8800 9600
//
//   --- Degenerate leaderboard (sorted insertion) ---
//   is_balanced (should be false): false
//
//   --- Season reset ---
//   After clear: is_empty = true, size = 0, height = -1
//
//   === Lab 7 Complete ===
//
// =============================================================================

int main()
{
    std::cout << "=== Lab 7: Leaderboard ===\n\n";

    // -------------------------------------------------------------------------
    // Build a balanced 7-score leaderboard
    //
    //          8500
    //        /      \
    //     7200      9300
    //    /    \    /    \
    //  6800  7800 8800  9600
    // -------------------------------------------------------------------------
    BinarySearchTree board;

    std::cout << "--- Post 7 high scores ---\n";
    std::cout << "Posting scores: 8500 7200 9300 6800 7800 8800 9600\n";
    board.insert(8500);
    board.insert(7200);
    board.insert(9300);
    board.insert(6800);
    board.insert(7800);
    board.insert(8800);
    board.insert(9600);

    // -------------------------------------------------------------------------
    // Traversals
    // -------------------------------------------------------------------------
    std::cout << "\n--- Leaderboard (traversals) ---\n";
    std::cout << "Ranked (inorder):   ";     board.inorder();
    std::cout << "Tree order (pre):   ";     board.preorder();
    std::cout << "Cleanup order (post): ";   board.postorder();

    // -------------------------------------------------------------------------
    // Leaderboard stats
    // -------------------------------------------------------------------------
    std::cout << "\n--- Leaderboard stats ---\n";
    std::cout << "height:      " << board.height()   << "\n";
    std::cout << "size:        " << board.size()      << "\n";
    std::cout << "is_empty:    " << (board.is_empty()    ? "true" : "false") << "\n";
    std::cout << "is_balanced: " << (board.is_balanced() ? "true" : "false") << "\n";

    // -------------------------------------------------------------------------
    // Score lookup
    // -------------------------------------------------------------------------
    std::cout << "\n--- Score lookup ---\n";
    std::cout << "search(7800): " << (board.search(7800) ? "on the board" : "not found") << "\n";
    std::cout << "search(5000): " << (board.search(5000) ? "on the board" : "not found") << "\n";

    // -------------------------------------------------------------------------
    // Remove — three cases
    // -------------------------------------------------------------------------
    std::cout << "\n--- Remove scores ---\n";

    board.remove(6800);  // leaf node
    std::cout << "remove(6800) [leaf]:\n  ranked: ";
    board.inorder();

    board.remove(7200);  // one child (only right child 7800)
    std::cout << "remove(7200) [one child - 7800 promoted]:\n  ranked: ";
    board.inorder();

    board.remove(9300);  // two children (successor is 9600)
    std::cout << "remove(9300) [two children - successor 9600 takes over]:\n  ranked: ";
    board.inorder();

    // -------------------------------------------------------------------------
    // Degenerate leaderboard — scores posted in ascending order
    // -------------------------------------------------------------------------
    std::cout << "\n--- Degenerate leaderboard (sorted insertion) ---\n";
    BinarySearchTree degen;
    degen.insert(1000);
    degen.insert(2000);
    degen.insert(3000);
    degen.insert(4000);
    degen.insert(5000);
    std::cout << "is_balanced (should be false): "
              << (degen.is_balanced() ? "true" : "false") << "\n";

    // -------------------------------------------------------------------------
    // Season reset
    // -------------------------------------------------------------------------
    std::cout << "\n--- Season reset ---\n";
    board.clear();
    std::cout << "After clear: is_empty = " << (board.is_empty() ? "true" : "false")
              << ", size = " << board.size()
              << ", height = " << board.height() << "\n";

    std::cout << "\n=== Lab 7 Complete ===\n";
    return 0;
}
