#ifndef AVLNode_HPP
#define AVLNode_HPP
#include "book.hpp"

class AVLNode {
private:
  AVLNode *m_left;

  AVLNode *m_right;

  int height;

  Book *m_book;

  int key;

public:
  /**
   * @post Constructor for AVLNode class, Sets m_right and m_left to nullptr
   */
  AVLNode(Book *b);

  /**
   * @return The T value of the AVLNode.
   */
  int getKey();

  /**
   * @return A pointer to the left AVLNode.
   */
  AVLNode *getLeft();

  /**
   * @return A pointer to the right AVLNode.
   */
  AVLNode *getRight();

  /**
   * @post Sets m_left
   */
  void setLeft(AVLNode *left);

  /**
   * @post Sets m_right
   */
  void setRight(AVLNode *right);

  void setHeight(int h);

  int getHeight();

  Book *getBook();
};

#endif // AVLNode_HPP
