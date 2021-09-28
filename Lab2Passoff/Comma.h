//
// Created by Malcolm MacGregor on 9/13/2021.
//

#ifndef LAB1LEXER_COMMA_H
#define LAB1LEXER_COMMA_H


#include "Automaton.h"

class Comma : public Automaton {
public:
    Comma() : Automaton(TokenType::COMMA){}
    void S0(const std::string& input) override;

};


#endif //LAB1LEXER_COMMA_H
