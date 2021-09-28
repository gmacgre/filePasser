//
// Created by Malcolm MacGregor on 9/13/2021.
//

#include "BlockCommentAuto.h"

void BlockCommentAuto::S0(const std::string &input) {
    if(input[index] == '#'){
        inputRead = 1;
        index++;
        S1(input);
    }
    else{
        Serr();
    }
}

void BlockCommentAuto::S1(const std::string &input) {
    if(input[index] == '|'){ //we're in business, baby
        inputRead++;
        index++;
        S2(input);
    }
}

void BlockCommentAuto::S2(const std::string &input) {
    if(input[index] == '\0'){
        Serr();
    }
    else if(input[index] != '|'){
        if(input[index] == '\n') newLines++;
        inputRead++;
        index++;
        S2(input);
    }
    else{
        inputRead++;
        index++;
        S3(input);
    }
}

void BlockCommentAuto::S3(const std::string &input){
    if(input[index] == '#'){
        inputRead++;
        return;
    }
    else if(input[index] == '\0'){
        Serr();
    }
    else{
        if(input[index] == '\n') newLines++;
        inputRead++;
        index++;
        S2(input);
    }
}
