#include <bits/stdc++.h>
using namespace std;
ifstream fin("date.in");
ofstream fout("date.out");
long long n,b,i,sol,f[100],a[10000],v1,v2,ok,aux,nr,poz,base,k,d,fr[2000][2000],col[2000][2000],x1,x2,x;
pair<int,int> com[10000];
int di[]={-1,0,1,0};
int dj[]={0,1,0,-1};
int main()
{
    while(fin>>b) a[++n]=b;
    base=1;int cont=0,sol=0;
    x1=1000;x2=1000;d=0;
    col[x1][x2]=1;x=1;
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
            a[poz]=x;
        }
        else if(f[1]==4)
        {
            if(f[3]==0) poz=a[++i]+1;
            else if(f[3]==1) poz=++i;
            else if(f[3]==2) poz=a[++i]+base;
            //fout<<a[poz]<<"\n";
            if(cont==0) com[++k].first=a[poz];
            if(cont==1) com[k].second=a[poz];
            cont=1-cont;
            if(cont==0)
            {
                if(fr[x1][x2]==0) sol++;fr[x1][x2]=1;
                if(com[k].second==1) d++;
                else d--;
                col[x1][x2]=com[k].first;
                if(d==4) d=0;
                if(d==-1) d=3;
                x1+=di[d];
                x2+=dj[d];
                if(col[x1][x2]==1) x=1;
                else x=0;
            }
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
    for(i=800;i<=1200;i++,fout<<"\n") for(int j=800;j<=1200;j++) fout<<col[i][j];
    fout<<sol;
    return 0;
}
