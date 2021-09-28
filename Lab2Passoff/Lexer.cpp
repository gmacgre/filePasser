#include "Lexer.h"


Lexer::Lexer() {
    CreateAutomata();
}

Lexer::~Lexer() {
    for(Automaton* a : automata){
        delete a;
    }
    for(Token* t : tokens){
        delete t;
    }
}

void Lexer::CreateAutomata() {
    automata.push_back(new ColonAutomaton());
    automata.push_back(new ColonDashAutomaton());
    automata.push_back(new Comma());
    automata.push_back(new Period());
    automata.push_back(new QuestionAuto());
    automata.push_back(new LeftParenAuto());
    automata.push_back(new RightParenAuto());
    automata.push_back(new MultiplyAuto());
    automata.push_back(new AddAuto());
    automata.push_back(new SchemesAuto());
    automata.push_back(new FactsAuto());
    automata.push_back(new RulesAuto());
    automata.push_back(new QueriesAuto());
    automata.push_back(new IdAuto());
    automata.push_back(new StringAuto());
    automata.push_back(new CommentAuto());
    automata.push_back(new BlockCommentAuto());
    automata.push_back(new UndefAuto());
}

void Lexer::Run(std::string& input) {
    int lineNumber = 1;
    while(!input.empty()){
        int maxRead = 0;
        unsigned maxAutomaton = 0;
        while(std::isspace(input[0])){
            if(input[0] == '\n') lineNumber++;
            input = input.substr(1, input.size() - 1);
        }
        for(unsigned i = 0; i < automata.size(); i++){
            int autoRead = automata.at(i)->Start(input);
            if(autoRead > maxRead){
                maxAutomaton = i;
                maxRead = autoRead;
            }
        }
        if(maxRead > 0){
            tokens.push_back(automata.at(maxAutomaton)->
                CreateToken(input.substr(0, maxRead), lineNumber));
            lineNumber += automata.at(maxAutomaton)->NewLinesRead();
            input = input.substr(maxRead);
        }
        else{
            if(!input.empty()) {
                tokens.push_back(new Token(TokenType::UNDEFINED, input.substr(0, 1), lineNumber));
                input = input.substr(1);
            }
        }

    }
    tokens.push_back(new Token(TokenType::END, "", lineNumber - 1));
    // TODO: convert this pseudo-code with the algorithm into actual C++ code
    /*
    set lineNumber to 1
    // While there are more characters to tokenize
    loop while input.size() > 0 {
        set maxRead to 0
        set maxAutomaton to the first automaton in automata

        // TODO: you need to handle whitespace inbetween tokens

        // Here is the "Parallel" part of the algorithm
        //   Each automaton runs with the same input
        foreach automaton in automata {
            inputRead = automaton.Start(input)
            if (inputRead > maxRead) {
                set maxRead to inputRead
                set maxAutomaton to automaton
            }
        }
        // Here is the "Max" part of the algorithm
        if maxRead > 0 {
            set newToken to maxAutomaton.CreateToken(...)
                increment lineNumber by maxAutomaton.NewLinesRead()
                add newToken to collection of all tokens
        }
        // No automaton accepted input
        // Create single character undefined token
        else {
            set maxRead to 1
                set newToken to a  new undefined Token
                (with first character of input)
                add newToken to collection of all tokens
        }
        // Update `input` by removing characters read to create Token
        remove maxRead characters from input
    }
    add end of file token to all tokens
    */
}
