/*
ID: ysharry1
PROG: castle
LANG: C++
*/

/* 7/5/2015  Harry Shao */

#include <fstream>
#include <iostream>
using namespace std;

struct cel
{
	bool west;
	bool north;
	bool east;
	bool south;
	int group;

};
typedef struct cel* cell;

int M,N;
int total_group;
cell castle[50][50];
int group_sizes[2501];

void find_component(int i, int j){
	castle[i][j] -> group = total_group;
	group_sizes[total_group] ++;
	if(j>0 && !(castle[i][j]->west)&& (castle[i][j-1]->group == -1)){
		find_component(i,j-1);
	}
	if(i>0 && !(castle[i][j]->north)&& (castle[i-1][j]->group == -1)){
		find_component(i-1,j);
	}
	if(j<M-1 && !(castle[i][j]->east)&& (castle[i][j+1]->group == -1)){
		find_component(i,j+1);
	}
	if(i<N-1 && !(castle[i][j]->south)&& (castle[i+1][j]->group == -1)){
		find_component(i+1,j);
	}
}

int main(){
	ifstream in("castle.in");
	ofstream out("castle.out");

	in>>M>>N;

	total_group = 0;

	for(int i = 0; i < N; i++){
		for(int j = 0; j < M; j++){
			int wall;
			in>>wall;
			cell cur_cell =  (cell)malloc(sizeof(struct cel));
			castle[i][j] = cur_cell;
			cur_cell->group = -1;
			if (wall >= 8){
				wall = wall - 8;
				cur_cell -> south = true;
			} else {cur_cell -> south = false;}
			if (wall >= 4){
				wall = wall - 4;
				cur_cell -> east = true;
			} else {cur_cell -> east = false;}
			if (wall >= 2){
				cur_cell->north = true;
				wall = wall - 2;
			} else {cur_cell->north = false;}
			if (wall >= 1){
				cur_cell->west = true;
			} else {cur_cell->west = false;}
		}
	}

	for (int i=0; i< N; i++){
		for (int j=0; j < M; j++){
			if(castle[i][j] -> group == -1){
				total_group++;
				find_component(i,j);
			}
		}
	}

	int max_size = 0;
	for (int i=1; i<=total_group;i++){
		if (group_sizes[i] > max_size) {
			max_size = group_sizes[i];
		}
	}

	out<<total_group<<endl;
	out<<max_size<<endl;

	max_size = 0;
	int max_row = N-1;
	int max_col = 0;
	char max_wall = 'N';
	for(int j = 0; j < M; j++){
		for (int i= N-1; i >= 0; i--){
			int new_size = 0;
			if(i>0 && castle[i][j] -> north){
				int size_below = group_sizes[castle[i][j]->group];
				int size_above = group_sizes[castle[i-1][j]->group];
				if(castle[i-1][j]->group == castle[i][j]->group){
					new_size = size_below;
				}else {
					new_size = size_below + size_above;
				}
				if(new_size > max_size){
					max_size = new_size;
					max_row = i;
					max_col = j;
					max_wall = 'N';
				}
			}
			if(j < M-1 && castle[i][j] -> east){
				int size_left = group_sizes[castle[i][j]->group];
				int size_right = group_sizes[castle[i][j+1]->group];
				if(castle[i][j+1]->group == castle[i][j]->group){
					new_size = size_left;
				}else {
					new_size = size_left + size_right;
				}
				if(new_size > max_size){
					max_size = new_size;
					max_row = i;
					max_col = j;
					max_wall = 'E';
				}
			}
		}
	}

	out<<max_size<<endl;
	out<<max_row+1<<" "<<max_col+1<<" "<<max_wall<<endl;


}