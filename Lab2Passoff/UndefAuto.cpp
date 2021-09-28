//
// Created by Malcolm MacGregor on 9/14/2021.
//

#include "UndefAuto.h"

void UndefAuto::S0(const std::string &input) {

    if(input[index] == '#' && input[index + 1] == '|'){
        isComment = true;
        inputRead += 2;
        index += 2;
        S1(input);
    }
    else if(input[index] == '\''){
        isComment = false;
        inputRead++;
        index++;
        S1(input);
    }
    else{
        Serr();
    }
}

void UndefAuto::S1(const std::string &input) {
    if(isComment && (input[index] == '|') && (input[index + 1] == '#')){ //block comment successfully terminates
        Serr();
    }
    else if(!isComment && (input[index] == '\'') && (input[index + 1] == '\'')){
        inputRead += 2;
        index += 2;
        S1(input);
    }
    else if(!isComment && (input[index] == '\'') && (input[index + 1] != '\'')){ //string sucessfully terminates
        Serr();
    }
    else if(input[index] == '\0'){
        inputRead--;
        newLines--;
        return;
    }
    else{
        if(input[index] == '\n') newLines++;
        index++;
        inputRead++;
        S1(input);
    }
}
