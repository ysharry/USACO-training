/*
ID : ysharry1
LANG : C
PROG : ride
*/



#include <stdio.h>
#include <stdlib.h>

int main() {
	char* s1 = malloc(8*sizeof(char));
	char* s2 = malloc(8*sizeof(char)); 
	FILE *fin = fopen ("ride.in", "r");
	FILE *fout = fopen ("ride.out","w");
	fscanf(fin, "%s\n",s1);
	fscanf(fin, "%s",s2);
	char* c = s1;
	int r1 = 1 ;
	int r2 = 1;
	while ((*c) != '\0'){
		r1 = r1*((*c) - 64);
		c = c+sizeof(char);
	}
	c= s2;
	while ((*c) != '\0'){
		r2 = r2 *((*c)-64);
		c = c+sizeof(char);
	}
	if ((r1 % 47)==(r2 % 47)) {fprintf(fout,"GO\n");}
	else {fprintf(fout, "STAY\n");}
	fclose(fin);
	fclose(fout);
}