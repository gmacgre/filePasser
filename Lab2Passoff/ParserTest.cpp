//
// Created by Malcolm MacGregor on 9/25/2021.
//

#include "ParserTest.h"


void ParserTest::runSyntax() {
    std::vector<Token*> holdOver = tokens;
    syntaxStack.push(DATALOG_PROG);
    if(syntaxStack.top() == DATALOG_PROG && tokens.at(0)->getStyle() == TokenType::SCHEMES){
        parseFull();
    }
    else if(syntaxStack.top() == DATALOG_PROG && tokens.at(0)->getStyle() == TokenType::END){
        return;
    }
    else throw "First Line is bad lmaoooo";
    tokens = holdOver;
}

void ParserTest::parseFull() {
    //here we push the needed stuff to the start of the program
    syntaxStack.pop(); // should be empty stack tbh
    //adding all of the terminals and non-terms the production makes
    syntaxStack.push(T_EOF);
    syntaxStack.push(QUERY_LIST);
    syntaxStack.push(QUERY);
    syntaxStack.push(T_COLON);
    syntaxStack.push(T_QUERIES);
    syntaxStack.push(RULE_LIST);
    syntaxStack.push(T_COLON);
    syntaxStack.push(T_RULES);
    syntaxStack.push(FACT_LIST);
    syntaxStack.push(T_COLON);
    syntaxStack.push(T_FACTS);
    syntaxStack.push(SCHEME_LIST);
    syntaxStack.push(SCHEME);
    syntaxStack.push(T_COLON);
    syntaxStack.push(T_SCHEMES);
    runCheck();
}

void ParserTest::runCheck() {
    //doing the terminal work
    switch(syntaxStack.top()){
        case DATALOG_PROG:
            throw "This should never happen- we popped the datalog already";
        case SCHEME_LIST:
            testSchemeList();
            break;
        case FACT_LIST:
            testFactList();
            break;
        case RULE_LIST:
            testRuleList();
            break;
        case QUERY_LIST:
            testQueryList();
            break;
        case SCHEME:
            testScheme();
            break;
        case FACT:
            testFact();
            break;
        case RULE:
            testRule();
            break;
        case QUERY:
            testQuery();
            break;
        case HEAD_PRED:
            testHeadPred();
            break;
        case PRED:
            testPred();
            break;
        case PRED_LIST:
            testPredList();
            break;
        case PARAM_LIST:
            testParamList();
            break;
        case STRING_LIST:
            testStringList();
            break;
        case ID_LIST:
            testIDList();
            break;
        case PARAM:
            testParam();
            break;

        ///now we work on the terminals rather than the non-terminals
        ///these all pretty much operate in the same way
        ///if the terminal matches with the latest input, pop the stack and remove the vector's first item
        ///otherwise, throw a related error to be caught up above in heaven
        case T_SCHEMES:
            if(tokens.at(0)->getStyle() == TokenType::SCHEMES){
                tokens.erase(tokens.begin());
                syntaxStack.pop();
                runCheck();
            }
            else throw tokens.at(0)->toString();
            break;
        case T_FACTS:
            if(tokens.at(0)->getStyle() == TokenType::FACTS){
                tokens.erase(tokens.begin());
                syntaxStack.pop();
                runCheck();
            }
            else throw tokens.at(0)->toString();
            break;
        case T_RULES:
            if(tokens.at(0)->getStyle() == TokenType::RULES){
                tokens.erase(tokens.begin());
                syntaxStack.pop();
                runCheck();
            }
            else throw tokens.at(0)->toString();
            break;
        case T_QUERIES:
            if(tokens.at(0)->getStyle() == TokenType::QUERIES){
                tokens.erase(tokens.begin());
                syntaxStack.pop();
                runCheck();
            }
            else throw tokens.at(0)->toString();
            break;
        case T_EOF:
            if(tokens.at(0)->getStyle() == TokenType::END){
                tokens.erase(tokens.begin());
                syntaxStack.pop();
            }
            else throw tokens.at(0)->toString();
            break;
        case T_COLON:
            if(tokens.at(0)->getStyle() == TokenType::COLON){
                tokens.erase(tokens.begin());
                syntaxStack.pop();
                runCheck();
            }
            else throw tokens.at(0)->toString();
            break;
        case T_PERIOD:
            if(tokens.at(0)->getStyle() == TokenType::PERIOD){
                tokens.erase(tokens.begin());
                syntaxStack.pop();
                runCheck();
            }
            else throw tokens.at(0)->toString();
            break;
        case T_COLON_DASH:
            if(tokens.at(0)->getStyle() == TokenType::COLON_DASH){
                tokens.erase(tokens.begin());
                syntaxStack.pop();
                runCheck();
            }
            else throw tokens.at(0)->toString();
            break;
        case T_COMMA:
            if(tokens.at(0)->getStyle() == TokenType::COMMA){
                tokens.erase(tokens.begin());
                syntaxStack.pop();
                runCheck();
            }
            else throw tokens.at(0)->toString();
            break;
        case T_ID:
            if(tokens.at(0)->getStyle() == TokenType::ID){
                tokens.erase(tokens.begin());
                syntaxStack.pop();
                runCheck();
            }
            else throw tokens.at(0)->toString();
            break;
        case T_RIGHT_PAREN:
            if(tokens.at(0)->getStyle() == TokenType::RIGHT_PAREN){
                tokens.erase(tokens.begin());
                syntaxStack.pop();
                runCheck();
            }
            else throw tokens.at(0)->toString();
            break;
        case T_LEFT_PAREN:
            if(tokens.at(0)->getStyle() == TokenType::LEFT_PAREN){
                tokens.erase(tokens.begin());
                syntaxStack.pop();
                runCheck();
            }
            else throw tokens.at(0)->toString();
            break;
        case T_STRING:
            if(tokens.at(0)->getStyle() == TokenType::STRING){
                tokens.erase(tokens.begin());
                syntaxStack.pop();
                runCheck();
            }
            else throw tokens.at(0)->toString();
            break;
        case T_QMARK:
            if(tokens.at(0)->getStyle() == TokenType::Q_MARK){
                tokens.erase(tokens.begin());
                syntaxStack.pop();
                runCheck();
            }
            else throw tokens.at(0)->toString();
            break;
        default:
            break;
    }
}

