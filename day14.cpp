#include <bits/stdc++.h>
using namespace std;
ifstream fin("date.in");
ofstream fout("date.out");
long long n,f[10000],i,k,niv[1000],x,nr,l,ob[1000],am[1000];
map<string,long long> F;
vector<pair<long long,long long> > v[1000];
pair<long long,long long> s[1000];
string c;
long long st,dr,mid;
priority_queue<pair<long long,long long>, vector<pair<long long,long long> >, less<pair<long long,long long> > > solve;
void dfs(long long nod)
{
    f[nod]=1;
    for(auto it:v[nod])
        if(f[it.first]==0) dfs(it.first);
    k++;
    niv[nod]=k;
}

int main()
{
    fin>>n;
    ///am citit ORE si FUEL inainte ca sa stiu val in vectorul de frecventa
    fin>>c;F[c]=1;
    fin>>c;F[c]=2;
    nr=2;
    for(;n--;)
    {
        long long ok=0;
        while(ok==0)
        {
            fin>>x;
            fin>>c;
            if(c.back()==',') c.pop_back();
            else ok=1;
            if(F[c]==0) F[c]=++nr;
            s[++k]=make_pair(F[c],x);
        }
        fin>>c;
        fin>>x;fin>>c;
        if(F[c]==0) F[c]=++nr;l=F[c];
        for(i=1;i<=k;i++) v[l].push_back(s[i]);k=0;
        ob[l]=x;

    }
    dfs(2);
 //   for(i=1;i<=nr;i++) fout<<niv[i]<<"\n";
    ///dr-ul e un numar randome care da rez mai mare de un trilion
    ///st-ul e rez de la punctul anterior impartit la un trilion
    st=7311491;dr=8311491;
    while(st<=dr)
    {
        mid=(st+dr)/2;
        am[2]=mid;
        solve.push(make_pair(niv[2],2));
        while(!solve.empty())
        {
            long long nod=solve.top().second;solve.pop();
            long long cant=am[nod]/ob[nod]+bool(am[nod]%ob[nod]);
            am[nod]=0;
            for(auto it:v[nod])
            {
                if(am[it.first]==0&&it.first!=1) solve.push(make_pair(niv[it.first],it.first));
                am[it.first]+=cant*it.second;
            }
        }
        if(am[1]<1000000000000)
            st=mid+1;
        else if(am[1]>1000000000000)
            dr=mid-1;
        else break;
        for(i=0;i<=nr+10;i++) am[i]=0;
        //fout<<am[1]<<"\n";
    }
    fout<<mid;
    return 0;
}
