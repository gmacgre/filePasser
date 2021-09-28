//
// Created by Malcolm MacGregor on 9/13/2021.
//

#ifndef LAB1LEXER_ENDOFFILEAUTO_H
#define LAB1LEXER_ENDOFFILEAUTO_H


#include "Automaton.h"

class EndOfFileAuto : public Automaton{
public:
    EndOfFileAuto() : Automaton(TokenType::END){}
    void S0(const std::string &input) override;
};


#endif //LAB1LEXER_ENDOFFILEAUTO_H
