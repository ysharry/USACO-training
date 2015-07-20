/*
ID: ysharry1
PROG: palsquare
LANG: C
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int B;

char map(int digit){
	char *mapping = "ABCDEFGHIJ";
	if(digit < 10) {
		char s[2];
		sprintf(s,"%d",digit);
		return s[0];
	}
	else{return mapping[digit-10];}
}

bool is_palindrom(char *digit, int len){
	int begin = 0;
	int end = len -1;
	while (end > begin){
		if(digit[begin] != digit[end]){return false;}
		begin++;
		end--;
	}
	return true;
}

int convert(char *digit, int n){
	int j = 0 ;
	while(n != 0){
		digit[j] = map(n % B);
		n = n / B;
		j++;
	}
	return j;
}

int main(){
	FILE *in = fopen("palsquare.in","r");
	FILE *out = fopen("palsquare.out","w");

	fscanf(in, "%d\n", &B);

	int i;
	for (i = 1; i <= 300 ; i++){
		int square = i * i;
		char sq_digit[50];
		int sq_len = convert(sq_digit, square);
		if (is_palindrom(sq_digit, sq_len)) {
			char digit[30];
			int len = convert(digit, i);
			int j;
			for (j = len-1 ;j >=0 ; j--){
				fprintf(out, "%c", digit[j]);
			}
			fprintf(out, " ");
			for (j = 0; j < sq_len; j++){
				fprintf(out, "%c", sq_digit[j]);
			}
			fprintf(out, "\n");
		}
	}

	fclose(in);
	fclose(out);
}