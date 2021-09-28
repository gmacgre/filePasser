//
// Created by Malcolm MacGregor on 9/13/2021.
//

#ifndef LAB1LEXER_COMMENTAUTO_H
#define LAB1LEXER_COMMENTAUTO_H


#include "Automaton.h"

class CommentAuto : public Automaton{
private:
    void S1(const std::string& input);
public:
    CommentAuto() : Automaton(TokenType::COMMENT){}
    void S0(const std::string &input) override;
};


#endif //LAB1LEXER_COMMENTAUTO_H
