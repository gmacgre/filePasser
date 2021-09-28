//
// Created by Malcolm MacGregor on 9/13/2021.
//

#ifndef LAB1LEXER_PERIOD_H
#define LAB1LEXER_PERIOD_H

#include "Automaton.h"

class Period : public Automaton{
public:
    Period() : Automaton(TokenType::PERIOD) {}

    void S0(const std::string &input) override;
};


#endif //LAB1LEXER_PERIOD_H
