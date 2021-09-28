//
// Created by Malcolm MacGregor on 9/13/2021.
//

#include "CommentAuto.h"

void CommentAuto::S0(const std::string &input) {
    if(input[index] == '#'){
        index++;
        inputRead = 1;
        S1(input);
    }
    else{
        Serr();
    }
}

void CommentAuto::S1(const std::string &input) {
    if(input[index] == '\n' || input[index] == '\0'){
        return;
    }
    else if(input[index] == '|' && input[index + 1] == '#') Serr();
    else{
        index++;
        inputRead++;
        S1(input);
    }
}
