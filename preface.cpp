/*
ID: ysharry1
PROG: preface
LANG: C++
*/

#include <fstream>
#include <iostream>
using namespace std;

char symbol[7];
int counts[7];
int n;

void compute(int p){	
	counts[6] += p/1000;
	p = p % 1000;
	if(p >= 900){
		p -= 900; //CM
		counts[6]++;
		counts[4]++;
	} else if (p >=500){
		p -= 500; //D
		counts[5]++;
	} else if (p >= 400){
		p -= 400; //CD
		counts[4]++;
		counts[5]++;
	} 
	counts[4] += p/100;
	p = p % 100;
	if(p >= 90){
		p -= 90; //XC
		counts[2]++;
		counts[4]++;
	} else if (p >=50){
		p -= 50; //L
		counts[3]++;
	} else if (p >= 40){
		p -= 40; //XL
		counts[2]++;
		counts[3]++;
	} 
	counts[2] += p/10;
	p = p % 10;
	if(p == 9){
		p -= 9;//IX
		counts[0]++;
		counts[2]++;
	} else if (p >=5){
		p -= 5; //V
		counts[1]++;
	} else if (p == 4){
		p -= 4; //IV
		counts[0]++;
		counts[1]++;
	}
	counts[0] += p;
}

int main(){
	ifstream in("preface.in");
	ofstream out("preface.out");

	in>>n;

	symbol[0] = 'I';
	symbol[1] = 'V';
	symbol[2] = 'X';
	symbol[3] = 'L';
	symbol[4] = 'C';
	symbol[5] = 'D';
	symbol[6] = 'M';

	for(int i = 1; i <= n; i++){
		compute(i);
	}

	for (int i = 0; i < 7; i++){
		if(counts[i] != 0){
			out<<symbol[i]<<" "<<counts[i]<<endl;
		}
	}
}

