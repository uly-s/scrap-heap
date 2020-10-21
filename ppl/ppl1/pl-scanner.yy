%{ 

#include "tokens.h"
# undef yywrap
# define yywrap() 1



#undef YY_DECL
#define YY_DECL int yylex()
YY_DECL;


// Code run each time a pattern is matched.
#undef  YY_USER_ACTION  
# define YY_USER_ACTION  {}



%}

%option yylineno
%option noyywrap 

DIGIT [0-9] 
ALPHA [a-zA-Z]
ID ([_]+[_0-9a-zA-Z]*[a-zA-Z]+[_0-9a-zA-Z]*)|([a-zA-Z]+[_0-9a-zA-Z]+)
FLOAT ("+"[0-9]+|"-"[0-9]+|[0-9]+)"."[0-9]+
%%





\/\/.*$   
[ \t]+						
[\n]+							



";"							  { 
										return ';'; 
                  }

"="							  { 
										return '='; 
                  }

"main"					  {  
										return K_MAIN; 
                  }
"+"						    {
										return OP_ADD;
								  }
"-"						    {
										return OP_SUB;
								  }
"*"						    {
										return OP_MUL;
									}
"/"						    {
										return OP_DIV;
								  }
"<"								{
										return OP_LT;
									}
">"								{
										return OP_GT;
									}
"<="								{
										return OP_LEQ;
									}
">="							{
										return OP_GEQ;
									}																											
"=="							{
										return OP_EQ;
									}
"!="							{
										return OP_INEQ;
									}
"foreach" {
	return K_FOREACH;
}
"while" {
	return K_WHILE;
}
"print" {
	return K_PRINT;
}
"repeat" {
	return K_REPEAT;
}
"until" {
	return K_UNTIL;
}
"begin" {
	return K_BEGIN;
}
"end" {
	return K_END;
}
"if" {
	return K_IF;
}
"then" {
	return K_THEN;
}
"integer" {
	return K_INTEGER;
}
"float" {
	return K_FLOAT;
}
{FLOAT} {
	return L_FLOAT;
}
{DIGIT}+					{ 
										return L_INTEGER;
									}


{ID} { 
									return T_ID;
							  }

<<EOF>>						{ return T_EOF ; }
.									{ printf ("Unexpected character\n"); exit (1); }





%%
