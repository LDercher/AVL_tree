#include "book.hpp"
#include "util.hpp"

Book::Book(int id, std::string name, std::string publisher, int copyCount) {
  this->id = id;
  this->name = name;
  this->publisher = publisher;
  this->currentCount = copyCount;
  this->totalCount = copyCount;
}

int Book::getId() { return this->id; }

std::string Book::getName() { return this->name; }

std::string Book::getPublisher() { return this->publisher; }

int Book::getCurrentCount() { return this->currentCount; }

void Book::setCurrentCount(int count) { this->currentCount = count; }

int Book::getTotalCount() { return this->totalCount; }

void Book::setTotalCount(int count) { this->totalCount = count; }
