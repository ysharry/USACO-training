/*
ID: ysharry1
PROG: holstein
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <cmath>
#include <string>
#include <cstring>
using namespace std;
ifstream fin("holstein.in");
ofstream fout("holstein.out");
int a[25],b[15][25],d[16],ans[16],c[25];
int main()
{
    int v;
    //cin>>v;
    fin>>v;
    int i,j;
    for(i=0;i!=v;++i)
        //cin>>a[i];
        fin>>a[i];
    int g;
    //cin>>g;
    fin>>g;
    for(i=0;i!=g;++i)
        for(j=0;j!=v;++j)
            //cin>>b[i][j];
            fin>>b[i][j];
    int num=0,min=20;
    long long sum=999999999999999,s;
    bool flag=1;                    //遍历每种可能的饲料组合
    for(d[15]=0;g>=15?(d[15]<=1):d[15]==0;++d[15])
    for(d[14]=0;g>=14?(d[14]<=1):d[14]==0;++d[14])
    for(d[13]=0;g>=13?(d[13]<=1):d[13]==0;++d[13])
    for(d[12]=0;g>=12?(d[12]<=1):d[12]==0;++d[12])
    for(d[11]=0;g>=11?(d[11]<=1):d[11]==0;++d[11])
    for(d[10]=0;g>=10?(d[10]<=1):d[10]==0;++d[10])
    for(d[9]=0;g>=9?(d[9]<=1):d[9]==0;++d[9])
    for(d[8]=0;g>=8?(d[8]<=1):d[8]==0;++d[8])
    for(d[7]=0;g>=7?(d[7]<=1):d[7]==0;++d[7])
    for(d[6]=0;g>=6?(d[6]<=1):d[6]==0;++d[6])
    for(d[5]=0;g>=5?(d[5]<=1):d[5]==0;++d[5])
    for(d[4]=0;g>=4?(d[4]<=1):d[4]==0;++d[4])
    for(d[3]=0;g>=3?(d[3]<=1):d[3]==0;++d[3])
    for(d[2]=0;g>=2?(d[2]<=1):d[2]==0;++d[2])
    for(d[1]=0;g>=1?(d[1]<=1):d[1]==0;++d[1])
    {
        memset(c,0,sizeof(c));
        flag=1;
        for(i=1;i<=g;++i)
        {
            if(d[i])                //如果当前组合中包含第i种饲料
                for(j=0;j!=v;j++)
                    c[j]+=b[i-1][j];    //保存当前组合的每种维他命的总量
        }
        for(j=0;j!=v;j++)
            if(c[j]<a[j])
            {
                flag=0;
                break;
            }
        if(flag)                        //如果当前组合满足各种维他命数量的最低要求
        {
            num=0;
            for(i=1;i<=g;i++)            //当前组合包含的饲料种数
                if(d[i])
                    num++;
            if(num<min)      //如果当前组合包含的饲料种数比先前的更少就将其保存下来
            {
                s=0;
                min=num;            
                for(i=1;i<=g;++i)
                    if(d[i])
                        ans[i]=d[i];
            }
            if(num==min)            //如果当前的与之前的饲料种数一样多，                 
            {                       //则保存饲料序号字典序最小的那个
                for(i=1;i<=g;++i)
                if(d[i])
                s+=10*d[i];             
                if(s<sum)                //比较饲料序号字典序
                {
                    sum=s;
                    for(i=1;i<=g;++i)
                        ans[i]=d[i];
                }
            }
        }
 
    }
    //cout<<min;
    fout<<min;
    for(i=1;i<=g;++i)
        if(ans[i])
            fout<<" "<<i;
            //cout<<" "<<i;
    //cout<<endl;
    fout<<endl;
    return 0;
}