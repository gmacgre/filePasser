//
// Created by Malcolm MacGregor on 9/13/2021.
//

#ifndef LAB1LEXER_ADDAUTO_H
#define LAB1LEXER_ADDAUTO_H


#include "Automaton.h"

class AddAuto : public Automaton{
public:
    AddAuto() : Automaton(TokenType::ADD) {}
    void S0(const std::string &input) override;
};


#endif //LAB1LEXER_ADDAUTO_H
