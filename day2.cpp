#include <bits/stdc++.h>
using namespace std;
ifstream fin("date.in");
ofstream fout("date.out");
long long n,b,i,sol,f[10000],a[10000],t2,t3;
int main()
{
    while(fin>>b) f[++n]=b;
    /*
    f[2]=12;f[3]=2;
    for(i=1;i<=n;i+=4)
    {
        if(f[i]==1) f[f[i+3]+1]=f[f[i+1]+1]+f[f[i+2]+1];
        else
        if(f[i]==2) f[f[i+3]+1]=f[f[i+1]+1]*f[f[i+2]+1];
        else
        if(f[i]==99) break;
    }
    fout<<f[1];
    */
    for(t2=0;t2<=99;t2++) for(t3=0;t3<=99;t3++)
    {
        for(i=1;i<=n;i++) a[i]=f[i];
        a[2]=t2;a[3]=t3;
        for(i=1;i<=n;i+=4)
        {
            if(a[i]==1) a[a[i+3]+1]=a[a[i+1]+1]+a[a[i+2]+1];
            else
            if(a[i]==2) a[a[i+3]+1]=a[a[i+1]+1]*a[a[i+2]+1];
            else
            if(a[i]==99) break;
        }
        if(a[1]==19690720)
        {
            fout<<t2*100+t3;
            return 0;
        }
    }
    return 0;
}