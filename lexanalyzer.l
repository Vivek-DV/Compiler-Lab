%{
	#include<stdio.h>
	int flag=0;
	int line=1;
	int sl=1;
	FILE* fp;
%}
DIGIT [0-9]
ALPHA [a-zA-Z]
WS [ \t]
DQ ["]
%%
{WS}+ {}
"\n" {line++;}
";" {printf("%d\t;\tSemicolon\t%d\n",sl,line);sl++;}
"+"|"-"|"*"|"/" {printf("%d\t%s\tArithmetic_Op\t%d\n",sl,yytext,line);sl++;}
"<"|">"|"<="|">="|"!"|"!="|"==" {fprintf(fp,"%d\t%s\tRelational_Op\t%d\n",sl,yytext,line);sl++;}
"=" {fprintf(fp,"%d\t%s\tAssignment_Op\t%d\n",sl,yytext,line);sl++;}
"void"|"main"|"if"|"else"|"if else"|"while"|"int"|"include"|"<stdio.h>" {fprintf(fp,"%d\t%s\tKeywords\t%d\n",sl,yytext,line);sl++;}
{ALPHA}({ALPHA}+{DIGIT})* {fprintf(fp,"%d\t%s\tIdentifiers\t%d\n",sl,yytext,line);sl++;}
{DIGIT}+"."{DIGIT}+ {fprintf(fp,"%d\t%s\tFloatingpoint_number\t%d\n",sl,yytext,line);sl++;}
{DIGIT}+ {fprintf(fp,"%d\t%s\tNumber\t%d\n",sl,yytext,line);sl++;}
"{"|"["|"(" {fprintf(fp,"%d\t%s\tOpening_Bracket\t%d\n",sl,yytext,line);sl++;}
"}"|"]"|")" {fprintf(fp,"%d\t%s\tClosing_Bracket\t%d\n",sl,yytext,line);sl++;}
"#"|"%" {fprintf(fp,"%d\t%s\tSpecial_Op\t%d\n",sl,yytext,line);sl++;}
. {fprintf(fp,"%d\t%s\tUnrecognized%d\n",sl,yytext,line);sl++;}
%%
void main(int argc, char* argv[])
{

	yyin=fopen(argv[1],"r");
	fp=fopen(argv[2],"w");
	yylex();
}
int yywrap()
{
	return 1;
}
