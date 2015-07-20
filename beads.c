/*
ID: ysharry1
PROG: beads
LANG: C 
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool all_same = false;

int mod(int a, int f){
	if(a>=f){return (a % f);}
	if(a<0){return (a + f);}
	return a; 
}


char look_left(char* necklace, int size,int pos){
	int init = pos;
	while (necklace[mod(pos-1,size)] == 'w') {
		if (mod(pos-1,size) == mod(init,size)){all_same = true;break;}
		pos--;
	}
	return necklace[mod(pos-1,size)] ;
}

char look_right(char* necklace, int size, int pos){
	int init = pos;
	while (necklace[mod(pos,size)] == 'w'){
		if (mod(pos,size) == mod(init-1,size)) {all_same = true; break;}
		pos++;
	}
	return necklace[mod(pos,size)];
}

int search_left(char* necklace, int size, int pos, char left){
	int count = 0; 
	int init = pos;
	while (necklace[mod(pos-1,size)] == 'w' || necklace[mod(pos-1,size)]==left){
		if (mod(pos-1,size) == mod(init,size)){all_same = true;break;}
		count++;
		pos--;
	}
	return count;
}

int search_right(char* necklace, int size, int pos, char right){
	int count = 0; 
	int init = pos;
	while (necklace[mod(pos,size)] == 'w' || necklace[mod(pos,size)]==right){
		if (mod(pos,size) == mod(init-1,size)) {all_same = true; break;}
		count++;
		pos++;
	}
	return count;
}

int main() {
	FILE* in = fopen("beads.in","r");
	FILE* out = fopen("beads.out","w");

	int n;
	fscanf(in, "%d", &n);
	int i;
	int max;
	char* necklace = malloc(n*sizeof(char));
	for (i = 0; i<n;i++){
		fscanf(in, "%s", necklace);
	}
	for (i = 0; i < n ; i++){
		char left = look_left(necklace, n,i);
		char right = look_right(necklace, n,i);
		int num = search_left(necklace, n,i,left)+search_right(necklace,n,i,right);
		if (all_same == true) {max = n; break;}
		if (num > max) {max = num;}
	}
	if(max > n){fprintf(out,"%d\n",n);}
	else {fprintf(out,"%d\n",max);}

	fclose(in);
	fclose(out);
}




