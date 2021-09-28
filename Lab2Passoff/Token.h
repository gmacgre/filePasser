#ifndef TOKEN_H
#define TOKEN_H
#include <string>
#include <iostream>
#include <sstream>

enum class TokenType {
    COLON,
    COLON_DASH,
    COMMA,
    PERIOD,
    Q_MARK,
    LEFT_PAREN,
    RIGHT_PAREN,
    MULTIPLY,
    ADD,
    SCHEMES,
    FACTS,
    RULES,
    QUERIES,
    ID,
    STRING,
    COMMENT,
    END,
    UNDEFINED
};

class Token
{
private:
    TokenType style;
    std::string content;
    int tokenLine;



public:
    Token(TokenType type, std::string description, int line);
    Token(Token const &o);

    std::string toString(){
        std::ostringstream toOut;
        toOut << "(" << typeToStr() << ",\"" << content << "\"," << tokenLine << ")";
        return toOut.str();
    }
    friend std::ostream& operator<<(std::ostream& os, Token& t){
        os << t.toString();
        return os;
    }
    TokenType getStyle() const { return style; }
    std::string getCont() const { return content; }
    int getLine() const { return tokenLine; }
    std::string typeToStr(){
        switch(style){
            case TokenType::COLON: return "COLON";
            case TokenType::COLON_DASH: return "COLON_DASH";
            case TokenType::COMMA: return "COMMA";
            case TokenType::PERIOD: return "PERIOD";
            case TokenType::Q_MARK: return "Q_MARK";
            case TokenType::LEFT_PAREN: return "LEFT_PAREN";
            case TokenType::RIGHT_PAREN: return "RIGHT_PAREN";
            case TokenType::MULTIPLY: return "MULTIPLY";
            case TokenType::ADD: return "ADD";
            case TokenType::SCHEMES: return "SCHEMES";
            case TokenType::FACTS: return "FACTS";
            case TokenType::RULES: return "RULES";
            case TokenType::QUERIES: return "QUERIES";
            case TokenType::ID: return "ID";
            case TokenType::STRING: return "STRING";
            case TokenType::COMMENT: return "COMMENT";
            case TokenType::UNDEFINED: return "UNDEFINED";
            case TokenType::END: return "EOF";
        }
        return "ERR: UNKNOWN TOKEN";
    }
};

#endif // TOKEN_H

