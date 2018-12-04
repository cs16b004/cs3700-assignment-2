%{#include<stdio.h>
#include<string.h>
int yylex();
int yyerror();
%}

%union{
  char *name;
  char *numval;
}
%token WHERE REL_OP NUM table create
%start query
%token <name>SLCT
%token <name>FRM
%token <name>COLNAM

%%
query: selectquery ';'{printf("Accept\n");};
	| createq ';' {printf("Accept\n");};

createq: create table TABLES ';'{printf("Accept\n");};

selectquery:     SLCT '*' FRM TABLES';'
		 | SLCT '*' FRM TABLES WHERE CONDITION ';'
		 ;

CONDITION: COLNAM REL_OP EXP ;

EXP:       COLNAM
	|  NUM
	|  EXP'+'EXP
	|  EXP'-'EXP
	|  EXP'*'EXP
	|  EXP'/'EXP
        ;

TABLES: COLNAM;
	

%%
int main(){
  yyparse();
  return 0;
}
int yyerror(){
  printf("Invalid\n");
  return 0;
}
