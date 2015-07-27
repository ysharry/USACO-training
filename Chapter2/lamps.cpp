/*
ID: ysharry1
PROG: lamps
LANG: C++
*/

#include <fstream>
#include <iostream>
using namespace std;

int N,C;
bool lamps[101];
bool target[101];
int fix[100];
int fix_index;
bool ans;

void press1(){
	for(int i = 1; i <= N; i++){
		lamps[i] = (lamps[i]+1)%2;
	}
}
void press2(){
	for(int i = 1; i <= N; i+=2){
		lamps[i] = (lamps[i]+1)%2;
	}
}
void press3(){
	for(int i = 2; i <= N; i+=2){
		lamps[i] = (lamps[i]+1)%2;
	}
}
void press4(){
	for(int i = 1; i <= N; i+=3){
		lamps[i] = (lamps[i]+1)%2;
	}
}

bool match(){
	for(int i = 0; i < fix_index; i++){
		if(lamps[fix[i]] != target[fix[i]]){
			return false;
		}

	}
	return true;
}

void DFS(int c, ofstream &out){
	if(c==C){
		if(match()){
			ans = true;
			for(int i = 1; i <= N; i++){
				out<<lamps[i];
			}
			out<<endl;
		}
		return;
	}
	c++;
	press1();
	DFS(c, out);
	press1();
	press2();
	DFS(c, out);
	press2();
	press3();
	DFS(c, out);
	press3();
	press4();
	DFS(c, out);
	press4();
}

int main(){
	ifstream in("lamps.in");
	ofstream out("lamps.out");

	in>>N;
	in>>C;
	int v;
	fix_index = 0;
	in>>v;
	while(v != -1){
		fix[fix_index] = v;
		fix_index++;
		target[v] = true;
		in>>v;
	}
	in>>v;
	while(v != -1){
		fix[fix_index] = v;
		fix_index++;
		target[v] = false;
		in>>v;
	}
	int c = 0;
	for(int i = 1; i <= N; i++){
		lamps[i] = true;
	}
	DFS(c, out);
	if(!ans){
		out<<"IMPOSSIBLE"<<endl;
	}

}
