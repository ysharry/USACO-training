/*
ID: ysharry1
PROG: milk3
LANG: C++
*/

#include <stdio.h>
#include <iostream>
#include <cstring>

using namespace std;

int A,B,C;
bool state[21][21][21] = {0};
bool result[21] = {0};


void DFS(int a, int b, int c){
	if (state[a][b][c]) {
		return;
	}
	state[a][b][c] = true;
	if (a == 0){
		result[c] = true;
	}
	//A -> B
	if (a+b <= B){
		DFS(0, a+b, c);
	} else { DFS(a-(B-b), B, c);}
	//B -> A
	if (a+b <= A){
		DFS(a+b, 0, c);
	} else { DFS(A, b-(A-a),c);}
	//A -> C
	if (a+c <= C){
		DFS(0, b, a+c);
	} else { DFS(a - (C-c), b ,C);}
	//C -> A
	if (a+c <= A){
		DFS(a+c, b, 0);
	} else { DFS(A , b, c - (A-a));}
	//B -> C
	if (c+b <= C){
		DFS(a, 0, b+c);
	} else { DFS(a, b-(C-c), C);}
	//C -> B
	if (c+b <= B){
		DFS(a, b+c, 0);
	} else { DFS(a, B, c -(B-b));}
}

int main(){
	FILE *in = fopen("milk3.in","r");
	FILE *out = fopen("milk3.out","w");

	fscanf(in, "%d %d %d\n" , &A, &B, &C);
	int init = C;

	DFS(0,0,C);

	int i;
	for(i=0; i<init; i++){
		if (result[i]){
			fprintf(out, "%d ", i);
		}
	}
	fprintf(out, "%d\n", init);

	fclose(in);
	fclose(out);
}

