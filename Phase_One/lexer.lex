%{
#include "y.tab.h"
int row = 0, col = 0;
char* toInt(char*);
%}

ALPHA [a-zA-Z]
INTEGER (":zero:"|":one:"|":two:"|":three:"|":four:"|":five:"|":six:"|":seven:"|":eight:"|":nine:")
NUM [0-9]

%%

":pencil2:"([^\n])*             {col += strlen(yytext);}
{ALPHA}+ 	               	 	{yylval.name = strdup(yytext); col += strlen(yytext); return VAR;}
{INTEGER}+                      {yylval.name = toInt(yytext); col += strlen(yytext); return INT;}


{NUM}+                          {printf("INT %s\n", yytext); col += strlen(yytext);}
({ALPHA}|{NUM})+				{printf("Invalid variable name %s at row: %d, col: %d\n", yytext, row, col); exit(0);}

" "								{col++;}
"\t"							{col+=strlen(yytext);}
"\n"							{row++; col = 0;}

       
":1234:"		        		{col += strlen(yytext); return INTEGER;}
":abcd:"                        {col += strlen(yytext); return STRING;}
":card_index:"                  {col += strlen(yytext); return ARRAY;}


":heavy_plus_sign:"             {col += strlen(yytext); return '+';}
":heavy_minus_sign:"            {col += strlen(yytext); return '-';}
":heavy_multiplication_x:"      {col += strlen(yytext); return '*';}
":heavy_division_sign:"         {col += strlen(yytext); return '/';}
":point_right:"                 {col += strlen(yytext); return '=';}
":exclamation:"                 {col += strlen(yytext); return '!';} 


":symbols:"                     {col += strlen(yytext); return FUNCTION;}
":arrow_forward:"               {col += strlen(yytext); return '>';}
":arrow_backward:"              {col += strlen(yytext); return '<';}
":vertical_traffic_light:"      {col += strlen(yytext); return IF;}
":vertical_traffic_light::traffic_light:"               {col += strlen(yytext); return ELSEIF;}
":traffic_light:"		{col += strlen(yytext); return ELSE;}
":repeat:"                      {col += strlen(yytext); return WHILE;}


":desktop_computer:"            {col += strlen(yytext); return WRITE;}
":keyboard:"                    {col += strlen(yytext); return READ;}


"{"                             {col++; return '{';}
"}"                         	{col++; return '}';}
"["                         	{col++; return '[';}
"]"                         	{col++; return ']';}
"("                         	{col++; return '(';}
")"                         	{col++; return ')';}
";"                         	{col++; return ';';}
","				{col++; return ',';}

":arrow_forward::point_right:"  {col+=strlen(yytext); return GTE;}
":arrow_backward::point_right:" {col+=strlen(yytext); return LTE;}
":point_right::point_right:"    {col+=strlen(yytext); return ISEQ;}
":exclamation::point_right:"    {col+=strlen(yytext); return NOTEQ;}

":chains:"			{col+=strlen(yytext); return AND;}
":question:"			{col+=strlen(yytext); return OR;}
":athletic_shoe:"		{col+=strlen(yytext); return RETURN;}

.								{printf("ERROR: unrecognized token, row %d, col%d\n", row, col); return -1;}

%%



char* toInt(char* input) {
	char* toReturn = new char[32];
	int retInd = 0;

	char currNum[6];
	currNum[5] = '\0';

	int reading = 0;
	int currInd = 0;
	size_t i = 0;

	for (; i < strlen(input); i++) {
		if (input[i] == ':') {
			if (!reading) {
				reading = 1;
				currInd = 0;
				size_t j = 0;
				for (; j < 5; j++) currNum[j] = '\0';
			}
			else {
				reading = 0;
				if (!strcmp(currNum, "zero")) {
					toReturn[retInd++] = '0';
				}
				else if (!strcmp(currNum, "one")) {
					toReturn[retInd++] = '1';
				}
				else if (!strcmp(currNum, "two")) {
					toReturn[retInd++] = '2';
				}
				else if (!strcmp(currNum, "three")) {
					toReturn[retInd++] = '3';
				}
				else if (!strcmp(currNum, "four")) {
					toReturn[retInd++] = '4';
				}
				else if (!strcmp(currNum, "five")) {
                                        toReturn[retInd++] = '5';
                                }
				else if (!strcmp(currNum, "six")) {
                                        toReturn[retInd++] = '6';
				}
				else if (!strcmp(currNum, "seven")) {
                                        toReturn[retInd++] = '7';
                                }
				else if (!strcmp(currNum, "eight")) {
                                        toReturn[retInd++] = '8';
                                }
				else if (!strcmp(currNum, "nine")) {
                                        toReturn[retInd++] = '9';
                                }
			}
			continue;
		}
		else {
			currNum[currInd++] = input[i];
		}
	}
	toReturn[retInd] = '\0'; 
	return toReturn;	
}

//main(int argc, char *argv[]){
//	yyin = stdin; //FOR PART 2
//	//printf("INTEGER: %d\n");
//	printf("Crtl+D to quit\n");
//	
//	yyin = fopen(argv[1], "r");
//	yylex();
//	fclose(yyin);

//}
