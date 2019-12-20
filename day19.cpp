#include <bits/stdc++.h>
using namespace std;
ifstream fin("date.in");
ofstream fout("date.out");
long long n,b,i,sol,f[100],a[10000],v[10000],v1,v2,ok,aux,sep,nr,poz,base,x,y,j,l[10100],st[10100];
int m[10001][10001],co,c[4],pi,pj,ai,aj;
int main()
{
    while(fin>>b) v[++n]=b;
    pj=5;pi=4;
    while(true)
    {
        x=pi;y=pj;
        for(i=1;i<=n;i++) a[i]=v[i];
        base=1;
        c[0]=x;c[1]=y;co=0;
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
                a[poz]=c[co];co++;
            }
            else if(f[1]==4)
            {
                if(f[3]==0) poz=a[++i]+1;
                else if(f[3]==1) poz=++i;
                else if(f[3]==2) poz=a[++i]+base;
                m[y][x]=a[poz];
                l[y]+=a[poz];
                sol=a[poz];
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
        if(sol==1&&sep==0)
        {
            sep=1;
            ai=pi;aj=pj;
            st[aj]=ai;
            pi++;
        }
        else if(sol==0&&sep==1)
        {
            sep=0;
            if(l[aj]>=100)
            {
                if(st[aj-99]<=st[aj]&&l[aj-99]-st[aj]+st[aj-99]>=100)
                {
                    x=st[aj];
                    y=aj-99;
                    //fout<<st[aj-99]<<" "<<st[aj]<<" "<<l[aj-99]<<"\n";
                    fout<<x*10000+y<<"\n";
                    //for(i=y;i<=y+99;i++) for(j=x;j<=x+99;j++) m[i][j]+=2;
                    //for(i=0;i<=y+120;i++,fout<<"\n") for(j=0;j<=3000;j++) fout<<m[i][j];
                    return 0;
                }
            }
            pi=ai;pj=aj+1;
        } else pi++;
        if(pj>3099) break;

    }
    //fout<<sol;
    for(i=0;i<=199;i++,fout<<"\n") for(j=0;j<=199;j++) fout<<m[i][j];
    for(i=1;i<=200;i++)
    {
        fout<<i-1<<".  "<<l[i-1]<<" "<<st[i-1]<<"\n";
        //if(i%10==0) fout<<"\n";
    }
    return 0;
}
