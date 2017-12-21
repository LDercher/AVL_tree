#ifndef AVL_HPP
#define AVL_HPP
#include "AVLNode.hpp"
#include "book.hpp"
#include <algorithm>
#include <string>
/**
 * AVL tree is a self balanced binary search tree
 */
class AVL {

private:
  // Member fields
  // IMPLEMENT ME
  AVLNode *m_root;
  // Member functions
  // IMPLEMENT ME

  void LOThelper(AVLNode *ST, int level, void (*op)(Book *b));

  AVLNode *addHelper(AVLNode *ST, AVLNode *newNode, Book *b);

  void deleteTree(AVLNode *ST);

  int checkBalance(AVLNode *ST);

  void printInOrder();

  void printHelper(AVLNode *ST);

  void pptree(AVLNode *tt);

  Book *searchHelper(int id, AVLNode *ST);

  int getAVLNodeHeight(AVLNode *ST);

  AVLNode *leftRotate(AVLNode *a);

  AVLNode *rightRotate(AVLNode *a);

public:
  // Member functions
  /**
   * Constructor to construct the binary search tree.
   */
  AVL();

  /**
   * Destructor to destroy the binary search tree
   * Make sure you destroy everything that you allocate on heap.
   */
  ~AVL();

  /**
   * Returns true if the AVL tree is empty or returns false
   */
  bool isEmpty();

  /**
   * add a book instance to the AVL Tree and balance it if necessary
   */
  void addBook(Book *);

  /**
   * Searches for the book given its id
   */
  Book *search(int id);

  /**
   * this function performs a levelorder traversal over the existing
   * AVL tree and performs the operation op on each of the Book instance
   * stored in the AVL tree.
   */
  void levelorderTraverse(void (*op)(Book *b));
};

#endif // AVL_HPP defined
