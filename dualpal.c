/*
ID: ysharry1
PROG: dualpal
LANG: C
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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

int convert(char *digit, int n, int B){
	int j = 0 ;
	while(n != 0){
		char s[2];
		sprintf(s,"%d",n%B);
		digit[j] = s[0];
		n = n / B;
		j++;
	}
	return j;
}

int main(){
	FILE *in = fopen("dualpal.in","r");
	FILE *out = fopen("dualpal.out","w");

	int N, S;
	fscanf(in,"%d %d\n", &N, &S);

	int count = 0;
	int n = S+1;
	while(count < N){
		int base;
		int num_base = 0;
		for(base = 2 ; base < 11 ; base++){
			char digit[20];
			int len = convert(digit, n, base);
			if(is_palindrom(digit, len)){
				num_base++;
				if(num_base == 2){
					count++;
					fprintf(out, "%d\n", n);
					break;
				}
			}
		}
		n++;
	}


	fclose(in);
	fclose(out);
}