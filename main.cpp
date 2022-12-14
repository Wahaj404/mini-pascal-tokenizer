#include "lexer.hpp"

#include <bits/stdc++.h>

int main(int const argc, char const *argv[]) {
    if (argc != 4) {
        std::cerr << "Usage: ./parser input_file token_list_output "
                     "symbol_table_output\n";
        std::exit(1);
    }
    Lexer lexer(argv[1]);
    std::ofstream tokens(argv[2]);
    tokens << "Token Type,Lexeme,Line Number,Position\n";
    std::ofstream symbols(argv[3]);
    symbols << "Identifier,Type\n";

    std::string lastToken, lastId;
    while (lexer.isValid()) {
        if (auto token = lexer.next(); lexer.isValid()) {
            if (token.getLexeme() == "var" || token.getLexeme() == "begin") {
                lastToken = token.getLexeme();
            } else if (token.getType() == "IDENTIFIER") {
                lastId = token.getLexeme();
            } else if (token.getType() == "KEYWORD" && lastToken == "var") {
                symbols << csv(lastId, token.getLexeme()) << '\n';
            }
            tokens << static_cast<std::string>(token) << '\n';
        }
    }
}
