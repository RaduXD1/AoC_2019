#include <bits/stdc++.h>
using namespace std;
ifstream fin("date.in");
ofstream fout("date.out");
long long n,b,i,sol,f[100],a[10000],v1,v2,ok,aux,nr,poz,base,rsp,j,pp;
int m[10000][10000],z[10000][10000],d;
int di[]={1,0,-1,0};
int dj[]={0,1,0,-1};
int main()
{
    while(fin>>b) a[++n]=b;
    base=1;
    int x=5000,y=5000;
    m[x][y]=1;
    for(i=1;i<=n;i++)
    {
        aux=a[i];nr=0;
        for(ok=1;ok<=7;ok++) f[ok]=0;
        while(aux) f[++nr]=aux%10,aux/=10;
        if(f[1]==9&&f[2]==9) break;
        if(f[1]==3)
        {
            if(f[3]==0) poz=a[++i]+1;
            else if(f[3]==1) poz=++i;
            else if(f[3]==2) poz=a[++i]+base;
            if(m[x][y]==0) a[poz]=0;
            else a[poz]=1;
        }
        else if(f[1]==4)
        {
            if(f[3]==0) poz=a[++i]+1;
            else if(f[3]==1) poz=++i;
            else if(f[3]==2) poz=a[++i]+base;
            if(pp==0)
            {
                m[x][y]=a[poz];
                if(z[x][y]==0) rsp++;
                z[x][y]=1;
            }
            else
            {
                if(a[poz]==0) d--;
                else d++;
                if(d==-1) d=3;
                if(d==4) d=0;
                x+=di[d];
                y+=dj[d];
            }
            fout<<a[poz]<<" ";
            if(pp==1) fout<<"\n";
            pp=1-pp;
        }
        else if(f[1]==2||f[1]==1||f[1]==7||f[1]==8)
        {
            if(f[3]==0) v1=a[a[++i]+1];
            else if(f[3]==1) v1=a[++i];
            else v1=a[a[++i]+base];

            if(f[4]==0) v2=a[a[++i]+1];
            else if(f[4]==1) v2=a[++i];
            else v2=a[a[++i]+base];

            if(f[5]==0) poz=a[++i]+1;
            else if(f[5]==1) poz=++i;
            else if(f[5]==2) poz=a[++i]+base;

            if(f[1]==1) a[poz]=v1+v2;
            if(f[1]==2) a[poz]=v1*v2;
            if(f[1]==7) a[poz]=(v1<v2);
            if(f[1]==8) a[poz]=(v1==v2);
        }
        else if(f[1]==5||f[1]==6)
        {
            if(f[3]==0) v1=a[a[++i]+1];
            else if(f[3]==1) v1=a[++i];
            else v1=a[a[++i]+base];

            if(f[4]==0) v2=a[a[++i]+1];
            else if(f[4]==1) v2=a[++i];
            else v2=a[a[++i]+base];

            if(f[1]==5&&v1!=0) i=v2;
            else if(f[1]==6&&v1==0) i=v2;
        }
        else if(f[1]==9)
        {
            if(f[3]==0) v1=a[a[++i]+1];
            else if(f[3]==1) v1=a[++i];
            else v1=a[a[++i]+base];
            base+=v1;
        }
    }
    for(i=4500;i<=5500;i++,fout<<"\n")
        for(j=4500;j<=5500;j++) fout<<m[i][j];

    //fout<<rsp;
    return 0;
}
