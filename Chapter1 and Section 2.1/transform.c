/*
ID: ysharry1
PROG: transform
LANG: C
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int dimension;

char **rotate_90(char **square){
	char **new = malloc(dimension*sizeof(char*));
	int i, j;
	for(i = 0; i < dimension; i++){
		 new[i] = malloc(dimension*sizeof(char));
	}
	int r = 0;
	int c = dimension-1;
	for(i = 0; i < dimension ; i++){
		r = 0;
		for(j = 0 ; j < dimension; j++){
			new[r][c] = square[i][j];
			r++;
		}
		c--;
	}
	return new;
}

char **rotate_180(char **square){
	return rotate_90(rotate_90(square));
}

char **rotate_270(char **square){
	return rotate_90(rotate_180(square));
}

char **reflect(char **square){
	char **new = malloc(dimension*sizeof(char*));
	int i, j;
	for(i = 0; i < dimension; i++){
		new[i] = malloc(dimension*sizeof(char));
	}
	for(i = 0; i < dimension; i++){
		int c = dimension-1;
		for(j = 0 ; j < dimension; j++){
			new[i][c] = square[i][j];
			c--;
		}
	}
	return new;
}

bool eq(char **s1, char **s2){
	int i,j;
	for(i = 0; i< dimension; i++){
		for(j = 0; j < dimension; j++){
			if (s1[i][j] != s2[i][j]){return false;}
		}
	}
	return true;
}

int main (){
	FILE *in = fopen("transform.in","r");
	FILE *out = fopen("transform.out","w");

	fscanf(in, "%d\n", &dimension);
	char **before = malloc(dimension*sizeof(char*));
	char **after = malloc(dimension*sizeof(char*));
	int i, j ;
	for(i = 0; i < dimension ; i++){
		before[i] = malloc(dimension*sizeof(char));
		for(j = 0 ; j < dimension; j++){
			fscanf(in, "%c",&(before[i][j]));
		}
		fscanf(in,"\n");
	}
	for(i = 0; i < dimension ; i++){
		after[i] = malloc(dimension*sizeof(char));
		for(j = 0 ; j < dimension; j++){
			fscanf(in, "%c",&(after[i][j]));
		}
		fscanf(in,"\n");
	}

	int trans = 7;

	if(eq(rotate_90(before), after)){trans = 1;}
	else if(eq(rotate_180(before),after)){trans = 2;}
	else if(eq(rotate_270(before), after)){trans = 3;}
	else if(eq(reflect(before),after)){trans = 4;}
	else if(eq(rotate_90(reflect(before)), after)){trans = 5;}
	else if(eq(rotate_180(reflect(before)), after)){trans = 5;}
	else if(eq(rotate_270(reflect(before)), after)){trans = 5;}
	else if(eq(before, after)){trans = 6;}

	fprintf(out, "%d\n", trans);

	fclose(in);
	fclose(out);
}