%{
#include <stdio.h>
%}

ALPHA [a-zA-Z]

%%

{ALPHA}+ 	                    {printf("STRING %s\n", yytext);}
" "                             {printf("SPACE\n");}

       
":1234:"		                {printf("INTEGER\n");}
":abcd:"                        {printf("STRING\n");}
":card_index:"                  {printf("ARRAY\n");}


":zero:"                         {printf("ZERO\n");}
":one:"                         {printf("ONE\n");}
":two:"                         {printf("TWO\n");}
":three:"                       {printf("THREE\n");}
":four:"                        {printf("FOUR\n");}
":five:"                        {printf("FIVE\n");}
":six:"                         {printf("SIX\n");}
":seven:"                       {printf("SEVEN\n");}
":eight:"                       {printf("EIGHT\n");}
":nine:"                        {printf("NINE\n");}



":heavy_plus_sign:"             {printf("PLUS\n");}
":heavy_minus_sign:"            {printf("MINUS\n");}
":heavy_multiplication_x:"      {printf("MULTIPLICATION\n");}
":heavy_division_sign:"         {printf("DIVISION\n");}
":point_right:"                 {printf("EQUAL\n");}
":exclamation:"                 {printf("NOT\n");}



":symbols:"                     {printf("FUNCTIONS\n");}
":arrow_forward:"               {printf("GREATER_THAN\n");}
":arrow_backward:"              {printf("LESS_THAN\n");}
":vertical_traffic_light:"      {printf("IF\n");}
":traffic_light:"               {printf("ELSE\n");}
":repeat:"                      {printf("WHILE\n");}




":desktop_computer:"             {printf("READ\n");}
":keyboard:"                     {printf("WRITE\n");}
":pencil2:"                      {printf("COMMENT\n");}





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
