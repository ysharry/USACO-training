/*
ID: ysharry1
PROG: frac1
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

struct frac{
	int den;
	int num;
};

int N;
struct frac frac_list[10000];

int cmp(const void* p1, const void* p2){
	struct frac* f1 = (struct frac*)p1;
	struct frac* f2 = (struct frac*)p2;

	return f1->num * f2->den - (f2->num * f1->den);
}

bool co_prime(int i ,int j){
	if (j == 1){return true;}
	if (j == 0){return false;}
	return co_prime(j,i % j);
}

int main(){
	ifstream in("frac1.in");
	ofstream out("frac1.out");

	in>>N;

	frac_list[0].den = 1;
	frac_list[0].num = 0;
	int total = 1;

	for (int i=1; i<=N; i++){
		for (int j=1; j<=i; j++){
			if ((j==1) || (co_prime(i,j))){
				frac_list[total].den = i;
				frac_list[total].num = j;
				total++;
			}
		}
	}
	qsort(frac_list,total,sizeof(frac_list[0]),cmp);

	for(int i=0 ; i< total; i++){
		out<<frac_list[i].num<<"/"<<frac_list[i].den<<endl;
	}


}