void ParserTest::testSchemeList() {
    syntaxStack.pop();
    if(tokens.at(0)->getStyle() == TokenType::ID){
        //has the start of a scheme, required in a schemeList
        syntaxStack.push(SCHEME_LIST);
        syntaxStack.push(SCHEME);
        runCheck();
    }
    else if(tokens.at(0)->getStyle() == TokenType::FACTS){ //we have a lambda version of a schemeList
        runCheck();
    }
    else{
        throw tokens.at(0)->toString();
    }
}
void ParserTest::testFactList() {
    syntaxStack.pop();
    if(tokens.at(0)->getStyle() == TokenType::ID){
        //has the start of a scheme, required in a schemeList
        syntaxStack.push(FACT_LIST);
        syntaxStack.push(FACT);
        runCheck();
    }
    else if(tokens.at(0)->getStyle() == TokenType::RULES){ //we have a lambda version of a schemeList
        runCheck();
    }
    else{
        throw tokens.at(0)->toString();
    }
}
void ParserTest::testRuleList() {
    syntaxStack.pop();
    if(tokens.at(0)->getStyle() == TokenType::ID){
        //has the start of a scheme, required in a schemeList
        syntaxStack.push(RULE_LIST);
        syntaxStack.push(RULE);

        runCheck();
    }
    else if(tokens.at(0)->getStyle() == TokenType::QUERIES){ //we have a lambda version of a schemeList
        runCheck();
    }
    else{
        throw tokens.at(0)->toString();
    }
}
void ParserTest::testQueryList() {
    syntaxStack.pop();
    if(tokens.at(0)->getStyle() == TokenType::ID){
        //has the start of a scheme, required in a schemeList
        syntaxStack.push(QUERY_LIST);
        syntaxStack.push(QUERY);
        runCheck();
    }
    else if(tokens.at(0)->getStyle() == TokenType::END){ //we have a lambda version of a schemeList
        runCheck();
    }
    else{
        throw tokens.at(0)->toString();
    }
}

void ParserTest::testScheme() {
    syntaxStack.pop();
    if(tokens.at(0)->getStyle() == TokenType::ID){
        //has the start of a scheme, add needed and begin parsing
        syntaxStack.push(T_RIGHT_PAREN);
        syntaxStack.push(ID_LIST);
        syntaxStack.push(T_ID);
        syntaxStack.push(T_LEFT_PAREN);
        syntaxStack.push(T_ID);
        runCheck();
    }
    else{
        throw tokens.at(0)->toString();
    }
}
void ParserTest::testFact() {
    syntaxStack.pop();
    if(tokens.at(0)->getStyle() == TokenType::ID){
        //has the start of a scheme, add needed and begin parsing
        ///ID LEFT_PAREN STRING stringList RIGHT_PAREN PERIOD
        syntaxStack.push(T_PERIOD);
        syntaxStack.push(T_RIGHT_PAREN);
        syntaxStack.push(STRING_LIST);
        syntaxStack.push(T_STRING);
        syntaxStack.push(T_LEFT_PAREN);
        syntaxStack.push(T_ID);
        runCheck();
    }
    else{
        throw tokens.at(0)->toString();
    }
}
void ParserTest::testRule() {
    syntaxStack.pop();
    if(tokens.at(0)->getStyle() == TokenType::ID){
        //has the start of a scheme, add needed and begin parsing
        ///headPredicate COLON_DASH predicate predicateList PERIOD
        syntaxStack.push(T_PERIOD);
        syntaxStack.push(PRED_LIST);
        syntaxStack.push(PRED);
        syntaxStack.push(T_COLON_DASH);
        syntaxStack.push(HEAD_PRED);
        runCheck();
    }
    else{
        throw tokens.at(0)->toString();
    }
}
void ParserTest::testQuery() {
    syntaxStack.pop();
    if(tokens.at(0)->getStyle() == TokenType::ID){
        syntaxStack.push(T_QMARK);
        syntaxStack.push(PRED);
        runCheck();
    }
    else{
        throw tokens.at(0)->toString();
    }
}

