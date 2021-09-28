//
// Created by Malcolm MacGregor on 9/13/2021.
//

#include "IdAuto.h"

void IdAuto::S0(const std::string &input) {
    if (isalpha(input[index])) {
        inputRead = 1;
        index++;
        S1(input);
    }
    else {
        Serr();
    }
}

void IdAuto::S1(const std::string &input) {
    if(std::isspace(input[index])){
        return;
    }
    else if(std::isalpha(input[index]) || std::isdigit(input[index])){
        index++;
        inputRead++;
        S1(input);
    }
    else{
        return;
    }
}
