//
//  Book.hpp
//  CF.BookReport00
//
//  Created by Alan Sampson on 2/21/21.
//

#pragma once
#ifndef Book_hpp
#define Book_hpp

#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <utility>

#include "Author.hpp"

using namespace std::literals::string_literals;

namespace bkrp {

//  Class Book
class Book {
public:
  Book(std::string name = ""s,
       Author author = { ""s, ""s, UNSPECIFIED, },
       double price = 0.0, int qtyInStock = 0);
  virtual ~Book() = default;

  Book(Book const & that) noexcept;
  Book(Book && that) noexcept;

  Book & operator=(Book const & that) noexcept;
  Book & operator=(Book && that) noexcept;
 
  virtual std::string getName(void)       const { return name_; }
  virtual Author      getAuthor(void)     const { return author_; }
  virtual double      getPrice(void)      const { return price_; }
  virtual int         getQtyInStock(void) const { return qtyInStock_; }

  virtual void setPrice(double price)        { price_ = price; }
  virtual void setQtyInStock(int qtyInStock) { qtyInStock_ = qtyInStock; }

  virtual std::string getAuthorName(void) const { return author_.name; }

  virtual void print(bool raw = false) const;
  virtual std::string toString(bool raw = false) const;
  virtual std::string json(void) const;

private:
  std::string name_;
  Author      author_;
  double      price_;
  int         qtyInStock_;
};

} /* namespace bkrp */

#endif /* Book_hpp */
