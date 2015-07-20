/*
ID: ysharry1
PROG: pprime
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <math.h>
using namespace std;

int A,B;
const int maxp = 10000;
int primes[maxp];
bool isp[maxp];
int plen;
 
bool prime(int i)
{
	if (i == 1)
		return false;
	if (i == 2 || i == 3)
		return true;
	if (i % 2 == 0)
		return false;
	int m = (int)sqrt((float)i);
	if (m > i - 1)
		m = i - 1;
	for (int j = 3; j < m + 1; j += 2)
	{
		if (i % j == 0)
			return false;
	}
	return true;
}
 
 
bool is_prime(int i)
{
	if (i < 10001)
	{
		return isp[i];
	}
	int m = (int)sqrt((float)i);
	for (int j = 0; j < plen; ++j)
	{
		if(primes[j] > m + 1)
			break;
		if (i % primes[j] == 0)
			return false;
	}
	return true;
}

bool in_range(int n){
	return A <=n && n <= B;
}

bool need_check(int d){
	return A < pow(10,(d)) && B > pow(10,d-1);
}

int main(){
	ofstream fout("pprime.out");
	ifstream fin("pprime.in");

	fin>>A;
	fin>>B;

	for (int i = 1; i <= 10000; ++i)
	{
		if (prime(i))
		{
			primes[plen++] = i;
			isp[i] = true;
		}
		else
			isp[i] = false;
	}

	if(need_check(1)){
		for(int i=1; i<10; i=i+2){
			if(in_range(i) && is_prime(i)){
				fout<<i<<endl;
			}
		}
	}

	if(need_check(2)){
		for(int a = 1; a<10; a=a+2){
			int n = a*10+a;
			if(in_range(n) && is_prime(n)){
				fout<<n<<endl;
			}
		}
	}
	if(need_check(3)){
		for (int a = 1; a < 10; a=a+2){
			for(int b=0;b<10;b++){
				int n = a*101+b*10;
				if(in_range(n) && is_prime(n)){
					fout<<n<<endl;
				}
			}
		}
	}
	if(need_check(4)){
		for (int a = 1; a < 10; a=a+2){
			for(int b=0;b<10;b++){
				int n = a*1001+b*110;
				if(in_range(n) && is_prime(n)){
					fout<<n<<endl;
				}
			}
		}
	}
	if(need_check(5)){
		for (int a = 1; a < 10; a=a+2){
			for(int b=0;b<10;b++){
				for(int c=0;c<10;c++){
					int n = a*10001+b*1010+c*100;
					if(in_range(n) && is_prime(n)){
						fout<<n<<endl;
					}
				}
			}
		}
	}
	if(need_check(6)){
		for (int a = 1; a < 10; a=a+2){
			for(int b=0;b<10;b++){
				for(int c=0;c<10;c++){
					int n = a*100001+b*10010+c*1100;
					if(in_range(n) && is_prime(n)){
						fout<<n<<endl;
					}
				}
			}
		}
	}
	if(need_check(7)){
		for (int a = 1; a < 10; a=a+2){
			for(int b=0;b<10;b++){
				for(int c=0;c<10;c++){
					for(int d=0;d<10;d++){
						int n = a*1000001+b*100010+c*10100+d*1000;
						if(in_range(n) && is_prime(n)){
							fout<<n<<endl;
						}
					}
				}
			}
		}
	}
	if(need_check(8)){
		for (int a = 1; a < 10; a=a+2){
			for(int b=0;b<10;b++){
				for(int c=0;c<10;c++){
					for(int d=0;d<10;d++){
						int n = a*10000001+b*1000010+c*100100+d*11000;
						if(in_range(n) && is_prime(n)){
							fout<<n<<endl;
						}
					}
				}
			}
		}
	}


}
