#include "Token.h"

#include <utility>

Token::Token(TokenType type, std::string description, int line) : style(type), content(std::move(description)), tokenLine(line) {
}

Token::Token(Token const &o) : style(o.getStyle()), content(o.getCont()), tokenLine(o.getLine()){

}
