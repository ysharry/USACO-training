/*
ID: ysharry1
PROG: runround
LANG: C++
*/

#include <fstream>
#include <iostream>
using namespace std;

int M;
int answer;
bool found;
bool table[10];
int array[9];
int temp[9];

int read(int *array, int n){
	int count = 0;
	while(n != 0){
		temp[count] = n % 10;
		n = n/10;
		count++;
	}
	for(int i = 0; i < count; i++){
		array[i] = temp[count-i-1];
	}
	return count;
}

void run(int n){
	for(int i = 0; i < 10; i++){
		table[i] = false;
	} // initializing table for checking uniqueness
	int len = read(array,n);
	for(int i = 0; i < len; i++){
		if (array[i] == 0){return;}	
	}// check if none of the digits is zero
	int d = array[0];
	table[d] = true;
	int index = 0;
	while(d != 0){
		array[index] = 0;
		index = (index+d)%len;
		d = array[index];
		if(table[d]){
			return; // Some digit d appears more than once
		} else {table[d] = true;}
	}
	if(index!=0){return;} //check if it returns to the first digit
	for(int i = 0; i < len; i
		++){
		if (array[i] != 0){
			return;
		}
	}  // check if every digit is visited
	found = true;
	answer = n;

}

int main(){
	ifstream in("runround.in");
	ofstream out("runround.out");
	in>>M;

	found = false;

	for (int i = M+1; found == false; i++){
		run(i);
	}
	out<<answer<<endl;

}