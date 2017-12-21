#ifndef CATALOG_HPP
#define CATALOG_HPP

#include "avl.hpp"
#include "book.hpp"
#include <string>
/**
 * Stores information of all the book in the library
 */
class Catalog {

private:
  // Member fields
  // IMPLEMENT ME
  AVL *book_avl;
  // Member functions
  // IMPLEMENT ME

public:
  // Member functions
  /**
   * Constructor to construct the bok catalog.
   */
  Catalog();

  /**
   * Destructor to destroy the Catalog
   * Make sure you destroy everything that you allocate on heap.
   */
  ~Catalog();

  /**
   * add and element to book library catalog
   */
  void addBook(int id, std::string bookName, std::string, int copyCount);

  /**
   * checkout book from the library
   */
  Book *checkoutBook(int id);

  /**
   * return book to library
   */
  void returnBook(int id);
};

#endif // CATALOG_H defined
