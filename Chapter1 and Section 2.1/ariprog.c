/*
ID: ysharry1
PROG: ariprog
LANG: C
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct seq
{
	int start;
	int diff;
};

int N,M, num;

int cmp(const void *p1, const void *p2){
	struct seq* s1 = (struct seq*)p1;
	struct seq* s2 = (struct seq*)p2;
	int k = (s1->diff) - (s2->diff);
	if(k!=0){return k;}
	else{return (s1->start) - (s2->start);}
}

int main() {
	FILE *in = fopen("ariprog.in","r");
	FILE *out = fopen("ariprog.out","w");


	fscanf(in,"%d\n%d",&N, &M);


	bool mapping[M*M+M*M];
	int i,j;
	for(i=0; i< M*M+M*M; i++){
		mapping[i] = false;
	}
	for(i=0; i<=M; i++){
		for(j=0; j<=M;j++){
			mapping[i*i+j*j] = true;
		}
	}
	struct seq sol_list[10000];
	num = 0;
	int max = M*M+M*M;
	int max_diff = (M*M+M*M) / (N - 1);
	int start, diff;
	for (start=0; start<=M*M+M*M-N+1; start++){
		if(mapping[start] == false){continue;}
		for(diff = 1; diff<= max_diff; diff++){
			bool flag = true;
			for(i = 1; i < N; i++){
				if(start+i*diff > max || mapping[start+i*diff] == false){
					flag = false;
					break;
				}
			}
			if (flag) {
				sol_list[num].start = start;
				sol_list[num].diff = diff;
				num++;
			}
		}  
	}

	if (num == 0){
		fprintf(out, "NONE\n");
	}else{

		qsort(sol_list,num,sizeof(sol_list[0]), cmp);
		for (i=0; i<num; i++){
			fprintf(out, "%d %d", sol_list[i].start, sol_list[i].diff);
			fprintf(out, "\n");
		}
	}



	fclose(in);
	fclose(out);
}