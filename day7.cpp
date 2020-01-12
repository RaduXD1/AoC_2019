#include <bits/stdc++.h>
using namespace std;
ifstream fin("solva.in");
ofstream fout("solve.out");
long long n,b,i,sol,f[10000],a[6][10000],v1,v2,v3,v4,v5,ok,aux,nr,poz,v[10000],ph[10];
long long maxi,p1,p2,p3,p4,p5;
long long solv(long long ap,long long ps,int p,long long &i)
{
    for(i++;i<=n;i++)
    {
        //fout<<i<<" ";
        aux=a[p][i];nr=0;
        for(ok=1;ok<=5;ok++) f[ok]=0;
        while(aux) f[++nr]=aux%10,aux/=10;
        if(f[1]==3)
        {
            if(ph[p]==0) a[p][a[p][++i]+1]=ap,ph[p]=1;
            else a[p][a[p][++i]+1]=ps;
        }
        else if(f[1]==4) return a[p][a[p][++i]+1];
        else if(f[1]==2||f[1]==1||f[1]==7||f[1]==8)
        {
            if(f[3]==0) v1=a[p][a[p][++i]+1];
            else v1=a[p][++i];
            if(f[4]==0) v2=a[p][a[p][++i]+1];
            else v2=a[p][++i];
            poz=a[p][++i]+1;
            if(f[1]==1) a[p][poz]=v1+v2;
            if(f[1]==2) a[p][poz]=v1*v2;
            if(f[1]==7) a[p][poz]=(v1<v2);
            if(f[1]==8) a[p][poz]=(v1==v2);
        }
        else if(f[1]==5||f[1]==6)
        {
            if(f[3]==0) v1=a[p][a[p][++i]+1];
            else v1=a[p][++i];
            if(f[4]==0) v2=a[p][a[p][++i]+1];
            else v2=a[p][++i];
            if(f[1]==5&&v1!=0) i=v2;
            else if(f[1]==6&&v1==0) i=v2;
        }
        else break;
    }
    return -1;
}
int main()
{
    while(fin>>b) v[++n]=b;
    for(int v1=5;v1<=9;v1++)for(int v2=5;v2<=9;v2++)for(int v3=5;v3<=9;v3++)for(int v4=5;v4<=9;v4++)for(int v5=5;v5<=9;v5++)
        if(v1!=v2&&v1!=v3&&v1!=v4&&v1!=v5&&v2!=v3&&v2!=v4&&v2!=v5&&v3!=v4&&v3!=v5&&v4!=v5)
        {
            long long st=0;
            p1=p2=p3=p4=p5=0;
            for(int i=1;i<=n;i++) a[1][i]=a[2][i]=a[3][i]=a[4][i]=a[5][i]=v[i];
            ph[1]=ph[2]=ph[3]=ph[4]=ph[5]=0;
            while(true)
            {
                st=solv(v1,st,1,p1);
                if(st==-1) break;
                st=solv(v2,st,2,p2);
                st=solv(v3,st,3,p3);
                st=solv(v4,st,4,p4);
                st=solv(v5,st,5,p5);
                //fout<<st<<"\n";
                maxi=max(maxi,st);
            }
        }
    fout<<maxi;
    return 0;
}
