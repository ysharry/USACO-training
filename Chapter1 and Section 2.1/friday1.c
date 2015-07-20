/*
ID : alu1
LANG : C
PROG : friday
*/



#include <stdio.h>
#include <stdlib.h>

int feb(int n){
	if ((n % 4 ==0 && n %100 !=0)||(n %400 ==0)){
		return 1;
	}else{
		return 0;
	}

}

int main() {
	int n, i, j;
	FILE *fin = fopen ("friday.in", "r");
	FILE *fout = fopen ("friday.out","w");
	fscanf(fin, "%d",&n);
	int a[12];
	a[0] = 3;
	a[1] = 0;
	a[2] = 3;
	a[3] = 2;
	a[4] = 3;
	a[5] = 2;
	a[6] = 3;
	a[7] = 3;
	a[8] = 2;
	a[9] = 3;
	a[10] = 2;
	a[11] = 3;
	int days[7];

	//the first 13 is a saturday
    days[0] = 1;
    //initialzing days
    for (i=1;i<7;i++){
    	days[i] = 0;
    }

    int left = 0;
    for (j=1; j<12; j++){
    	days[((a[j-1] + left) % 7)] += 1;
    	left = (a[j-1] + left) % 7;
    }

	for (i =1; i< n; i++){
	    a[1] = feb(1900+i);
	    days[((a[11] + left) % 7)] +=1;
		left = (a[11]+ left) % 7;
		for (j=1; j < 12; j++){
			days[((a[j-1] + left) % 7)] +=1;
		    left = (a[j-1]+ left) % 7;
		}

	}
	
	for (i=0; i<7; i++){
		fprintf(fout,"%d ", days[i]);
	}
	fclose(fin);
	fclose(fout);
}