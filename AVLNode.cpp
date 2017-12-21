#include "AVLNode.hpp"

AVLNode::AVLNode(Book *b) {

  this->m_book = b;

  this->key = b->getId();

  this->m_left = nullptr;

  this->m_right = nullptr;

  this->height = 0;
}

AVLNode *AVLNode::getRight() { return this->m_right; }

AVLNode *AVLNode::getLeft() { return this->m_left; }

int AVLNode::getKey() { return this->key; }

void AVLNode::setLeft(AVLNode *left) { this->m_left = left; }

void AVLNode::setRight(AVLNode *right) { this->m_right = right; }

int AVLNode::getHeight() { return this->height; }

void AVLNode::setHeight(int h) { this->height = h; }

Book *AVLNode::getBook() { return this->m_book; }
