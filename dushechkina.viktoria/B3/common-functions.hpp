#ifndef COMMON_FUNCTIONS_HPP
#define COMMON_FUNCTIONS_HPP
#include <iosfwd>
#include <string>
namespace dushechkina
{
 void checkForFailInput(const std::istream& in);
 void checkForEmptyInput(const std::string& in);
 void incorrectIndex(std::ostream& out);
 constexpr const char* EMPTY = "<EMPTY>\n";
 constexpr const char* INVALID_STEP = "<INVALID STEP>\n";
 constexpr const char* INVALID_COMMAND = "<INVALID COMMAND>\n";
 constexpr const char* INVALID_BOOKMARK = "<INVALID BOOKMARK>\n";
}
#endif
