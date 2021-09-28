//
// Created by Malcolm MacGregor on 9/14/2021.
//

#ifndef LAB1LEXER_UNDEFAUTO_H
#define LAB1LEXER_UNDEFAUTO_H


#include "Automaton.h"

class UndefAuto : public Automaton{
private:
    void S1(const std::string& input);
    bool isComment; //other option is being a block comment
public:
    UndefAuto() : Automaton(TokenType::UNDEFINED){
        isComment = false;
    }
    void S0(const std::string &input) override;
};


#endif //LAB1LEXER_UNDEFAUTO_H
