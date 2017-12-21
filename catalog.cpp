#include "catalog.hpp"
#include "util.hpp"

Catalog::Catalog() { book_avl = new AVL(); }

Catalog::~Catalog() { delete book_avl; }

void Catalog::addBook(int id, std::string bookName, std::string s,
                      int copyCount) {
  Book* b = new Book(id, bookName, s, copyCount);
  book_avl->addBook(b);
  delete b;
}

Book *Catalog::checkoutBook(int id) {
  Book *temp = book_avl->search(id);
  if (temp == NULL) {
    std::cout << "Book not in library" << std::endl;
    return nullptr;
  } else {
    if (temp->getCurrentCount() < 1) {
      std::cout << "not enough copies of book" << std::endl;
    } else {
      temp->setCurrentCount((temp->getCurrentCount() - 1));
      std::cout << "Successfully checked out book " << std::endl;
      return temp;
    }
  }
  return nullptr;
}

void Catalog::returnBook(int id) {
  Book *temp = book_avl->search(id);
  if (temp == NULL) {
    std::cout << "Book not in library" << std::endl;
    return;
  } else {
    if (temp->getCurrentCount() > temp->getTotalCount()) {
      std::cout << "All copies of book returned" << std::endl;
      return;
    } else {
      std::cout << "Book successfully returned" << std::endl;
      temp->setCurrentCount(temp->getCurrentCount() + 1);
    }
  }
}
