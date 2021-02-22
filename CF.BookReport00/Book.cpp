//
//  Book.cpp
//  CF.BookReport00
//
//  Created by Alan Sampson on 2/21/21.
//

#include "Book.hpp"

using namespace std::literals::string_literals;

namespace bkrp {

/*
 *  MARK: Book::Book() - default c'tor
 */
Book::Book(std::string name, Author author, double price, int qtyInStock)
: name_(name), author_(author), price_(price), qtyInStock_(qtyInStock) {}

/*
 *  MARK: Book::Book() - copy c'tor
 */
Book::Book(Book const & that) noexcept
: name_(that.name_), author_(that.author_), price_(that.price_), qtyInStock_(that.qtyInStock_) {}

/*
 *  MARK: Book::Book() - move c'tor
 */
Book::Book(Book && that) noexcept {
  if (this != &that) {
    name_       = std::move(that.name_);
    author_     = std::move(that.author_);
    price_      = std::move(that.price_);
    qtyInStock_ = std::move(that.qtyInStock_);
  }
}

/*
 *  MARK: Book::operator=() - copy assignment
 */
Book & Book::operator=(Book const & that) noexcept {
  if (this != &that) {
    name_       = that.name_;
    author_     = that.author_;
    price_      = that.price_;
    qtyInStock_ = that.qtyInStock_;
  }

  return *this;
}

/*
 *  MARK: Book::operator=() - move assignment
 */
Book & Book::operator=(Book && that) noexcept {
  if (this != &that) {
    name_       = std::move(that.name_);
    author_     = std::move(that.author_);
    price_      = std::move(that.price_);
    qtyInStock_ = std::move(that.qtyInStock_);
  }

  return *this;
}

/*
 *  MARK: Book::print()
 */
void Book::print(bool raw) const {
  std::cout << toString(raw) << std::endl;
}

/*
 *  MARK: Book::toString()
 */
std::string Book::toString(bool raw) const {
  std::ostringstream ss;
  std::string book;

  char gn = author_.gender == MALE ? 'M' : (author_.gender == FEMALE ? 'F' : 'U');

  if (raw) {
    ss << "\""s << getName() << "\","s
       << "\""s << std::fixed << std::setprecision(2) << getPrice() << "\","s
       << "\""s << getQtyInStock() << "\","s
       << "\""s << getAuthorName() << "\","s
       << "\""s << author_.email << "\""s
       << "\""s << gn << "\""s;
  }
  else {
    ss << "Name: \""     << getName()
       << "\", price: "  << std::fixed << std::setprecision(2) << getPrice()
       << ", in stock: " << getQtyInStock()
       << " [Author: "   << getAuthorName()
       << ", email: "    << author_.email
       << ", gender: "   << gn
       << "]";
  }

  book = ss.str();
  
  return book;
}

/*
 *  MARK: Book::json()
 */
std::string Book::json(void) const {
  std::ostringstream jss;
  std::string json;

  char gn = author_.gender == MALE ? 'M' : (author_.gender == FEMALE ? 'F' : 'U');

  jss << "{ "s
      << "\"name\" : \""s     << getName() << "\", "s
      << "\"price\" : "       << std::fixed << std::setprecision(2) << getPrice() << ", "s
      << "\"qtyInStock\" : "s << getQtyInStock()   << ", "s
      << "\"author\" : { "s
      << "\"name\" : \""s     << getAuthorName()   << "\", "s
      << "\"email\" : \""s    << getAuthor().email << "\", "s
      << "\"gender\" : \""s   << gn << "\""s
      << " }"s
      << " }"s;

  json = jss.str();
  return json;
}

} /* namespace bkrp */
