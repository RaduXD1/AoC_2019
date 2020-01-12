#include <bits/stdc++.h>
using namespace std;
ifstream fin("date.in");
ofstream fout("date.out");
int n,b,i,sol,f[10000],a,v1,v2,ok,aux,nr,poz;
vector<int> v[10000];
map<string,int> m;
string s1,s2;
char c;
queue<int> q;
void bfs()
{
    q.push(1);f[1]=1;
    while(!q.empty())
    {
        int nod=q.front();q.pop();
        for(auto it:v[nod]) if(f[it]==0)
        {
            f[it]=f[nod]+1;
            if(it==2)
            {
                fout<<f[nod]-2;
                return;
            }
            q.push(it);
        }
    }
}
int main()
{
    //schimb imputul
    fin>>s1;
    m[s1]=1;
    fin>>s1;
    m[s1]=2;
    nr=2;
    fin>>n;
    for(i=1;i<=n;i++)
    {
        fin>>s1; fin>>c; fin>>s2;
        int a=m[s1];
        int b=m[s2];
        if(a==0) m[s1]=++nr,a=nr;
        if(b==0) m[s2]=++nr,b=nr;
        //fout<<a<<" "<<b<<"\n";
        v[a].push_back(b);
        v[b].push_back(a);
    }
    bfs();
    return 0;
}
