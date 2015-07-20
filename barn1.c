/*
ID: ysharry1
PROG: barn1
LANG: C
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int cmp1(const void *p1, const void *p2){
	return *(int*)p2 - *(int*)p1;
}

int cmp2(const void *p1, const void *p2){
	return *(int*)p1 - *(int*)p2;
}

int main(){
	FILE *in = fopen("barn1.in","r");
	FILE *out = fopen("barn1.out","w");

	int M, S, C;

	fscanf(in,"%d %d %d\n", &M, &S,&C);
	int list[C];
	int i;
	for(i=0; i<C; i++){
		fscanf(in,"%d\n",&(list[i]));
	}
	qsort(list,C, sizeof(list[0]), cmp2);

	int total = list[C-1] - list[0] + 1;
	int diffs[C-1];
	for(i=0; i<C-1; i++){
		diffs[i] = list[i+1] - list[i];
	}

	qsort(diffs, C-1, sizeof(diffs[0]), cmp1);

	for(i=0; i<M-1 && i < C-1; i++){
		total -= diffs[i]-1;
	}

	fprintf(out, "%d\n", total);

	fclose(in);
	fclose(out);
}