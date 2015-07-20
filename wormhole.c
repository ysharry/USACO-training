/* 
  ID:ysharry1 
  PROG:wormhole 
  LANG:C 
*/    
#include <stdio.h>  
#include <stdlib.h>
#include <stdbool.h>   
#define MAX_N 12  
  
int N, X[MAX_N+1], Y[MAX_N+1];  
int partner[MAX_N+1];  
int next_on_right[MAX_N+1];  
  
bool cycle_exists()  
{  
	int start;
    for (start=1; start<=N; start++) {  
        // does there exist a cylce starting from start  
        int pos = start;  
        int count;
        for (count=0; count<N; count++)  
        {  
            pos = next_on_right[partner[pos]];  
        }  
        if (pos != 0) return true;  
    }  
    return false;  
}  
  
// count all solutions  
int solve()  
{  
    // find first unpaired wormhole  
    int i, total=0;  
    for (i=1; i<=N; i++)  
        if (partner[i] == 0) break;  
  
    // everyone paired?  
    if (i > N) {  
        if (cycle_exists()) return 1;  
        else return 0;  
    }  

    int j;
  
    // try pairing i with all possible other wormholes j  
    for (j=i+1; j<=N; j++)  
        if (partner[j] == 0) {  
            // try pairing i & j, let recursion continue to  
            // generate the rest of the solution  
            partner[i] = j;  
            partner[j] = i;  
            total += solve();  
            partner[i] = partner[j] = 0;  
        }  
    return total;  
}  
  
int main()  
{ 
	FILE *in;
	FILE *out; 
    in = fopen("wormhole.in","r");  
    fscanf(in, "%d\n", &N);  
    int i ,j ;
    for (i=1; i<=N; i++) fscanf(in,"%d %d\n", &(X[i]),&(Y[i]));
    fclose(in);  
  	

    for (i=1; i<=N; i++) // set next_on_right[i]...  
        for (j=1; j<=N; j++)  
            if (X[j] > X[i] && Y[i] == Y[j]) // j right of i...  
                if (next_on_right[i] == 0 ||  
                    X[j]-X[i] < X[next_on_right[i]]-X[i])  
                    next_on_right[i] = j;  
    //找出紧邻的右边平行点  
  
    out = fopen("wormhole.out","w");  
    int result = solve();
    fprintf(out, "%d\n", result); 
    //  cout<<solve()<<endl;  
    fclose(out);  

} 