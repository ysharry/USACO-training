/*
ID: ysharry1
LANG: C
PROG: skidesign
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int N;  
int h[1001];  
#define MIN(a,b) ((a)>(b)?(b):(a))  
int main(int argc,char *argv[])  
{  
    freopen("skidesign.in","r",stdin);  
    freopen("skidesign.out","w",stdout);  
    scanf("%d",&N);  
    int Max=0;  
    int tmp;
    int i,j;  
    for(i=0;i<N;++i)  
    {  
        scanf("%d",&tmp);  
        if(Max<tmp)Max=tmp;  
        h[i]=tmp;  
    }  
    int ans=0x3f3f3f3f;  
    for(i=0;i<=Max;++i)  
    {  
        int sum=0;  
        for(j=0;j<N;++j)  
        {  
            if(h[j]<i&&i-h[j]>17)  
            {  
                int c=(i-h[j]-17)*(i-h[j]-17);  
                sum+=c;  
            }  
            if(h[j]>i)  
            {  
                int c= h[j]-i;  
                sum+=c*c;  
            }  
        }  
        ans=MIN(sum,ans);  
    }  
    printf("%d\n",ans);  
  
    return 0;  
}  