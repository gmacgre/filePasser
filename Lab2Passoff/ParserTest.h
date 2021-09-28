//
// Created by Malcolm MacGregor on 9/25/2021.
//

#ifndef LAB1LEXER_PARSERTEST_H
#define LAB1LEXER_PARSERTEST_H


#include <stack>
#include <set>
#include "Lexer.h"
#include "Predicate.h"
#include "Rule.h"

class ParserTest {
public:
    explicit ParserTest(Lexer* passer) : tokens(passer->getTokens()), syntaxStack() {
        std::vector<Token*> deepCopy;
        for(Token* t : tokens){
            if(t->getStyle() != TokenType::COMMENT) deepCopy.push_back(new Token(*t));
        }
        tokens = deepCopy;
    }
    ~ParserTest(){
        for(Token* t : tokens){
            delete t;
        }
    }

    void runSyntax();
    void parseFull();
    void runCheck();

    //now we have all the functions we call with time
    void testSchemeList();
    void testFactList();
    void testRuleList();
    void testQueryList();
    void testScheme();
    void testFact();
    void testRule();
    void testQuery();
    void testHeadPred();
    void testPred();
    void testPredList();
    void testParamList();
    void testStringList();
    void testIDList();
    void testParam();

    //functions to divide the program up into proper bits
    std::vector<Predicate*> getSchemes(){
        std::vector<Predicate*> toRet;
        unsigned startPoint = 0, endPoint = 0;
        for(unsigned i = 0; i < tokens.size(); i++){
            if(tokens.at(i)->getStyle() == TokenType::SCHEMES) startPoint = i + 2;
            else if(tokens.at(i)->getStyle() == TokenType::FACTS) endPoint = i;
            if(endPoint != 0) break;
        }
        //we now have SCHEMES TO FACTS

        while (startPoint != endPoint){
            auto* newPred = new Predicate(tokens.at(startPoint)->getCont());
            startPoint += 2; //skipping the opening left bracket
            while(tokens.at(startPoint)->getStyle() == TokenType::ID){
                newPred->addParam(new Parameter(tokens.at(startPoint)->getCont()));
                startPoint += 2;
                if(tokens.at(startPoint - 1)->getStyle() == TokenType::RIGHT_PAREN) break;
            }
            toRet.push_back(newPred);
            //if it is a
        }
        return toRet;
    }
    std::vector<Predicate*> getFacts(){
        std::vector<Predicate*> toRet;
        unsigned startPoint = 0, endPoint = 0;
        for(unsigned i = 0; i < tokens.size(); i++){
            if(tokens.at(i)->getStyle() == TokenType::FACTS) startPoint = i + 2;
            else if(tokens.at(i)->getStyle() == TokenType::RULES) endPoint = i;
            if(endPoint != 0) break;
        }
        //we now have FACTS TO RULES

        while (startPoint != endPoint){
            auto* newPred = new Predicate(tokens.at(startPoint)->getCont());
            startPoint += 2; //skipping the opening left bracket
            while(tokens.at(startPoint)->getStyle() == TokenType::STRING){
                newPred->addParam(new Parameter(tokens.at(startPoint)->getCont()));
                startPoint += 2;
                if(tokens.at(startPoint - 1)->getStyle() == TokenType::RIGHT_PAREN) break;
            }
            toRet.push_back(newPred);
            startPoint++;
        }
        return toRet;
    }
    std::vector<Predicate*> getQueries(){
        std::vector<Predicate*> toRet;
        unsigned startPoint = 0, endPoint = 0;
        for(unsigned i = 0; i < tokens.size(); i++){
            if(tokens.at(i)->getStyle() == TokenType::QUERIES) startPoint = i + 2;
            else if(tokens.at(i)->getStyle() == TokenType::END) endPoint = i;
            if(endPoint != 0) break;
        }
        //we now have QUERIES TO EOF

        while (startPoint != endPoint){
            auto* newPred = new Predicate(tokens.at(startPoint)->getCont());
            startPoint += 2; //skipping the opening left bracket
            while(tokens.at(startPoint)->getStyle() == TokenType::STRING || tokens.at(startPoint)->getStyle() == TokenType::ID){
                newPred->addParam(new Parameter(tokens.at(startPoint)->getCont()));
                startPoint += 2;
                if(tokens.at(startPoint - 1)->getStyle() == TokenType::RIGHT_PAREN) break;
            }
            toRet.push_back(newPred);
            startPoint++;
        }
        return toRet;
    }
    std::vector<Rule*> getRules() {
        std::vector<Rule*> toRet;
        unsigned startPoint = 0, endPoint = 0;
        for(unsigned i = 0; i < tokens.size(); i++){
            if(tokens.at(i)->getStyle() == TokenType::RULES) startPoint = i + 2;
            else if(tokens.at(i)->getStyle() == TokenType::QUERIES) endPoint = i;
            if(endPoint != 0) break;
        }
        //we now have RULES TO QUERIES
        while (startPoint != endPoint){
            //first, parse the head predicate
            auto* newPred = new Predicate(tokens.at(startPoint)->getCont());
            startPoint += 2; //skipping the opening left bracket
            while(tokens.at(startPoint)->getStyle() == TokenType::ID){
                newPred->addParam(new Parameter(tokens.at(startPoint)->getCont()));
                startPoint += 2;
                if(tokens.at(startPoint - 1)->getStyle() == TokenType::RIGHT_PAREN) break;
            }
            auto* newRule = new Rule(newPred);
            //now we parse the colon-D and the predicates
            startPoint++;
            while(tokens.at(startPoint)->getStyle() != TokenType::PERIOD){
                auto* newBod = new Predicate(tokens.at(startPoint)->getCont());
                startPoint += 2;
                while(tokens.at(startPoint)->getStyle() == TokenType::ID || tokens.at(startPoint)->getStyle() == TokenType::STRING){
                    newBod->addParam(new Parameter(tokens.at(startPoint)->getCont()));
                    startPoint += 2;
                    if(tokens.at(startPoint - 1)->getStyle() == TokenType::RIGHT_PAREN) break;
                }
                newRule->addPred(newBod);
                if(tokens.at(startPoint)->getStyle() == TokenType::COMMA) startPoint++; //avoiding a comma in between predicates.
            }
            toRet.push_back(newRule);
            startPoint++;
        }

        return toRet;
    }
    std::set<std::string> getDomain(){
        std::set<std::string> toRet;
        unsigned startPoint = 0, endPoint = 0;
        for(unsigned i = 0; i < tokens.size(); i++){
            if(tokens.at(i)->getStyle() == TokenType::FACTS) startPoint = i + 2;
            else if(tokens.at(i)->getStyle() == TokenType::RULES) endPoint = i;
            if(endPoint != 0) break;
        }
        //we now have FACTS TO RULES

        while (startPoint != endPoint){
            if(tokens.at(startPoint)->getStyle() == TokenType::STRING) toRet.insert(tokens.at(startPoint)->getCont());
            startPoint++;
        }
        return toRet;
    }

private:
    enum allTerminals { DATALOG_PROG,
            SCHEME_LIST, FACT_LIST, RULE_LIST, QUERY_LIST,
            SCHEME, FACT, RULE, QUERY,
            HEAD_PRED, PRED, PRED_LIST, PARAM_LIST,
            STRING_LIST, ID_LIST, PARAM,
            ///now getting to the point where we can start doing terminals
            T_SCHEMES, T_FACTS, T_RULES, T_QUERIES,
            T_EOF, T_COLON, T_PERIOD, T_COLON_DASH, T_COMMA,
            T_ID, T_RIGHT_PAREN, T_LEFT_PAREN, T_STRING, T_QMARK};
    std::vector<Token*> tokens;
    std::stack<allTerminals> syntaxStack;
};


#endif //LAB1LEXER_PARSERTEST_H
