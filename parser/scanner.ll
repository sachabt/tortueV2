%{

#include "scanner.hh"
#include <cstdlib>

#define YY_NO_UNISTD_H

using token = yy::Parser::token;

#undef  YY_DECL
#define YY_DECL int Scanner::yylex( yy::Parser::semantic_type * const lval, yy::Parser::location_type *loc )

/* update location on matching */
#define YY_USER_ACTION loc->step(); loc->columns(yyleng);

%}

%option c++
%option yyclass="Scanner"
%option noyywrap

%%

%{
    yylval = lval;
%}


fin return token::END;

--.* {
    return token::COMMENT;
}

"avance" {
    return token::AVANCE;
}

"recule" {
    return token::RECULE;
}

"saute" {
    return token::SAUTE;
}

"tourne" {
    return token::TOURNE;
}

"à droite" {
    yylval->build<int>(1);
    return token::SENS;
}

"à gauche" {
    yylval->build<int>(-1);
    return token::SENS;
}

[0-9]+      {    
    yylval->build<float>(std::atof(yytext));
    return token::NUMBER;
}

@[0-9]+   {
    std::string temp = YYText();
    yylval->build<int>(std::stoi(temp.substr(1)));
    return token::IdTortue;
}

"\n"          {
    loc->lines();
    return token::NL;
}


"+" return '+';
"*" return '*';
"-" return '-';
"/" return '/';
"(" return '(';
")" return ')';
"=" return '=';

"fois" return token::FOIS;


%%
