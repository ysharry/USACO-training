/*
ID: ysharry1
PROG: combo
LANG: C
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int N;
int lock1[3];
int lock2[3];
int count[3];

int convert(int n){
	if (n<0){return n+N;}
	else{return n;}
}

int min(int a, int b){
	if (a < b){return a;}
	else{return b;}
}

int distance(int a, int b){
	return min(convert(a-b), convert(b-a));
}

int main(){
	FILE *in = fopen("combo.in","r");
	FILE *out = fopen("combo.out","w");

	fscanf(in,"%d\n",&N);
	int i;
	for(i=0 ; i<3; i++){
		fscanf(in,"%d ",&(lock1[i]));
	}
	for(i=0 ; i<3; i++){
		fscanf(in,"%d ",&(lock2[i]));
	}
	int result;

	if (N<5) {
		result = N*N*N;
	} else {

	for(i=0; i<3; i++){
		int j;
		for(j=1; j<=N; j++){
			if(distance(j,lock1[i])<3 && distance(j,lock2[i])<3){
				count[i]++;
			}
		}
	}

	result = 250 - (count[0]*count[1]*count[2]);
	}
	
	fprintf(out, "%d\n", result);


	fclose(in);
	fclose(out);
}