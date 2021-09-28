#include <fstream>
#include "Lexer.h"
#include "ParserTest.h"
#include "DataLogProgram.h"

using std::cout;
using std::endl;

int main(int argc, char* argv[]) {

    auto* lexer = new Lexer();
    char* tester = argv[1];
    *tester = *tester;
    ///args 0- location of program 1- 1st input 2- 2nd input

    if(argc == 1){
        cout << "No file given as argument" << endl;
        delete lexer;
        return 0;
    }
    std::ostringstream file;
    std::ifstream in(argv[1]);
    std::string line;
    while(!in.eof()){
        std::getline(in, line);
        line.append("\n");
        file << line;
    }
    line = file.str();
    lexer->Run(line);
    auto* p = new ParserTest(lexer);
    delete lexer;
    try{
        p->runSyntax();
        cout << "Success!" << endl;
        auto* program = new DataLogProgram(p);
        delete p;
        cout << *program;
    }
    catch(char const* e){
        cout << "Failure!" << endl;
        cout << "  " << e << endl;
    }
    catch(std::string &e){
        cout << "Failure!" << endl;
        cout << "  " << e << endl;
    }



    return 0;
}
