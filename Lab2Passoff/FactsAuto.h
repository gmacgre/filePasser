//
// Created by Malcolm MacGregor on 9/13/2021.
//

#ifndef LAB1LEXER_FACTSAUTO_H
#define LAB1LEXER_FACTSAUTO_H

#include "Automaton.h"

class FactsAuto : public Automaton{
private:
    void S1(const std::string &input);
    void S2(const std::string &input);
    void S3(const std::string &input);
    void S4(const std::string &input);
public:
    FactsAuto() : Automaton(TokenType::FACTS){}
    void S0(const std::string &input) override;
};


#endif //LAB1LEXER_FACTSAUTO_H
