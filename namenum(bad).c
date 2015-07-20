/*
ID: ysharry1
PROG: namenum
LANG: C
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

char mapping[8][3];
char* dict [4617];
bool flag = false;

char* reduce(char *n){
	int len = strlen(n);
	char* new = malloc(len*sizeof(char));
	int i = 0;
	for(i =0; i < len-1; i++){
		new[i] = n[i+1];
	}
	new[len-1] = '\0';
	return new;
}

bool is_in(char *str){
	int i;
	for(i=0; i<4617; i++){
		if(strcmp(str,dict[i])==0){return true;}
		if(strcmp(str,dict[i])<0){return false;}
	}
	return false;
}

void print_result(char *num, char *str, FILE *out){

	if (strlen(num) == 0){
		if(is_in(str)){
			flag = true;
			fprintf(out, "%s\n", str); 
		}	
	}
	else {
		int digit = num[0] - '0';
		printf("%d\n", digit);
		int i;
		for(i = 0; i< 3; i++){
			char new[12];
			strcpy(new, str);
			char cstring[2];
			cstring[0] = mapping[digit-2][i];
			cstring[1] = '\0';
			strcat(new, cstring);
			print_result(reduce(num), new ,out);
		}

	}

}


int main() {
	FILE * in = fopen("namenum.in","r");
	FILE * dictionary = fopen("dict.txt","r");
	FILE * out = fopen("namenum.out","w");


	mapping[0][0] = 'A';
	mapping[0][1] = 'B';
	mapping[0][2] = 'C';
	mapping[1][0] = 'D';
	mapping[1][1] = 'E';
	mapping[1][2] = 'F';
	mapping[2][0] = 'G';
	mapping[2][1] = 'H';
	mapping[2][2] = 'I';
	mapping[3][0] = 'J';
	mapping[3][1] = 'K';
	mapping[3][2] = 'L';
	mapping[4][0] = 'M';
	mapping[4][1] = 'N';
	mapping[4][2] = 'O';
	mapping[5][0] = 'P';
	mapping[5][1] = 'R';
	mapping[5][2] = 'S';
	mapping[6][0] = 'T';
	mapping[6][1] = 'U';
	mapping[6][2] = 'V';
	mapping[7][0] = 'W';
	mapping[7][1] = 'X';
	mapping[7][2] = 'Y';


	int i;
	for(i=0; i<4617; i++){
		dict[i] = malloc(12*sizeof(char));
		fscanf(dictionary, "%s\n",dict[i]);
	}

	char num[12];
	fscanf(in, "%s\n", num);

	print_result(num, "", out);
	if (flag == false) {fprintf(out, "NONE\n");}


	fclose(in);
	fclose(dictionary);
	fclose(out);



}