//
// Created by Malcolm MacGregor on 9/27/2021.
//

#ifndef LAB1LEXER_DATALOGPROGRAM_H
#define LAB1LEXER_DATALOGPROGRAM_H


#include <vector>
#include <set>
#include "Parameter.h"
#include "Predicate.h"
#include "Rule.h"
#include "ParserTest.h"

class DataLogProgram {
public:
    DataLogProgram(ParserTest* p){
        rules = p->getRules();
        schemes = p->getSchemes();
        facts = p->getFacts();
        queries = p->getQueries();
        domain = p->getDomain();
    }
    ~DataLogProgram(){
        for(Rule* r : rules){
            delete r;
        }
        for(Predicate* r : schemes){
            delete r;
        }
        for(Predicate* r : facts){
            delete r;
        }
        for(Predicate* r : queries){
            delete r;
        }
    }
    std::string toString() const {
        std::ostringstream toOut;
        toOut << "Schemes(" << schemes.size() << "):" << std::endl;
        for(Predicate* s : schemes){
            toOut << "  " << *s << std::endl;
        }
        toOut << "Facts(" << facts.size() << "):" << std::endl;
        for(Predicate* s : facts){
            toOut << "  " << *s << "." << std::endl;
        }
        toOut << "Rules(" << rules.size() << "):" << std::endl;
        for(Rule* r : rules){
            toOut << "  " << *r << "." << std::endl;
        }
        toOut << "Queries(" << queries.size() << "):" << std::endl;
        for(Predicate* s : queries){
            toOut << "  " << *s << "?" <<  std::endl;
        }
        toOut << "Domain(" << domain.size() << "):" << std::endl;
        for(const std::string& s : domain){
            toOut << "  " <<  s << std::endl;
        }
        return toOut.str();
    }

    friend std::ostream& operator<<(std::ostream& os, DataLogProgram& d){
        os << d.toString();
        return os;
    }

private:
    std::vector<Rule*> rules;
    std::vector<Predicate*> schemes;
    std::vector<Predicate*> facts;
    std::vector<Predicate*> queries;
    std::set<std::string> domain;
};


#endif //LAB1LEXER_DATALOGPROGRAM_H
