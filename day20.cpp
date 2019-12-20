#include <bits/stdc++.h>
using namespace std;
ifstream fin("date.in");
ofstream fout("date.out");
char c;
int n,m,aux,v[200][200],i,j,iv,jv,d,dp[500][200][200],ok,pi,pj,nr,f[30][30],urm,poz;
int di[]={-1,1,0,0};
int dj[]={0,0,-1,1};
pair<int,int> paux;
struct stare{int i;int j;int level;};
queue<stare> q;
vector<pair<int,int> > p[700];
int main()
{
    for(i=1;i<=26;i++)
        for(j=i;j<=26;j++)
            f[i][j]=f[j][i]=++nr;
    n=1;// am pus / la finalul fiecarei linii pt a putea citii spatile
    while(fin.get(c))
    {
        if(c=='\n') n++,m=0;
        else if(c==' ') v[n][++m]=-1;
        else if(c=='#') v[n][++m]=-1;
        else if(c=='.') v[n][++m]=0;
        else if(c>='A'&&c<='Z') v[n][++m]=c-'A'+1;
        aux=max(aux,m);
    }n--;m=aux;
    for(i=1;i<=n;i++) for(j=1;j<=m;j++)
        if(v[i][j]>0)
        {
            ok=0;
            for(d=0;d<=3;d++)
            {
                iv=i+di[d];
                jv=j+dj[d];
                if(iv>=1&&iv<=n&&jv>=1&&jv<=m&&v[iv][jv]==0) ok=1,pi=iv,pj=jv;
            }
            if(ok==1)
            {
                for(d=0;d<=3;d++)
                {
                    iv=i+di[d];
                    jv=j+dj[d];
                    if(iv>=1&&iv<=n&&jv>=1&&jv<=m&&v[iv][jv]>0)
                    {
                        v[pi][pj]=f[v[i][j]][v[iv][jv]];
                        v[iv][jv]=-1;v[i][j]=-1;
                        p[v[pi][pj]].push_back(make_pair(pi,pj));
                        break;
                    }
                }
            }
        }
    //for(i=1;i<=n;i++,fout<<"\n")
    //    for(j=1;j<=m;j++) fout<<v[i][j]<<" ";
    pi=p[1][0].first;pj=p[1][0].second;
    dp[0][pi][pj]=1;
    q.push({pi,pj,0});
    //fout<<pi<<" "<<pj<<"\n";
    while(!q.empty())
    {
        i=q.front().i;
        j=q.front().j;
        poz=q.front().level;
        q.pop();
        if(v[i][j]==351&&poz==0)
        {
            //for(i=1;i<=n;i++,fout<<"\n")
            //    for(j=1;j<=m;j++) fout<<dp[i][j]<<" ";
            fout<<dp[0][i][j]-1;
            return 0;
        }
        if(v[i][j]>0&&v[i][j]!=1&&v[i][j]!=351)
        {
            paux.first=i;paux.second=j;
            for(auto it:p[v[i][j]]) if(it!=paux){paux=it;break;}
            iv=paux.first;jv=paux.second;
            if(iv==3||iv==n-2||jv==3||jv==m-2) urm=1;
            else urm=-1;
            if(urm+poz>=0&&dp[poz+urm][iv][jv]==0)
            {
                dp[poz+urm][iv][jv]=dp[poz][i][j]+1;
                q.push({iv,jv,poz+urm});
            }
        }
        for(d=0;d<=3;d++)
        {
            iv=i+di[d];
            jv=j+dj[d];
            if(v[iv][jv]>=0&&dp[poz][iv][jv]==0)
            {
                q.push({iv,jv,poz});
                dp[poz][iv][jv]=dp[poz][i][j]+1;
            }
        }
    }
    return 0;
}
