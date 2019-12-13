#include <bits/stdc++.h>
using namespace std;
ifstream fin("date.in");
ofstream fout("date.out");
long long c[4][5],v[4][5],aux[4][5],i,j,h,l,pot,kin,sol[4],ok,mc,dc;
long long cmmdc(long long a, long long b)
{
    long long c;
    while(b)
    {
        c=a%b;
        a=b;
        b=c;
    }
    return a;
}

int mod(long long r)
{
    if(r<0) return -r;
    return r;
}
int main()
{
    fin>>c[1][1]>>c[2][1]>>c[3][1];
    fin>>c[1][2]>>c[2][2]>>c[3][2];
    fin>>c[1][3]>>c[2][3]>>c[3][3];
    fin>>c[1][4]>>c[2][4]>>c[3][4];
    for(i=1;i<=4;i++) for(h=1;h<=3;h++) aux[h][i]=c[h][i];
    while(true)
    {
        h=1;
        for(i=1;i<=4;i++)
            for(j=i+1;j<=4;j++)
                {
                    if(c[h][i]>c[h][j]) v[h][i]--,v[h][j]++;
                    if(c[h][i]<c[h][j]) v[h][i]++,v[h][j]--;
                }
        for(i=1;i<=4;i++) c[h][i]+=v[h][i];
        ok=0;
        for(i=1;i<=4;i++) if(aux[h][i]!=c[h][i]||v[h][i]!=0)
        {
            ok=1;
            break;
        }
        sol[h]++;
        if(ok==0) break;
    }
    while(true)
    {
        h=2;
        for(i=1;i<=4;i++)
            for(j=i+1;j<=4;j++)
                {
                    if(c[h][i]>c[h][j]) v[h][i]--,v[h][j]++;
                    if(c[h][i]<c[h][j]) v[h][i]++,v[h][j]--;
                }
        for(i=1;i<=4;i++) c[h][i]+=v[h][i];
        ok=0;
        for(i=1;i<=4;i++) if(aux[h][i]!=c[h][i]||v[h][i]!=0)
        {
            ok=1;
            break;
        }
        sol[h]++;
        if(ok==0) break;
    }
    while(true)
    {
        h=3;
        for(i=1;i<=4;i++)
            for(j=i+1;j<=4;j++)
                {
                    if(c[h][i]>c[h][j]) v[h][i]--,v[h][j]++;
                    if(c[h][i]<c[h][j]) v[h][i]++,v[h][j]--;
                }
        for(i=1;i<=4;i++) c[h][i]+=v[h][i];
        ok=0;
        for(i=1;i<=4;i++) if(aux[h][i]!=c[h][i]||v[h][i]!=0)
        {
            ok=1;
            break;
        }
        sol[h]++;
        if(ok==0) break;
    }
    fout<<sol[1]<<" "<<sol[2]<<" "<<sol[3]<<"\n";
    /*
    for(i=1;i<=4;i++)
    {
        pot=kin=0;
        for(h=1;h<=3;h++)
        {
            pot+=mod(c[h][i]);
            kin+=mod(v[h][i]);
        }
        sol+=pot*kin;
    }
    */
    dc=cmmdc(sol[1],sol[2]);
    mc=sol[1]*sol[2]/dc;
    fout<<mc<<"\n";
    dc=cmmdc(sol[3],mc);
    mc=mc*sol[3]/dc;
    fout<<mc;
    return 0;
}
