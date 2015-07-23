/*
ID: ysharry1
PROG: subset
LANG: C++
*/

#include <fstream>
#include <iostream>
using namespace std;

int N;
long long dp[40][500];

int main(){
	ifstream in("subset.in");
	ofstream out("subset.out");

	in>>N;
	int sum = N*(N+1) / 2;
	if (sum %2 == 0){
		sum = sum/2;
		for(int i = 0; i <= sum; i++){
			dp[0][i] = 0;
		}
		for(int i = 0; i <= N; i++){
			dp[i][0] = 1;
		}
		for(int j = 1; j<=sum; j++){
			for(int i = 1; i <= N; i++){
				if(i > j){
					dp[i][j] = dp[i-1][j];
				}else {
					dp[i][j] = dp[i-1][j] + dp[i-1][j-i];
				}
			}
		}
		for(int i = 0; i<=N; i++){
			for(int j = 0; j <= sum; j++){
				cout<<dp[i][j]<<" ";
			}
			cout<<endl;
		}
		out<<dp[N][sum]/(long)2<<endl;
	} else {
		out << 0 <<endl;
	}



}