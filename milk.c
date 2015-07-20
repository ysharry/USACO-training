/*
ID: ysharry1
PROG: milk
LANG: C
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct farmer{
	int price;
	int amount;
};
typedef struct farmer* farmer;

int cmp(const void *p1, const void *p2){
	farmer* f1 = (farmer*)p1;
	farmer* f2 = (farmer*)p2;
	return ((*f1)->price) - ((*f2)->price);
}

int main(){

	FILE *in = fopen("milk.in","r");
	FILE *out = fopen("milk.out","w");

	int total, n, i;
	fscanf(in, "%d %d\n", &total, &n);
	farmer *farmerlist = malloc(n*sizeof(farmer));
	for(i=0; i<n; i++){
		farmerlist[i] = malloc(sizeof(struct farmer));
		fscanf(in,"%d %d\n",&(farmerlist[i]->price),
							&(farmerlist[i]->amount));
	}

	qsort(farmerlist,n,sizeof(farmerlist[0]),cmp);

	for(i=0;i<n;i++){
		printf("%d %d\n", farmerlist[i]->price, farmerlist[i]->amount);
	}

	i = 0;
	int cost = 0;
	while (total >= farmerlist[i]->amount){
		total -= farmerlist[i]->amount;
		cost += farmerlist[i]->amount * farmerlist[i]->price;
		i++;
	}
	cost += total * farmerlist[i]->price;

	fprintf(out, "%d\n", cost);

	fclose(in);
	fclose(out);
}