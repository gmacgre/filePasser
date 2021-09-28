#ifndef LEXER_H
#define LEXER_H
#include <vector>
#include "Automaton.h"
#include "Token.h"
#include "ColonAutomaton.h"
#include "ColonDashAutomaton.h"
#include "Comma.h"
#include "Period.h"
#include "QuestionAuto.h"
#include "LeftParenAuto.h"
#include "RightParenAuto.h"
#include "MultiplyAuto.h"
#include "AddAuto.h"
#include "SchemesAuto.h"
#include "FactsAuto.h"
#include "RulesAuto.h"
#include "QueriesAuto.h"
#include "IdAuto.h"
#include "StringAuto.h"
#include "CommentAuto.h"
#include "BlockCommentAuto.h"
#include "EndOfFileAuto.h"
#include "UndefAuto.h"

class Lexer
{
private:
    std::vector<Automaton*> automata;
    std::vector<Token*> tokens;

    void CreateAutomata();


public:
    Lexer();
    ~Lexer();

    void Run(std::string& input);

    friend std::ostream& operator<<(std::ostream& os, Lexer& l){
        os << l.toString();
        return os;
    }
    std::string toString(){
        std::ostringstream toOut;
        for(Token* token : tokens){
            toOut << *token << std::endl;
        }
        toOut << "Total Tokens = " << tokens.size();
        return toOut.str();
    }
    std::vector<Token*> getTokens(){ return tokens; }
};

#endif // LEXER_H

