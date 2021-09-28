//
// Created by Malcolm MacGregor on 9/13/2021.
//

#ifndef LAB1LEXER_RIGHTPARENAUTO_H
#define LAB1LEXER_RIGHTPARENAUTO_H


#include "Automaton.h"

class RightParenAuto : public Automaton{
public:
    RightParenAuto() : Automaton(TokenType::RIGHT_PAREN){}
    void S0(const std::string &input) override;
};


#endif //LAB1LEXER_RIGHTPARENAUTO_H
