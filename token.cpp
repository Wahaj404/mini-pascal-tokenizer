#include "token.hpp"

std::array<std::pair<std::string_view, std::regex>, 6> const Token::regexes = {
    std::make_pair("KEYWORD",
                   std::regex("^(program|var|real|integer|begin|end|if|then|"
                              "else|while|do|repeat|until|(read|write)(ln)?|"
                              "or|div|mod|and|true|false|not|trunc|real)")),
    std::make_pair("STRING_CONST", std::regex("^\"(.*)\"")),
    std::make_pair("REAL_CONST", std::regex("^([0-9]+\\.[0-9]+)")),
    std::make_pair("INT_CONST", std::regex("^[0-9]+")),
    std::make_pair("IDENTIFIER", std::regex("^([A-Z]|[a-z]|_)+")),
    std::make_pair(
        "SYMBOL",
        std::regex("^(;|\\.|:=?|\\(|\\)|\\+|\\-|\\*|\\/|=|<=?|>=?|<>)"))};

Token::Token(std::string_view const &type, std::string const &lexeme,
             int const line, int const column) :
    type(type),
    lexeme(lexeme), line(line), column(column) {}

std::string const &Token::getLexeme() const {
    return lexeme;
}

std::string const &Token::getType() const {
    return type;
}

Token::operator std::string() const {
    return csv(static_cast<std::string>(type), lexeme, line, column);
}