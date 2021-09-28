//
// Created by Malcolm MacGregor on 9/27/2021.
//

#ifndef LAB1LEXER_PARAMETER_H
#define LAB1LEXER_PARAMETER_H


#include <string>
#include <utility>

class Parameter {
public:
    explicit Parameter(std::string newIn) : info(std::move(newIn)) {}
    std::string getInfo(){ return info; }
    void setInfo(std::string &in) { info = in; }
    std::string toString() const {
        return info;
    }
    friend std::ostream& operator<<(std::ostream& os, const Parameter& p){
        os << p.toString();
        return os;
    }
private:
    std::string info;
};


#endif //LAB1LEXER_PARAMETER_H
