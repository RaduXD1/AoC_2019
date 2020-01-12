#include <bits/stdc++.h>
using namespace std;
ifstream fin("date.in");
ofstream fout("date.out");
int a,b,i,aux,ok,nr,sol,sp;

int main()
{
    fin>>a>>b;
    for(i=a;i<=b;i++)
    {
        ok=0;aux=i;nr=10;sp=0;
        while(aux)
        {
            if(aux%10==nr&&sp==0) ok++,sp=1;
            else if(aux%10==nr&&sp==1) ok--,sp=2;
            else if(aux%10!=nr) sp=0;
            if(aux%10>nr){ok=0;break;}
            nr=aux%10;
            aux/=10;
        }
        if(ok) sol++;
    }
    fout<<sol;
    return 0;
}