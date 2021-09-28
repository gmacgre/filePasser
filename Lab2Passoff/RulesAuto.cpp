//
// Created by Malcolm MacGregor on 9/13/2021.
//

#include "RulesAuto.h"

void RulesAuto::S0(const std::string &input) {
    if (input[index] == 'R') {
        inputRead = 1;
        index++;
        S1(input);
    }
    else {
        Serr();
    }
}

void RulesAuto::S1(const std::string &input) {
    if (input[index] == 'u') {
        inputRead++;
        index++;
        S2(input);
    }
    else {
        Serr();
    }
}

void RulesAuto::S2(const std::string &input) {
    if (input[index] == 'l') {
        inputRead++;
        index++;
        S3(input);
    }
    else {
        Serr();
    }
}

void RulesAuto::S3(const std::string &input) {
    if (input[index] == 'e') {
        inputRead++;
        index++;
        S4(input);
    }
    else {
        Serr();
    }
}

void RulesAuto::S4(const std::string &input) {
    if (input[index] == 's') {
        inputRead++;
    }
    else {
        Serr();
    }
}
