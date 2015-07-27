 /*
ID: ysharry1
PROG: hamming
LANG: C++
*/

#include <fstream>
#include <iostream>
#include <stdlib.h>
using namespace std;

int N,B,D,total,n;
int* answers[65];

int* convert(int n){
	
	int* result = (int*)malloc(B*sizeof(int));
	int i = 0;
	while(n!=0){
		result[i] = n % 2;
		n = n/2;
		i++;
	}
	return result;
}

bool hdifferent(int *bin){
	for(int i = 0; i < total; i++){
		int count = 0;
		for(int b = 0; b < B; b++){
			if(answers[i][b] != bin[b]){
				count++;
			}
		}
		if(count < D){return false;}
	}
	return true;
}

int main(){

	ifstream in("hamming.in");
	ofstream out("hamming.out");

	in>>N>>B>>D;
	total = 0;
	n = 0;

	while(total<N){
		int* bin = convert(n);
		if(hdifferent(bin)){
			
			if(total % 10 == 0){
				if (total != 0 ){
					out<<endl;
				}
			} else {
				out<<" ";
			}
			out<<n;
			answers[total] = bin;
			total++;
		}
		n++;
	}
	out<<endl;
}