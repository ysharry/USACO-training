/*
ID : ysharry1
PROG : gift1
LANG: C
*/



#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


struct account_hd{
	char* name;
	int balance; 
};
typedef struct account_hd* account;


bool streq (char* s1, char* s2){
	char* c1 = s1;
	char* c2 = s2;
	while (*c1 != '\0'){
		if(*c2 == '\0') {return false;}
		if (*c1 != *c2){return false;}
		c1 += sizeof(char);
		c2 += sizeof(char);
	}
	if (*c2 == '\0'){return true;}
	else {return false;}
}

account find(account* account_list, char* name){
	int i ;
	for (i =0 ; account_list[i] != NULL; i++){
		if (streq(account_list[i]->name, name)) {return account_list[i];}
	}
	return NULL;

}

int main() {

	FILE * in = fopen ("gift1.in", "r");
	FILE * out = fopen ("gift1.out","w");
	int NP ;
	fscanf (in, "%d", &NP);
	account* account_list = malloc(NP*sizeof(account));	
	int i;
	
	for (i = 0; i < NP; i++){
		account_list[i] = malloc(sizeof(struct account_hd));
		account_list[i]->name = malloc(20*sizeof(char));
		fscanf (in, "%s", account_list[i]->name);
	}
	

	for (i = 0; i < NP; i++){
		char* giver = malloc(20*sizeof(char));
		int total, n;
		fscanf(in, "%s\n", giver);
		fscanf(in, "%d %d\n", &total,&n);
		if (n!=0) {
			int left = total % n;
			int add = total / n;
			(find(account_list,giver) -> balance) -= (total-left);
			int j;
			for (j =0 ; j< n; j++){
				char* receiver = malloc(20*sizeof(char));
				fscanf(in, "%s", receiver);
				(find(account_list,receiver) -> balance) += add;
			}
		}
	}

	for(i =0 ; i< NP; i++){
		fprintf(out,"%s ",account_list[i]->name);
		fprintf(out, "%d\n", account_list[i]->balance);
	}

	fclose(in);
	fclose(out);

}