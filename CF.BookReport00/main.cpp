//
//  main.cpp
//  CF.BookReport00
//
//  Created by Alan Sampson on 2/21/21.
//

#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <map>
#include <utility>

#include "Book.hpp"

using namespace std::literals::string_literals;

/*
 *  MARK: main()
 */
int main(int argc, const char * argv[]) {
  std::cout << "CF.BookReport00"s << std::endl;

  std::cout << "Vector"s << std::endl;

  auto books = std::vector<bkrp::Book> {
   bkrp::Book("Lord of the Rings"s,
    { "J.R.R. Tolkien", "jrrt@middleearth.ac.uk"s, bkrp::MALE }, 45.0, 5),
    bkrp::Book("A Brief History of Time"s,
    { "Stephen Hawking", "hawking@thirdblackholeontheleft.ac.uc"s, bkrp::MALE }),
  };

  books[1].setPrice(30.0);
  books[1].setQtyInStock(15);

  for (auto const & bk : books) {
    bk.print();
  }
  std::cout << std::endl;

  auto bkmp = std::map<std::string const, bkrp::Book> {
    { "lotr"s,
      bkrp::Book("Lord of the Rings"s,
           { "J.R.R. Tolkien", "jrrt@middleearth.ac.uk"s, bkrp::MALE, },
           45.0, 5), },
    { "bhot"s,
      bkrp::Book("A Brief History of Time"s,
           { "Stephen Hawking", "hawking@thirdblackholeontheleft.ac.uc"s, bkrp::MALE, }), },
    { "con"s,
      bkrp::Book("The Chronicles of Narnia"s,
           { "C.S. Lewis"s, "CliveStaples@narnia.ac.uk", bkrp::MALE, }), },
    { "aiw"s,
      bkrp::Book("Alice in Wonderland"s,
           { "Lewis Carroll"s, "CharlesLutwidgeDodgson@wonderland.ac.uc", bkrp::MALE, },
           29.99, 40), },
    { "attlg"s,
      bkrp::Book("Through the Looking-Glass, and What Alice Found There"s,
           { "Lewis Carroll"s, "CharlesLutwidgeDodgson@wonderland.ac.uc", bkrp::MALE, },
           29.99, 35), },
    { "hpps"s,
      bkrp::Book("Harry Potter and the Philosopher's Stone"s,
           {"J.K. Rowling"s, "jk@hogwarts.ac.uk"s, bkrp::FEMALE, },
           15.49, 19), },
  };

  std::cout << "Map"s << std::endl;

  bkmp["bhot"s].setPrice(30.0);
  bkmp["bhot"s].setQtyInStock(15);

  bkmp["con"s].setPrice(15.0);
  bkmp["con"s].setQtyInStock(12);

  for (auto const & [key, val] : bkmp) {
    std::cout << key << ": "s << val.toString() << std::endl;
  }
  std::cout << std::endl;

  for (auto const & [key, val] : bkmp) {
    std::cout << key << ": "s << val.toString(true) << std::endl;
  }
  std::cout << std::endl;

  auto first(true);
  std::cout << "[\n";
  std::for_each(bkmp.cbegin(), bkmp.cend(), [&first](auto const & it) {
    auto const key = it.first;
    auto const val = it.second;
    auto scd = first ? ""s : ", ";
    first = false;
    std::cout << scd << '\n';
    std::cout << " \"id\" : \""s << key << "\" , \"book\" : "s << '\n';
    std::cout << val.json() << '\n';
  });
  std::cout << " ]\n"s;
  std::cout << std::endl;

  return 0;
}
