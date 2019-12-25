#include<bits/stdc++.h>
#include<stdint.h>
using namespace std;
ifstream fin("date.in");
ofstream fout("date.out");
///set<pair<int128,int128> > s[2];
///set<pair<int128,int128> >::iterator it;
///pair<int128,int128> nr;
typedef __int128_t int128;
int128 i,n,st,ok,x;
int128 sol[4][4];
pair<int,int> op[101];
int128 k,m[4][4],aux[4][4],rep[4][4];
char c[1000];
/// a trebuit sa rulez pe compilator de codebloks pe net ca sa mearga __int128_t
int128 invmod(int128 x)
{
    int128 sol=1,aux=n-2;
    while(aux>0)
    {
        if(aux%2==1) sol=(sol*x)%n;
        x=(1ll*x*x)%n;
        aux/=2;
    }
    return sol;
}

void inm(int128 a[4][4], int128 b[4][4])
{
    int i,j,l;
    for(i=1;i<=2;i++)
        for(j=1;j<=2;j++)
        {
            rep[i][j]=0;
            for(l=1;l<=2;l++)
                rep[i][j]=(rep[i][j]+(a[i][l]*b[l][j])%n)%n;
        }
     for(i=1;i<=2;i++)
        for(j=1;j<=2;j++)
            a[i][j]=rep[i][j];
}

long long ridput(int128 rid,int128 poz)
{
    sol[1][1]=1;sol[1][2]=0;sol[2][1]=0;sol[2][2]=1;
    while(rid>0)
    {
        if(rid%2==1) inm(sol,m);
        inm(m,m);
        rid/=2;
    }

    return (poz*sol[1][1]+sol[1][2])%n;
}


int main()
{
    /*
    n=10007;
    for(i=0;i<n;i++) s[0].insert(make_pair(i+1,i));
    while(fin>>c)
    {
        if(c[0]=='d')
        {
            fin>>c;
            if(c[0]=='i')
            {
                fin>>c;fin>>c;
                while(!s[ok].empty())
                {
                    it=s[ok].begin();nr=*it;
                    s[ok].erase(it);
                    nr.first=-nr.first;
                    s[1-ok].insert(nr);
                }
                ok=1-ok;
            }
            else
            {
                fin>>c;
                fin>>x;st=0;
                while(!s[ok].empty())
                {
                    it=s[ok].begin();nr=*it;
                    s[ok].erase(it);
                    nr.first=st+1;
                    st+=x;st%=n;
                    s[1-ok].insert(nr);
                }
                ok=1-ok;
            }
        }
        else
        {
            fin>>x;
            if(x>0)
            {
                st=n-x+1;
                for(i=1;i<=x;i++)
                {
                    it=s[ok].begin();nr=*it;
                    s[ok].erase(it);
                    nr.first=st;st++;
                    s[1-ok].insert(nr);
                }st=1;
                while(!s[ok].empty())
                {
                    it=s[ok].begin();nr=*it;
                    s[ok].erase(it);
                    nr.first=st;st++;
                    s[1-ok].insert(nr);
                }
                ok=1-ok;
            }
            else
            {
                x=-x;st=x+1;
                for(i=1;i<=n-x;i++)
                {
                    it=s[ok].begin();nr=*it;
                    s[ok].erase(it);
                    nr.first=st;st++;
                    s[1-ok].insert(nr);
                }st=1;
                while(!s[ok].empty())
                {
                    it=s[ok].begin();nr=*it;
                    s[ok].erase(it);
                    nr.first=st;st++;
                    s[1-ok].insert(nr);
                }
                ok=1-ok;
            }
        }
    }
    st=0;
    for(auto it:s[ok])
    {
        st++;
        if(it.second==2019)
            fout<<st-1<<" ";
    }
    */
    int128 a;
    while(fin>>c)
    {
        if(c[0]=='d')
        {
            fin>>c;
            if(c[0]=='i')
            {
                fin>>c;fin>>c;
                op[++k].first=1;
            }
            else
            {
                fin>>c;fin>>x;
                op[++k].first=2;
                op[k].second=x;
            }
        }
        else
        {
            fin>>x;
            op[++k].first=3;
            op[k].second=x;
        }
    }

    n=119315717514047;
    ///f2(a)=(a*invmod(x))%mod;
    ///f3(a)=(x+a)%mod
    ///f1(a)=mod-1-a;
    ///initializare
    m[1][1]=1;m[1][2]=0;m[2][1]=0;m[2][2]=1;
    for(int j=1;j<=k;j++)
    {
        if(op[j].first==1)
        {
            aux[1][1]=-1;aux[1][2]=n-1;aux[2][1]=0;aux[2][2]=1;
            inm(m,aux);
        }
        else if(op[j].first==2)
        {
            aux[1][1]=invmod(op[j].second);aux[1][2]=0;aux[2][1]=0;aux[2][2]=1;
            inm(m,aux);
        }
        else if(op[j].first==3)
        {
            aux[1][1]=1;aux[1][2]=op[j].second;aux[2][1]=0;aux[2][2]=1;
            inm(m,aux);
        }
    }
    fout<<ridput(101741582076661,2020);
    return 0;
}

