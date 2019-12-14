#include <bits/stdc++.h>
using namespace std;
ifstream fin("date.in");
ofstream fout("date.out");
long long n,b,i,sol,f[1000],a[100000],v1,v2,ok,aux,nr,poz,base,pi,pj,si,sj,pop;
long long v[100000],k,x,y,z,rep,o[100000];
long long m[10000][10000];
long long d,di[4]={1,-1,-1,1};
long long dj[4]={1,1,-1,-1};
int main()
{
    while(fin>>b) a[++n]=b;
    base=1;
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
            //fout<<pi<<" "<<pj<<" "<<si<<" "<<sj<<"\n";
            //fout<<k<<"\n";
            if(pi<si) o[rep+1]=-1;
            if(pi==si) o[rep+1]=0;
            if(pi>si) o[rep+1]=1;
            pop++;
            //fout<<o[rep+1]<<"\n";
            rep++;
            //fout<<o[rep]<<"\n";
            a[poz]=o[rep];
        }
        else if(f[1]==4)
        {
            if(f[3]==0) poz=a[++i]+1;
            else if(f[3]==1) poz=++i;
            else if(f[3]==2) poz=a[++i]+base;
            v[++k]=a[poz];
            //fout<<k<<"\n";
            if(a[poz]==4&&k%3==0)
            {
                pi=v[k-2],pj=v[k-1];
            }
            if(a[poz]==3&&k%3==0)
                si=v[k-2],sj=v[k-1];
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
    long long score=0;
    for(i=1;i<=k;i+=3)
    {
        x=v[i];y=v[i+1];z=v[i+2];
        if(x!=-1)
        {
            m[y][x]=z;
            if(z==2) sol++;
        }
        else score=max(score,z);

        //fout<<i<<"   "<<x<<" "<<y<<" "<<z<<"\n";
        /*
        if(i>=2647&&i%2==1)
        {
            for(int ii=0;ii<=19;ii++,fout<<"\n")
                for(int j=0;j<=43;j++)
                    fout<<m[ii][j];
            fout<<"\n\n";
        }
        */
    }
    fout<<rep<<"\n";
    fout<<score<<"\n";
    fout<<sol<<"\n";
    for(i=0;i<=19;i++,fout<<"\n")
        for(int j=0;j<=43;j++)
            fout<<m[i][j];
    return 0;
}
