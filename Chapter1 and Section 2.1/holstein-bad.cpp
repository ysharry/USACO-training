/*
ID: ysharry1
PROG: holstein
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <queue>
#include <assert.h>
using namespace std;

int V, G;
int require[25];
int feed[15][25];

struct state{
	int max_scoop;
	int total[25];
	bool scoop[15];
};

bool require_met(struct state* s){
	for (int i = 0; i < V; i++){
		if (s->total[i] < require[i]){return false;}
	}
	return true;
}

void add_feed(queue<struct state*> Q, ofstream &out){
	struct state* s = Q.front();
	Q.pop();

	if(require_met(s)){
		int count = 0;
		for(int i=0; i<G; i++){
			if(s->scoop[i]){
				count++;
			}
		}
		out<< count;
		for(int i = 0; i < G; i++){
			if(s->scoop[i]){
				out<<" "<<i+1;
			}
		}
		out<<endl;
		return;
	}


	for (int i = s->max_scoop; i < G; i++){
		if (s->scoop[i]) {continue;}
		struct state* new_state = (struct state*)malloc(sizeof(struct state));
		//new_state->total_scoop  = s->total_scoop+1;
		for (int j = 0; j < V; j++){
			new_state->total[j] = s->total[j] + feed[i][j];
		}
		for (int j =0 ; j < G; j++){
			new_state->scoop[j] = s->scoop[j];
		}
		assert(!(new_state->scoop[i]));
		new_state->scoop[i] = true;
		new_state->max_scoop = i;
		
		Q.push(new_state);
	}

	add_feed(Q,out);
}

int main(){
	ifstream in("holstein.in");
	ofstream out("holstein.out");

	in>>V;
	for(int i = 0; i < V; i++){
		in>>require[i];
	}

	in>>G;
	for(int i = 0; i < G; i++){
		for(int j = 0; j < V; j++){
			in>>feed[i][j];
		}
	}

	queue<struct state*> Q;
	struct state* initial = (struct state*)malloc(sizeof(struct state));
	//initial->total_scoop = 0;
	for(int i = 0; i < V; i++){
		initial->total[i] = 0;
	}
	for (int i = 0; i < G; i++){
		initial->scoop[i] = false;
	}
	initial->max_scoop = 0;
	Q.push(initial);

	add_feed(Q, out);


}