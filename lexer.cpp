#include "lexer.hpp"

std::sregex_iterator const Lexer::regex_end;

void Lexer::skip() {
    static const std::regex whitespace("\\S");

    std::string in;
    while (std::getline(file, in)) {
        if (in.empty()) {
            ++line;
            column = 1;
        } else {
            file.seekg(-in.length(), std::ios_base::cur);
            if (auto it =
                    std::sregex_iterator(in.begin(), in.end(), whitespace);
                it != regex_end) {
                column += it->position();
                file.seekg(it->position() - 1, std::ios_base::cur);
            }
            return;
        }
    }
}

Lexer::Lexer(std::string const &filename) :
    file(filename), line(1), column(1) {}

Token Lexer::next() {
    skip();
    std::string in;
    std::getline(file, in);
    for (auto [name, regex] : Token::regexes) {
        if (auto it = std::sregex_iterator(in.begin(), in.end(), regex);
            it != regex_end) {
            auto lexeme = it->str();
            file.seekg(lexeme.length() - in.length() - 1, std::ios_base::cur);
            column += lexeme.length();
            return {name, lexeme, line,
                    column - static_cast<int>(lexeme.length())};
        }
    }
    return {};
}

bool Lexer::isValid() const {
    return !file.eof();
}
