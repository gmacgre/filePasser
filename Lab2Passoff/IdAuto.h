//
// Created by Malcolm MacGregor on 9/13/2021.
//

#ifndef LAB1LEXER_IDAUTO_H
#define LAB1LEXER_IDAUTO_H


#include "Automaton.h"

class IdAuto : public Automaton {
private:
    void S1(const std::string &input);
public:
    IdAuto() : Automaton(TokenType::ID){}
    void S0(const std::string &input) override;
};


#endif //LAB1LEXER_IDAUTO_H
