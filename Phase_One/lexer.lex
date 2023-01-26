%{
#include <stdio.h>
%}

ALPHA [a-zA-Z]
INTEGER (":zero:"|":one:"|":two:"|":three:"|":four:"|":five:"|":six:"|":seven:"|":eight:"|":nine:")
NUM [0-9]

%%

":pencil2:"({ALPHA}|\ )+           {printf("Comment %s\n", yytext);}
{ALPHA}+ 	                {printf("VAR %s\n", yytext);}
{INTEGER}+                      {printf("INT %s\n", yytext);}
{NUM}+                          {printf("INT %s\n", yytext);}
" "
"\n"
       
":1234:"		        {printf("INTEGER\n");}
":abcd:"                        {printf("STRING\n");}
":card_index:"                  {printf("ARRAY\n");}


":heavy_plus_sign:"             {printf("PLUS\n");}
":heavy_minus_sign:"            {printf("MINUS\n");}
":heavy_multiplication_x:"      {printf("MULTIPLICATION\n");}
":heavy_division_sign:"         {printf("DIVISION\n");}
":point_right:"                 {printf("EQUAL\n");}
":exclamation:"                 {printf("NOT\n");}



":symbols:"                     {printf("FUNCTION\n");}
":arrow_forward:"               {printf("GREATER_THAN\n");}
":arrow_backward:"              {printf("LESS_THAN\n");}
":vertical_traffic_light:"      {printf("IF\n");}
":traffic_light:"               {printf("ELSE\n");}
":repeat:"                      {printf("WHILE\n");}



":desktop_computer:"             {printf("READ\n");}
":keyboard:"                     {printf("WRITE\n");}



"{"                         {printf("LEFT_CURLY\n");}
"}"                         {printf("RIGHT_CURLY\n");}
"["                         {printf("LEFT_SQUARE\n");}
"]"                         {printf("RIGHT_SQUARE\n");}
"("                         {printf("LEFT_PARENTHESIS\n");}
")"                         {printf("RIGHT_PARENTHESIS\n");}
":"                         {printf("COLON\n");}
";"                         {printf("SEMICOLON\n");}

.		{printf("ERROR: unrecognized token"); return;}

%%

main(int argc, char *argv[]){
	yyin = stdin; //FOR PART 2
	//printf("INTEGER: %d\n");
	printf("Crtl+D to quit\n");
	
	yyin = fopen(argv[1], "r");
	yylex();
	fclose(yyin);


}
