%{
#include <stdio.h>
int row = 0, col = 0;
%}

ALPHA [a-zA-Z]
INTEGER (":zero:"|":one:"|":two:"|":three:"|":four:"|":five:"|":six:"|":seven:"|":eight:"|":nine:")
NUM [0-9]

%%

":pencil2:"([^\n])+        {printf("Comment %s\n", yytext); row++; col = 0;}
{ALPHA}+ 	                {printf("VAR %s\n", yytext); col += strlen(yytext);}
{INTEGER}+                      {printf("INT %s\n", yytext); col += strlen(yytext);}
{NUM}+                          {printf("INT %s\n", yytext); col += strlen(yytext);}
" "				{col++;}
"\n"				{row++; col = 0;}

       
":1234:"		        {printf("INTEGER\n"); col += strlen(yytext);}
":abcd:"                        {printf("STRING\n"); col += strlen(yytext);}
":card_index:"                  {printf("ARRAY\n"); col += strlen(yytext);}


":heavy_plus_sign:"             {printf("PLUS\n"); col += strlen(yytext);}
":heavy_minus_sign:"            {printf("MINUS\n"); col += strlen(yytext);}
":heavy_multiplication_x:"      {printf("MULTIPLICATION\n"); col += strlen(yytext);}
":heavy_division_sign:"         {printf("DIVISION\n"); col += strlen(yytext);}
":point_right:"                 {printf("EQUAL\n"); col += strlen(yytext);}
":exclamation:"                 {printf("NOT\n"); col += strlen(yytext);} 


":symbols:"                     {printf("FUNCTION\n"); col += strlen(yytext);}
":arrow_forward:"               {printf("GREATER_THAN\n"); col += strlen(yytext);}
":arrow_backward:"              {printf("LESS_THAN\n"); col += strlen(yytext);}
":vertical_traffic_light:"      {printf("IF\n"); col += strlen(yytext);}
":traffic_light:"               {printf("ELSE\n"); col += strlen(yytext);}
":repeat:"                      {printf("WHILE\n"); col += strlen(yytext);}


":desktop_computer:"            {printf("READ\n"); col += strlen(yytext);}
":keyboard:"                    {printf("WRITE\n"); col += strlen(yytext);}


"{"                             {printf("LEFT_CURLY\n"); col++;}
"}"                         	{printf("RIGHT_CURLY\n"); col++;}
"["                         	{printf("LEFT_SQUARE\n"); col++;}
"]"                         	{printf("RIGHT_SQUARE\n"); col++;}
"("                         	{printf("LEFT_PARENTHESIS\n"); col++;}
")"                         	{printf("RIGHT_PARENTHESIS\n"); col++;}
":"                         	{printf("COLON\n"); col++;}
";"                         	{printf("SEMICOLON\n"); col++;}
","				{printf("COMMA\n"); col++;}


.				{printf("ERROR: unrecognized token"); return;}

%%

main(int argc, char *argv[]){
	yyin = stdin; //FOR PART 2
	//printf("INTEGER: %d\n");
	printf("Crtl+D to quit\n");
	
	yyin = fopen(argv[1], "r");
	yylex();
	fclose(yyin);


}
