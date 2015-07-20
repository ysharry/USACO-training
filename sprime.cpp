/*
ID: ysharry1
PROG: sprime
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <math.h>
using namespace std;

int N;
bool is_p[10000];
int prime[10000];

bool prime1(int n){
	if (n==1) {return false;}
	if (n==2) {return true;}
	if (n % 2 ==0){return false;}
	int m = sqrt(n);
	for(int i=3;i<= m;i++){
		if(n % i==0){return false;}
	}
	return true;
}

bool is_prime(int n){
	if(n <=10000) {
		return is_p[n];
	}
	int m = sqrt(n);
	for (int i  = 0; prime[i]<= m; i++){
		if (n % prime[i] == 0){return false;}
	}
	return true;
}

void Search(int n, int digit, ofstream &out){
	if (digit == N){
		out<<n<<endl;
		return;
	}
	if (digit == 0) {
		for (int i=2; i<10;i++){
			int n1 = n*10+i;
			if (is_prime(n1)){
				Search(n1, digit+1, out);
			}
		}
	} else {
		for (int i=1; i<10; i += 2){
			int n1 = n*10+i;
			if (is_prime(n1)){
				Search(n1, digit+1, out);
			}
		}
	}
	
}

int main(){
	ifstream in("sprime.in");
	ofstream out("sprime.out");

	in>>N;

	int count = 0;

	for (int i=1; i <10000; i++){
		bool p = prime1(i);
		is_p[i] = p;
		if (p) {
			prime[count] = i;
			count++;
		}
	}

	Search(0, 0, out);
}