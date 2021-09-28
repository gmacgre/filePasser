//
// Created by Malcolm MacGregor on 9/13/2021.
//

#ifndef LAB1LEXER_MULTIPLYAUTO_H
#define LAB1LEXER_MULTIPLYAUTO_H


#include "Automaton.h"

class MultiplyAuto : public Automaton{
public:
    MultiplyAuto() : Automaton(TokenType::MULTIPLY) {}
    void S0(const std::string &input) override;
};


#endif //LAB1LEXER_MULTIPLYAUTO_H
