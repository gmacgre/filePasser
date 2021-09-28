//
// Created by Malcolm MacGregor on 9/13/2021.
//

#ifndef LAB1LEXER_QUESTIONAUTO_H
#define LAB1LEXER_QUESTIONAUTO_H


#include "Automaton.h"

class QuestionAuto : public Automaton{
public:
    QuestionAuto() : Automaton(TokenType::Q_MARK) {}
    void S0(const std::string &input) override;
};


#endif //LAB1LEXER_QUESTIONAUTO_H
