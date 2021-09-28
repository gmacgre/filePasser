//
// Created by Malcolm MacGregor on 9/13/2021.
//

#include "LeftParenAuto.h"

void LeftParenAuto::S0(const std::string &input) {
    if (input[index] == '(') {
        inputRead = 1;
    }
    else {
        Serr();
    }
}
