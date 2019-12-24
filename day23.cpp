#include <bits/stdc++.h>
using namespace std;
ifstream fin("date.in");
ofstream fout("date.out");
long long n,b,i,sol,f[100],a[50][10000],v1,v2,ok,aux,nr,poz,base[50];
long long rez,op,pp[50],x,y,vv;
queue<long long> q[50];

long long progress(long long &base, long long a[], long long &i, long long robot)
{
    for(;i<=n;i++)
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
            if(q[robot].empty())
            {
                a[poz]=-1;
                i++;
                return 0;
            }
            else
            {
                a[poz]=q[robot].front();
                q[robot].pop();
            }
            //fout<<"IN:"<<a[poz]<<"\n";
        }
        else if(f[1]==4)
        {
            if(f[3]==0) poz=a[++i]+1;
            else if(f[3]==1) poz=++i;
            else if(f[3]==2) poz=a[++i]+base;
            vv=1;
            if(op==-1)
                op=a[poz];
            else
            {   rez++;
                if(op!=255) q[op].push(a[poz]);
                else {
                    if(rez==2)
                        y=a[poz];
                    else
                        x=a[poz];
                }
                if(rez==2) op=-1,rez=0;
            }
            //fout<<"OUT:"<<a[poz]<<"\n";
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
    return 0;
}

int main()
{
    while(fin>>b)
    {
        n++;
        for(i=0;i<=49;i++) a[i][n]=b;
    }
    for(i=0;i<=49;i++){
       base[i]=1;
       pp[i]=1;
       q[i].push(i);
    }
    long long verif=0;op=-1;rez=0;
    map<long long, int> Y;
    while(true)
    {
        vv=0;
        for(i=0;i<=49;i++)
        {
            //fout<<i<<"\n";
            progress(base[i],a[i],pp[i],i);
            //fout<<"\n";
        }
        if(vv==0)
        {
            if(verif!=0)
            {
                q[0].push(x);
                q[0].push(y);
                if(Y[y]==1)
                {
                    fout<<y;
                    return 0;
                }
                Y[y]=1;
            }
            verif++;
        }
    }
    return 0;
}
