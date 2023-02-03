%{
#include <stdio.h>
int row = 0, col = 0;
%}

ALPHA [a-zA-Z]
INTEGER (":zero:"|":one:"|":two:"|":three:"|":four:"|":five:"|":six:"|":seven:"|":eight:"|":nine:")
NUM [0-9]

%%

":pencil2:"([^\n])*             {col += strlen(yytext);}
{ALPHA}+ 	                {printf("VAR %s\n", yytext); col += strlen(yytext);}
{INTEGER}+                      {printf("INT %d\n", toInt(yytext)); col += strlen(yytext);}
{NUM}+                          {printf("INT %s\n", yytext); col += strlen(yytext);}
({ALPHA}|{NUM})+		{printf("Invalid variable name %s at row: %d, col: %d\n", yytext, row, col); return;}

" "				{col++;}
"\t"				{col+=strlen(yytext);}
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
";"                         	{printf("SEMICOLON\n"); col++;}
","				{printf("COMMA\n"); col++;}


.				{printf("ERROR: unrecognized token, row %d, col%d\n", row, col); return;}

%%

int toInt(char* input) {
	int toReturn = 0;

	char currNum[5];

	int reading = 0;
	int toMult = 0;
	int currInd = 0;
	size_t i = 0;

	for (; i < strlen(input); i++) {
		if (input[i] == ':') {
			if (!reading) {
				reading = 1;
				toMult = 0;
				currInd = 0;
				size_t j = 0;
				for (; j < 5; j++) currNum[j] = '\0';
			}
			else {
				reading = 0;
				if (!strcmp(currNum, "zero")) {
					toMult = 0;
				}
				else if (!strcmp(currNum, "one")) {
					toMult = 1;
				}
				else if (!strcmp(currNum, "two")) {
					toMult = 2;
				}
				else if (!strcmp(currNum, "three")) {
					toMult = 3;
				}
				else if (!strcmp(currNum, "four")) {
					toMult = 4;
				}
				else if (!strcmp(currNum, "five")) {
                                        toMult = 5;
                                }
				else if (!strcmp(currNum, "six")) {
                                        toMult = 6;
                                }
				else if (!strcmp(currNum, "seven")) {
                                        toMult = 7;
                                }
				else if (!strcmp(currNum, "eight")) {
                                        toMult = 8;
                                }
				else if (!strcmp(currNum, "nine")) {
                                        toMult = 9;
                                }
				toReturn *= 10;
				toReturn += toMult;
			}
			continue;
		}
		else {
			currNum[currInd++] = input[i];
		}
	} 
	return toReturn;	
}

main(int argc, char *argv[]){
	yyin = stdin; //FOR PART 2
	//printf("INTEGER: %d\n");
	printf("Crtl+D to quit\n");
	
	yyin = fopen(argv[1], "r");
	yylex();
	fclose(yyin);


}
