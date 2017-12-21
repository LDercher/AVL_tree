#include "avl.hpp"
#include "util.hpp"
#include <cassert>

AVL::AVL() { this->m_root = NULL; }

AVL::~AVL() { deleteTree(this->m_root); }

void AVL::deleteTree(AVLNode *ST) {

  if (ST->getLeft() != nullptr) {
    deleteTree(ST->getLeft());
  }
  if (ST->getRight() != nullptr) {
    deleteTree(ST->getRight());
  }
  delete ST;
}

bool AVL::isEmpty() {
  if (this->m_root == NULL) {
    return true;
  } else {
    return false;
  }
}

void AVL::pptree(AVLNode *t) {
  if (t == nullptr) {
    std::cout << "NULL" << std::endl;
  } else {
    pptree(t->getLeft());
    std::cout << t << std::endl;
    pptree(t->getRight());
  }
}

void AVL::printInOrder() { printHelper(this->m_root); }

void AVL::printHelper(AVLNode *ST) {
  if (ST != NULL) {
    printHelper(ST->getLeft());

    std::cout << ST->getKey() << " ";

    printHelper(ST->getRight());

    std::cout << std::endl;
  }
}

void AVL::addBook(Book *book) {

  // check if there is already a copy of this book in the library

  Book *temp = search(book->getId());

  if (temp != NULL) {
    std::cout << "Found book, trying to add..." << std::endl;
    if (temp->getCurrentCount() != temp->getTotalCount()) {
      std::cout << "successfully added copy of: " << temp->getName()
                << " to library " << std::endl;
      temp->setCurrentCount(temp->getCurrentCount() + 1);
      return;
    } else {
      std::cout << "The  library is currently full of that book";
      return;
    }
  }

  AVLNode *tnode = new AVLNode(book);
  this->m_root = addHelper(this->m_root, tnode, book);

  std::cout << "successfully added book titled: " << tnode->getBook()->getName()
            << " to library " << std::endl;

}

int AVL::getAVLNodeHeight(AVLNode *ST) {
  if (ST == NULL)
    return 0;
  else
    return ST->getHeight();
}

AVLNode *AVL::addHelper(AVLNode *ST, AVLNode *newNode, Book *b) {

  if (ST == NULL) {

    return newNode;
  } else if (b->getId() < ST->getKey()) {

    AVLNode *tt = addHelper(ST->getLeft(), newNode, b);
    ST->setLeft(tt);
  } else if (b->getId() > ST->getKey()) {

    AVLNode *tt = addHelper(ST->getRight(), newNode, b);
    ST->setRight(tt);
  } else {
    assert(0);
    return NULL;
  }

  ST->setHeight(1 + std::max(getAVLNodeHeight(ST->getLeft()),
                             getAVLNodeHeight(ST->getRight())));

  int bal = getAVLNodeHeight(ST->getLeft()) - getAVLNodeHeight(ST->getRight());

  // check for all 4 cases of imbalance

  // Left Left Case
  if (bal > 1 && b->getId() < ST->getLeft()->getKey()) {
    return rightRotate(ST);
  }
  // Right Right Case
  if (bal < -1 && b->getId() > ST->getRight()->getKey()) {
    return leftRotate(ST);
  }

  // Left Right Case
  if (bal > 1 && b->getId() > ST->getLeft()->getKey()) {
    ST->setLeft(leftRotate(ST->getLeft()));
    return rightRotate(ST);
  }

  // Right Left Case
  if (bal < -1 && b->getId() < ST->getRight()->getKey()) {
    ST->setRight(rightRotate(ST->getRight()));
    return leftRotate(ST);
  }

  return ST;
}

AVLNode *AVL::leftRotate(AVLNode *a) {
  AVLNode *T1 = a->getRight();

  AVLNode *T2 = T1->getLeft();

  T1->setLeft(a);

  a->setRight(T2);

  a->setHeight(std::max(getAVLNodeHeight(a->getLeft()),
                        getAVLNodeHeight(a->getRight())) +
               1);

  T1->setHeight(std::max(getAVLNodeHeight(T1->getLeft()),
                         getAVLNodeHeight(T1->getRight())) +
                1);

  return T1;
}

AVLNode *AVL::rightRotate(AVLNode *a) {
  AVLNode *T1 = a->getLeft();

  AVLNode *T2 = T1->getRight();

  T1->setRight(a);

  a->setLeft(T2);

  a->setHeight(std::max(getAVLNodeHeight(a->getLeft()),
                        getAVLNodeHeight(a->getRight())) +
               1);

  T1->setHeight(std::max(getAVLNodeHeight(T1->getLeft()),
                         getAVLNodeHeight(T1->getRight())) +
                1);
  return T1;
}

int AVL::checkBalance(AVLNode *ST) {
  if (ST == NULL) {
    return 0;
  } else {
    printInOrder();
    return getAVLNodeHeight(ST->getLeft()) - getAVLNodeHeight(ST->getRight());
  }
}

Book *AVL::search(int id) { return searchHelper(id, this->m_root); }

Book *AVL::searchHelper(int id, AVLNode *ST) {
  if (ST != nullptr) {
    if (id == ST->getKey()) {
      std::cout << "Found book..." << std::endl;
      return ST->getBook();
    } else if (id < ST->getKey()) {

      return searchHelper(id, ST->getLeft());
    } else {

      return searchHelper(id, ST->getRight());
    }
  } else {
    std::cout << "Book does not exist..." << std::endl;
    return NULL;
  }
}

void AVL::levelorderTraverse(void (*op)(Book *b)) {

  for (int i = 1; i <= this->m_root->getHeight(); i++) {
    LOThelper(this->m_root, i, op);
  }
}

void AVL::LOThelper(AVLNode *ST, int level, void (*op)(Book *b)) {
  if (ST == nullptr) {
    return;
  } else if (level == 1) {
    // std::cout << ST->getKey() << " ";
    op(ST->getBook());
  } else if (level > 1) {
    LOThelper(ST->getRight(), level - 1, op);
    LOThelper(ST->getLeft(), level - 1, op);
  }
}
