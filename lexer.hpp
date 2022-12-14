#ifndef __LEXER_HPP__
#define __LEXER_HPP__

#include "token.hpp"

#include <fstream>
#include <regex>
#include <string>

class Lexer {
    static std::sregex_iterator const regex_end;

    std::ifstream file;
    int line;
    int column;

    void skip();

public:
    Lexer(std::string const &filename);

    Token next();

    bool isValid() const;
};

#endif // __LEXER_HPP__
