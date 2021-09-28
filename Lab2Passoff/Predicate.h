//
// Created by Malcolm MacGregor on 9/27/2021.
//

#ifndef LAB1LEXER_PREDICATE_H
#define LAB1LEXER_PREDICATE_H


#include <utility>
#include <vector>
#include <sstream>
#include "Parameter.h"

class Predicate {
public:
    Predicate() = default;
    explicit Predicate(std::string newId) : id(std::move(newId)){}
    void addParam(Parameter* newP){
        params.push_back(newP);
    }
    std::string toString() const {
        std::ostringstream out;
        out << id << "(";
        for(unsigned i = 0; i < params.size(); i++){
            out << *params.at(i);
            if(i != params.size() - 1) out << ",";
        }
        out << ")";
        return out.str();
    }
    friend std::ostream& operator<<(std::ostream& os, const Predicate &p){
        os << p.toString();
        return os;
    }

private:
    std::vector<Parameter*> params;
    std::string id;
};


#endif //LAB1LEXER_PREDICATE_H
