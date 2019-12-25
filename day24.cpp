#include <bits/stdc++.h>
using namespace std;
ifstream fin("date.in");
ofstream fout("date.out");
string s,r;
map<string,int> m;
int i,j,b,poz;
char c[1010][6][6],aux[1010][6][6];
int h,l,nr;
int main()
{
    /*
    for(i=1;i<=5;i++)
    {
        fin>>s;
        r+=s;
    }
    while(true)
    {
        if(m[r]==1) break;
        m[r]=1;
        poz=-1;s=r;
        for(i=0;i<=4;i++) for(j=0;j<=4;j++)
        {
            poz++;b=0;
            if(i!=0) if(r[poz-5]=='#') b++;
            if(i!=4) if(r[poz+5]=='#') b++;
            if(j!=0) if(r[poz-1]=='#') b++;
            if(j!=4) if(r[poz+1]=='#') b++;
            if(r[poz]=='#')
            {
                if(b==1) s[poz]='#';
                else s[poz]='.';
            }
            else
            {
                if(b<=2&&b>=1) s[poz]='#';
                else s[poz]='.';
            }
        }
        r=s;

    }
    long long sol=0;
    poz=-1;s=r;
    for(i=0;i<=4;i++) for(j=0;j<=4;j++)
        if(r[++poz]=='#') sol+=(1<<poz);
    fout<<sol;
    */
    for(h=1;h<=1000;h++) for(i=1;i<=5;i++) for(j=1;j<=5;j++) c[h][i][j]='.';
    for(i=1;i<=5;i++) fin>>c[500][i]+1;
    int k=200;
    for(;k--;)
    {
        nr=0;
        for(h=1;h<=1000;h++) for(i=1;i<=5;i++) for(j=1;j<=5;j++) aux[h][i][j]='.';
        for(h=2;h<999;h++)
        {
            for(i=1;i<=5;i++) for(j=1;j<=5;j++) if(i!=3||j!=3)
            {
                b=0;
                if(i==1) if(c[h-1][2][3]=='#') b++;
                if(i==5) if(c[h-1][4][3]=='#') b++;
                if(j==1) if(c[h-1][3][2]=='#') b++;
                if(j==5) if(c[h-1][3][4]=='#') b++;
                if(c[h][i-1][j]=='#') b++;
                if(c[h][i][j+1]=='#') b++;
                if(c[h][i+1][j]=='#') b++;
                if(c[h][i][j-1]=='#') b++;
                if(i==2&&j==3) for(l=1;l<=5;l++) if(c[h+1][1][l]=='#') b++;
                if(i==4&&j==3) for(l=1;l<=5;l++) if(c[h+1][5][l]=='#') b++;
                if(i==3&&j==2) for(l=1;l<=5;l++) if(c[h+1][l][1]=='#') b++;
                if(i==3&&j==4) for(l=1;l<=5;l++) if(c[h+1][l][5]=='#') b++;
                if(c[h][i][j]=='#')
                {
                    if(b==1) aux[h][i][j]='#',nr++;
                    else aux[h][i][j]='.';
                }
                else
                {
                    if(b<=2&&b>=1)  aux[h][i][j]='#',nr++;
                    else aux[h][i][j]='.';
                }
            }
        }
        for(h=1;h<=1000;h++) for(i=1;i<=5;i++) for(j=1;j<=5;j++) c[h][i][j]=aux[h][i][j];
    }
    for(h=495;h<=505;h++,fout<<"\n")for(i=1;i<=5;i++,fout<<"\n") for(j=1;j<=5;j++) fout<<c[h][i][j]<<" ";
    fout<<nr;
    return 0;
}
