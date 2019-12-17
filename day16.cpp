#include <bits/stdc++.h>
//#define fin cin
//#define fout cout
using namespace std;
ifstream fin("date.in");
ofstream fout("date.out");
char c[10000];
int i,j,h,nr,s[5],v[7000000],aux[7000000],n,t;
short d[30000][30000];

int main()
{
    fin>>c;
    for(j=1;j<=10000;j++) for(i=0;c[i];i++) v[++n]=c[i]-'0';
    /*
    s[0]=0;s[1]=1;s[2]=0;s[3]=-1;
    for(i=1;i<=n;i++)
    {
        nr=-1;
        for(j=0;j<=n;j+=i)
        {
            ++nr;nr%=4;
            for(h=0;h<i;h++) d[i][j+h]=s[nr];
        }
    }
    //for(i=1;i<=n;i++,fout<<"\n")
     //   for(j=1;j<=n;j++) fout<<d[i][j]<<" ";
    t=100;
    for(;t--;)
    {
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=n;j++)
                aux[i]+=d[i][j]*v[j];
            if(aux[i]<0) aux[i]=-aux[i];
            aux[i]%=10;
        }
        for(i=1;i<=n;i++) v[i]=aux[i],aux[i]=0;
    }
    //fout<<n<<"\n";
    */
    int x=5970157+1;
    t=100;
    for(;t--;)
    {
        for(i=n;i>=x;i--)
        {
            aux[i]=aux[i+1]+v[i];
            if(aux[i]<0) v[i]=(-aux[i])%10;
            else v[i]=aux[i]%10;
        }
    }
    for(i=x;i<=x+7;i++) fout<<v[i];
    return 0;
}