void ParserTest::testHeadPred() {
    syntaxStack.pop();
    if(tokens.at(0)->getStyle() == TokenType::ID){
        //has the start of a scheme, add needed and begin parsing
        ///ID LEFT_PAREN ID idList RIGHT_PAREN
        syntaxStack.push(T_RIGHT_PAREN);
        syntaxStack.push(ID_LIST);
        syntaxStack.push(T_ID);
        syntaxStack.push(T_LEFT_PAREN);
        syntaxStack.push(T_ID);
        runCheck();
    }
    else{
        throw tokens.at(0)->toString();
    }
}
void ParserTest::testPred() {
    syntaxStack.pop();
    if(tokens.at(0)->getStyle() == TokenType::ID){
        //has the start of a scheme, add needed and begin parsing
        ///ID LEFT_PAREN parameter parameterList RIGHT_PAREN
        syntaxStack.push(T_RIGHT_PAREN);
        syntaxStack.push(PARAM_LIST);
        syntaxStack.push(PARAM);
        syntaxStack.push(T_LEFT_PAREN);
        syntaxStack.push(T_ID);
        runCheck();
    }
    else{
        throw tokens.at(0)->toString();
    }
}

void ParserTest::testPredList() {
    syntaxStack.pop();
    if(tokens.at(0)->getStyle() == TokenType::COMMA){
        //has the start of a scheme, add needed and begin parsing
        ///COMMA predicate predicateList | lambda
        syntaxStack.push(PRED_LIST);
        syntaxStack.push(PRED);
        syntaxStack.push(T_COMMA);
        runCheck();
    }
    else if(tokens.at(0)->getStyle() == TokenType::PERIOD){
        runCheck();
    }
    else{
        throw tokens.at(0)->toString();
    }
}
void ParserTest::testParamList() {
    syntaxStack.pop();
    if(tokens.at(0)->getStyle() == TokenType::COMMA){
        //has the start of a scheme, add needed and begin parsing
        ///COMMA parameter parameterList | lambda
        syntaxStack.push(PARAM_LIST);
        syntaxStack.push(PARAM);
        syntaxStack.push(T_COMMA);
        runCheck();
    }
    else if(tokens.at(0)->getStyle() == TokenType::RIGHT_PAREN){
        runCheck();
    }
    else{
        throw tokens.at(0)->toString();
    }
}

void ParserTest::testStringList() {
    syntaxStack.pop();
    if(tokens.at(0)->getStyle() == TokenType::COMMA){
        //has the start of a scheme, add needed and begin parsing
        ///COMMA STRING stringList | lambda
        syntaxStack.push(STRING_LIST);
        syntaxStack.push(T_STRING);
        syntaxStack.push(T_COMMA);
        runCheck();
    }
    else if(tokens.at(0)->getStyle() == TokenType::RIGHT_PAREN){
        runCheck();
    }
    else{
        throw tokens.at(0)->toString();
    }
}

void ParserTest::testIDList() {
    syntaxStack.pop();
    if(tokens.at(0)->getStyle() == TokenType::COMMA){
        //has the start of a scheme, add needed and begin parsing
        ///COMMA STRING stringList | lambda
        syntaxStack.push(ID_LIST);
        syntaxStack.push(T_ID);
        syntaxStack.push(T_COMMA);
        runCheck();
    }
    else if(tokens.at(0)->getStyle() == TokenType::RIGHT_PAREN){
        runCheck();
    }
    else{
        throw tokens.at(0)->toString();
    }
}

void ParserTest::testParam() {
    syntaxStack.pop();
    if(tokens.at(0)->getStyle() == TokenType::STRING){
        syntaxStack.push(T_STRING);
        runCheck();
    }
    else if(tokens.at(0)->getStyle() == TokenType::ID){
        syntaxStack.push(T_ID);
        runCheck();
    }
    else{
        throw tokens.at(0)->toString();
    }
}
