//
// Created by Malcolm MacGregor on 9/13/2021.
//

#include "EndOfFileAuto.h"

void EndOfFileAuto::S0(const std::string &input) {
    if(input[index] == '\0'){
        inputRead = 1;
    }
    else{
        Serr();
    }
}
