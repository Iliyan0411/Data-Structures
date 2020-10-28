#ifndef TOKENIZER_H
#define TOKENIZER_H
#include <iostream>
#include <string>
#include <cassert>


class Tokenizer
{
private:
    std::istream& in;

    void clear_white_spaces();

public:
    struct Token
    {
        enum TokenType {open_par, number, oper, close_par, error};
        TokenType type;
        int numval;
        char c;
    };

    Tokenizer(std::istream& _in);

    Token next_token();
    bool more_tokens();
};

Tokenizer& operator >> (Tokenizer&, Tokenizer::Token&);

#endif