#include<bits/stdc++.h>
using namespace std;
ifstream fin("date.in");
ofstream fout("date.out");
int n,f[10][30],i,nr,rez,x,y;
long long sol;
char c[100000],a;
int main()
{
    rez=1000000000;
    while(fin>>a) c[++n]=a;
    i=1;
    for(x=1;x<=6;x++) for(y=1;y<=25;y++) f[x][y]=2;
    while(i<=n)
    {
        /*rezolvare primul task
        f[0]=0;f[1]=0;f[2]=0;
        for(nr=1;nr<=25*6;i++,nr++)
            f[c[i]-'0']++;
        if(f[0]<rez)
        {
            rez=f[0];
            sol=1ll*f[1]*f[2];
        }
        */
        for(x=1;x<=6;x++) for(y=1;y<=25;y++,i++)
            if(f[x][y]==2) f[x][y]=c[i]-'0';
    }
    for(x=1;x<=6;x++,fout<<"\n") for(y=1;y<=25;y++) fout<<f[x][y];
    return 0;
}
