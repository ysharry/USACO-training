/*
ID: ysharry1
PROG: subset
LANG: C++
*/

#include <iostream>
#include <fstream>
using namespace std;

int N;
int sum;
int c;

void solve(int n, int s){
	if(s > sum){return;}
	if(n > N){return;}
	if(s == sum){c++;return;}
	solve(n+1, s+n);
	solve(n+1, s);
	
}

int main(){
	ifstream in("subset.in");
	ofstream out("subset.out");

	in>>N;
	for(int i = 1; i <=N; i++){
		sum += i;
	}
	if (sum % 2 == 1){
		out<<0<<endl;
	} else {
		sum /= 2;
		solve(1,0);
		out<<c<<endl;
	}
}