/*
ID: ysharry1
PROG: sort3
LANG: C++
*/

#include <fstream>
#include <iostream>
using namespace std;

int N;
int data[1000];
int count[4];
int region[4];
int num_swap = 0;

void swap(int i, int j){
	num_swap ++;
	int t = data[i];
	data[i] = data[j];
	data[j] = t;
}

int find(int target, int r){
	for(int i = region[r-1]; i < region[r]; i++){
		if(data[i] == target){
			return i;
		}
	}
	return -1;
}


int main(){

	ifstream in("sort3.in");
	ofstream out("sort3.out");

	in>>N;
	for (int i = 0; i < N; i++){
		in>>data[i];
		count[data[i]]++;
	}
	region[0] = 0;
	region[1] = count[1];
	region[2] = count[1]+count[2];
	region[3] = N;
	for (int i = 0; i < region[1]; i++){
		int n = data[i];
		if (n==2) {
			int j = find(1,2);
			if (j == -1){ j = find (1,3);}
			swap(i,j);
		}
		else if (n==3) {
			int j = find(1,3);
			if (j == -1){ j = find (1,2);}
			swap(i,j);
		}
	}

	for (int i = region[1]; i < region[2]; i++){
		int n = data[i];
		if (n==3) {
			int j = find(2,3);
			swap(i,j);
		}
	}

	out<<num_swap<<endl;

}