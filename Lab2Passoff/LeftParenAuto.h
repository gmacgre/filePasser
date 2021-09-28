//
// Created by Malcolm MacGregor on 9/13/2021.
//

#ifndef LAB1LEXER_LEFTPARENAUTO_H
#define LAB1LEXER_LEFTPARENAUTO_H

#include "Automaton.h"

class LeftParenAuto : public Automaton{
public:
    LeftParenAuto() : Automaton(TokenType::LEFT_PAREN) {}
    void S0(const std::string &input) override;
};


#endif //LAB1LEXER_LEFTPARENAUTO_H
