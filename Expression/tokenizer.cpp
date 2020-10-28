#include "tokenizer.h"


Tokenizer::Tokenizer(std::istream& _in): in(_in){}

typename Tokenizer::Token Tokenizer::next_token()
{
    clear_white_spaces();

    Tokenizer::Token result({Tokenizer::Token::error,-1,'?'});

    char c = in.peek();

    if(std::isdigit(c))
    {
        result.type = Tokenizer::Token::number;
        in >> result.numval;
    }else if(c == '(')
    {
        result.type = Tokenizer::Token::open_par;
        in >> result.c;
    }else if(c == ')')
    {
        result.type = Tokenizer::Token::close_par;
        in >> result.c;
    }else if(c == '+' || c == '-' || c == '*' || c == '/')
    {
        result.type = Tokenizer::Token::oper;
        in >> result.c;
    }
    else{
        throw "Wrong expression!\n";
    }

    return result;
}

bool Tokenizer::more_tokens()
{
    return (bool)in;
}

void Tokenizer::clear_white_spaces()
{
    while(in && in.peek() <= 32)
    {
        in.get();
    }
}

Tokenizer& operator >> (Tokenizer& tokenizer, typename Tokenizer::Token& result)
{
    result = tokenizer.next_token();
    return tokenizer;
}