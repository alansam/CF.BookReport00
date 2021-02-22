//
//  Author.hpp
//  CF.BookReport00
//
//  Created by Alan Sampson on 2/21/21.
//

#pragma once
#ifndef Author_hpp
#define Author_hpp

#include <string>

namespace bkrp {

//  MARK: Enumeration Gender
enum Gender { UNSPECIFIED, MALE = 'M', FEMALE = 'F', };

//  MARK: Structure Author
struct Author {
public:
  std::string name;
  std::string email;
  Gender gender;
};

} /* namespace bkrp */

#endif /* Author_hpp */
