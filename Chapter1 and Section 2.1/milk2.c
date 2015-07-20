/*
ID: ysharry1
PROG: milk2
LANG: C
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool is_milking(int t, int* start, int* end, int len){
	int i;
	for (i = 0; i < len; i++){
		if (t >= start[i] && t < end[i]){
			return true;
		}
	}
	return false;
}

int main() {
	FILE* in = fopen("milk2.in","r");
	FILE* out = fopen ("milk2.out","w");

	int idleinterv = 0;
	int milkinterv = 0;
	bool status = false;
	int start_time = 0;

	int n;
	fscanf(in,"%d\n",&n);
	int start[n];
	int end[n];
	int i;
	for (i=0; i<n; i++){
		fscanf(in, "%d %d", &(start[i]), &(end[i]));
	}

	int min = start[0];
	int max = end[0];
	for (i=1; i<n; i++){
		if (start[i] < min) {min = start[i];}
		if (end[i] > max) {max = end[i];}
	}
	start_time = min;

	for (i = min; i<= max; i++){
		if (status==false){
			if(is_milking(i, start, end, n)){
				status = true;
				int interv = i - start_time;
				if (interv > idleinterv) {idleinterv = interv;}
				start_time = i;
			}
		}
		else {
			if(!is_milking(i, start, end, n)){
				status = false;
				int interv = i - start_time;
				if (interv > milkinterv) {milkinterv = interv;}
				start_time = i;
			}
		}
	}
	if (max - start_time > milkinterv) {
		milkinterv = max - start_time;
	} 
	fprintf(out, "%d %d\n", milkinterv, idleinterv);

	fclose(in);
	fclose(out);
}




