#include <bits/stdc++.h>
using namespace std;
ifstream fin("date.in");
ofstream fout("date.out");
int n,a,i,sol;
int main()
{
    fin>>n;
    for(i=1;i<=n;i++)
    {
        fin>>a;a/=3;a-=2;
        while(a>0)
        {
            sol+=a;
            a/=3;a-=2;
        }
    }
    fout<<sol;
    return 0;
}