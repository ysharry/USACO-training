/*
ID: ysharry1
PROG: crypt1
LANG: C
*/

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int N;

bool is_valid(int *digits, int n){
	int i;
	while(n != 0){
		int d = n % 10;
		bool is_in = false;
		for(i=0; i < N; i++){
			if(d == digits[i]) {is_in = true;}
		}
		if (!is_in) {return false;}
		n = n / 10;
	}
	return true;
}

int main(){
	FILE *in = fopen("crypt1.in","r");
	FILE *out = fopen("crypt1.out","w");

	fscanf(in, "%d\n", &N);
	int digits[N];
	int i;
	for(i=0; i< N; i++){
		fscanf(in, "%d ", &(digits[i]));
	}
	int count = 0;
	int a,b,c,d,e;
	for (a = 0; a < N; a++){
		for (b = 0; b < N; b++){
			for (c = 0; c < N; c++){
				for (d = 0; d < N; d++){
					for (e = 0; e < N; e++){
						int n1 = digits[a]*100+digits[b]*10+digits[c];
						int p1 = n1 * digits[e];
						int p2 = n1 * digits[d];
						if((is_valid(digits,p1))&(p1<=999)
						  &(is_valid(digits,p2))&(p2<=999)
						  &(is_valid(digits,p1*10+p2))){
							count++;
						}
					}
				}
			}
		}
	}
	fprintf(out, "%d\n", count);


	fclose(in);
	fclose(out);
}