/*
ID: ysharry1
PROG: friday
LANG: C
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main() {
	FILE* in = fopen("friday.in","r");
	FILE* out = fopen ("friday.out","w");
	int n;
	fscanf (in, "%d\n", &n);

	int a[7];
	int i;
	for (i = 0; i<7; i++){
		a[i] = 0;
	}
	int year;
	int prev_13 = 5;
	a[5]++;
	for (year = 1900; year < 1900+n;  year++){
		bool is_leap;
		if ((year % 4 ==0 && year %100 !=0)||(year %400 ==0)){
			is_leap = true;
		} else {is_leap = false;}

		int month;
		for(month = 1 ; month < 13; month++){
			int day;
			if ((month==4)||(month==6)||(month==9)||(month==11)){
				day = 30;
			}else if(month == 2 && is_leap) {
				day = 29;
			}else if (month ==2){
				day = 28;
			}else {day = 31;}
			prev_13 = (prev_13+day) % 7;
			a[prev_13]++;
			if (year == 1900+n-1 && month ==12){a[prev_13]--;}

		}
	}

	fprintf(out,"%d", a[5]);
	fprintf(out," %d", a[6]);
	for (i = 0; i< 5; i++){
		fprintf(out," %d", a[i]);
	}
	fprintf(out,"\n");

	fclose(in);
	fclose(out);

}