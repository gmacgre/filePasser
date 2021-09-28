cmake_minimum_required(VERSION 3.16.3)
project(Lab1Lexer)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Werror")
set(CMAKE_CXX_STANDARD 14)

add_executable(Lab1Lexer main.cpp
        LexerAndLexerNodes/Lexer.cpp
        LexerAndLexerNodes/Lexer.h
        Token.cpp
        Token.h
        LexerAndLexerNodes/Automaton.h
        LexerAndLexerNodes/ColonAutomaton.cpp
        LexerAndLexerNodes/ColonAutomaton.h
        LexerAndLexerNodes/ColonDashAutomaton.cpp
        LexerAndLexerNodes/ColonDashAutomaton.h
        LexerAndLexerNodes/Comma.cpp
        LexerAndLexerNodes/Comma.h
        LexerAndLexerNodes/Period.cpp
        LexerAndLexerNodes/Period.h
        LexerAndLexerNodes/QuestionAuto.cpp
        LexerAndLexerNodes/QuestionAuto.h
        LexerAndLexerNodes/LeftParenAuto.cpp
        LexerAndLexerNodes/LeftParenAuto.h
        LexerAndLexerNodes/RightParenAuto.cpp
        LexerAndLexerNodes/RightParenAuto.h
        LexerAndLexerNodes/MultiplyAuto.cpp
        LexerAndLexerNodes/MultiplyAuto.h
        LexerAndLexerNodes/AddAuto.cpp
        LexerAndLexerNodes/AddAuto.h
        LexerAndLexerNodes/SchemesAuto.cpp
        LexerAndLexerNodes/SchemesAuto.h
        LexerAndLexerNodes/FactsAuto.cpp
        LexerAndLexerNodes/FactsAuto.h
        LexerAndLexerNodes/RulesAuto.cpp
        LexerAndLexerNodes/RulesAuto.h
        LexerAndLexerNodes/QueriesAuto.cpp
        LexerAndLexerNodes/QueriesAuto.h
        LexerAndLexerNodes/IdAuto.cpp
        LexerAndLexerNodes/IdAuto.h
        LexerAndLexerNodes/StringAuto.cpp
        LexerAndLexerNodes/StringAuto.h
        LexerAndLexerNodes/CommentAuto.cpp
        LexerAndLexerNodes/CommentAuto.h
        LexerAndLexerNodes/EndOfFileAuto.cpp
        LexerAndLexerNodes/EndOfFileAuto.h
        LexerAndLexerNodes/BlockCommentAuto.cpp
        LexerAndLexerNodes/BlockCommentAuto.h
        LexerAndLexerNodes/UndefAuto.cpp
        LexerAndLexerNodes/UndefAuto.h
        ParserAndParseNodes/ParserTest.cpp
        ParserAndParseNodes/ParserTest.h DataLogProgram.cpp DataLogProgram.h Rule.cpp Rule.h Predicate.cpp Predicate.h Parameter.cpp Parameter.h)
