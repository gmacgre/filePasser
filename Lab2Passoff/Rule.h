//
// Created by Malcolm MacGregor on 9/27/2021.
//

#ifndef LAB1LEXER_RULE_H
#define LAB1LEXER_RULE_H


#include "Predicate.h"

class Rule {
public:
    Rule() = default;
    explicit Rule(Predicate* newH) : headPred(newH){}
    void addPred(Predicate* newP){
        bodyPreds.push_back(newP);
    }
    std::string toString() const{
        std::ostringstream out;
        out << *headPred << " :- ";
        for(unsigned i = 0; i < bodyPreds.size(); i++){
            out << *bodyPreds.at(i);
            if(i != bodyPreds.size() - 1) out << ",";
        }
        return out.str();
    }
    friend std::ostream& operator<<(std::ostream& os, const Rule &h){
        os << h.toString();
        return os;
    }
private:
    Predicate* headPred;
    std::vector<Predicate*> bodyPreds;
};


#endif //LAB1LEXER_RULE_H
