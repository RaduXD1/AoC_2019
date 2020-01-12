#include <bits/stdc++.h>
using namespace std;
ifstream fin("date.in");
ofstream fout("date.out");
long long n,b,i,sol,f[10000],a[10000],v1,v2,ok,aux,nr,poz;
int main()
{
    while(fin>>b) a[++n]=b;
    for(i=1;i<=n;i++)
    {
        aux=a[i];nr=0;
        for(ok=1;ok<=5;ok++) f[ok]=0;
        while(aux) f[++nr]=aux%10,aux/=10;
        if(f[1]==3) a[a[++i]+1]=5;
        else if(f[1]==4) fout<<a[a[++i]+1]<<"\n";
        else if(f[1]==2||f[1]==1||f[1]==7||f[1]==8)
        {
            if(f[3]==0) v1=a[a[++i]+1];
            else v1=a[++i];
            if(f[4]==0) v2=a[a[++i]+1];
            else v2=a[++i];
            poz=a[++i]+1;
            if(f[1]==1) a[poz]=v1+v2;
            if(f[1]==2) a[poz]=v1*v2;
            if(f[1]==7) a[poz]=(v1<v2);
            if(f[1]==8) a[poz]=(v1==v2);
        }
        else if(f[1]==5||f[1]==6)
        {
            if(f[3]==0) v1=a[a[++i]+1];
            else v1=a[++i];
            if(f[4]==0) v2=a[a[++i]+1];
            else v2=a[++i];
            if(f[1]==5&&v1!=0) i=v2;
            else if(f[1]==6&&v1==0) i=v2;
        }
        else break;
    }
    return 0;
}