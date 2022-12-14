#ifndef __TOKEN_HPP__
#define __TOKEN_HPP__

#include "util.hpp"

#include <array>
#include <compare>
#include <regex>
#include <string>
#include <utility>

class Token {
    std::string type;
    std::string lexeme;
    int line;
    int column;

public:
    static std::array<std::pair<std::string_view, std::regex>, 6> const regexes;

    Token(std::string_view const &type = "", std::string const &lexeme = "",
          int const line = 0, int const column = 0);

    std::string const &getLexeme() const;

    std::string const &getType() const;

    auto operator<=>(const Token &) const = default;

    operator std::string() const;
};

#endif // __TOKEN_HPP__
