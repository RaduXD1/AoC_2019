#include <bits/stdc++.h>
using namespace std;
ifstream fin("date.in");
ofstream fout("date.out");
char c[1000][1000];
int n,m,i,j,iv,jv,d,pi[5],pj[5],ok,sol,k,kv,poz,nr[5];
int f[100],x[100],y[100];
int di[]={0,0,-1,1};
int dj[]={-1,1,0,0};
map<int,int> dp[100][100];
struct qu{int i;int j;int k;};
queue<qu> q;
int main()
{
    while(fin>>c[++n]+1);n--;
    for(i=1;c[1][i];i++) m++;
    for(i=1;i<=n;i++) for(j=1;j<=m;j++)
    {
        if(i>n/2+1) poz=3; else poz=1;
        if(j>m/2+1) poz+=1; else poz+=0;
        if(c[i][j]=='@') pi[poz]=i,pj[poz]=j,c[i][j]='.';
        if(c[i][j]>='a'&&c[i][j]<='z')
        {
            if(f[c[i][j]-'a']!=poz&&f[c[i][j]-'a']!=0)
                c[x[c[i][j]-'a']][y[c[i][j]-'a']]='.';
            nr[poz]+=(1<<(c[i][j]-'a'));
            f[c[i][j]-'a']=poz;
        }
        else if(c[i][j]>='A'&&c[i][j]<='Z')
        {
            if(f[c[i][j]-'A']!=poz&&f[c[i][j]-'A']!=0)
                c[i][j]='.';
            else
            {
                f[c[i][j]-'A']=poz;
                x[c[i][j]-'A']=i;
                y[c[i][j]-'A']=j;
            }
        }
    }
    //fout<<pi[1]<<" "<<pj[1]<<"\n";
    //for(i=1;i<=n/2+1;i++,fout<<"\n")
     //   for(j=1;j<=m/2+1;j++) fout<<c[i][j];
    //fout<<nr[1]<<"\n";
    for(int h=1;h<=4;h++)
    {
        while(!q.empty()) q.pop();
        dp[pi[h]][pj[h]][0]=1;
        q.push({pi[h],pj[h],0});
        ok=0;
        while(!q.empty()&&ok==0)
        {
            i=q.front().i;
            j=q.front().j;
            k=q.front().k;
            //fout<<i<<" "<<j<<" "<<k<<" ->"<<dp[i][j][k]<<"\n";
            q.pop();
            for(d=0;d<=3;d++)
            {
                iv=i+di[d];
                jv=j+dj[d];
                if(c[iv][jv]=='.'&&dp[iv][jv][k]==0)
                {
                    q.push({iv,jv,k});
                    dp[iv][jv][k]=dp[i][j][k]+1;
                }
                else if(c[iv][jv]>='a'&&c[iv][jv]<='z'&&dp[iv][jv][k]==0)
                {
                    if((k&(1<<(c[iv][jv]-'a')))==0)
                    {
                        kv=k+(1<<(c[iv][jv]-'a'));
                        if(dp[iv][jv][kv]==0)
                        {
                            q.push({iv,jv,kv});
                            dp[iv][jv][kv]=dp[i][j][k]+1;
                            if(kv==nr[h])
                            {
                                sol+=dp[i][j][k];
                                ok=1;
                                break;
                            }
                        }
                    }
                    else
                    {
                        dp[iv][jv][k]=dp[i][j][k]+1;
                        q.push({iv,jv,k});
                    }
                }
                else if(c[iv][jv]>='A'&&c[iv][jv]<='Z'&&dp[iv][jv][k]==0)
                {
                    if((k&(1<<(c[iv][jv]-'A'))))
                    {
                        q.push({iv,jv,k});
                        dp[iv][jv][k]=dp[i][j][k]+1;
                    }
                }
            }
        }
    }
    fout<<sol;
    return 0;
}

/*
while(fin>>c[++n]+1);n--;
    for(i=1;c[1][i];i++) m++;
    for(i=1;i<=n;i++) for(j=1;j<=m;j++)
        if(c[i][j]=='@') pi=i,pj=j,c[i][j]='.';
    dp[pi][pj][0]=1;
    q.push({pi,pj,0});
    while(!q.empty()&&ok==0)
    {
        i=q.front().i;
        j=q.front().j;
        k=q.front().k;
        //fout<<i<<" "<<j<<" "<<k<<" ->"<<dp[i][j][k]<<"\n";
        q.pop();
        for(d=0;d<=3;d++)
        {
            iv=i+di[d];
            jv=j+dj[d];
            if(c[iv][jv]=='.'&&dp[iv][jv][k]==0)
            {
                q.push({iv,jv,k});
                dp[iv][jv][k]=dp[i][j][k]+1;
            }
            else if(c[iv][jv]>='a'&&c[iv][jv]<='z'&&dp[iv][jv][k]==0)
            {
                if((k&(1<<(c[iv][jv]-'a')))==0)
                {
                    kv=k+(1<<(c[iv][jv]-'a'));
                    if(dp[iv][jv][kv]==0)
                    {
                        q.push({iv,jv,kv});
                        dp[iv][jv][kv]=dp[i][j][k]+1;
                        if(kv==(1<<('z'-'a'))-1)
                        {
                            fout<<dp[i][j][k];
                            ok=1;
                            break;
                        }
                    }
                }
                else
                {
                    dp[iv][jv][k]=dp[i][j][k]+1;
                    q.push({iv,jv,k});
                }
            }
            else if(c[iv][jv]>='A'&&c[iv][jv]<='Z'&&dp[iv][jv][k]==0)
            {
                if((k&(1<<(c[iv][jv]-'A'))))
                {
                    q.push({iv,jv,k});
                    dp[iv][jv][k]=dp[i][j][k]+1;
                }
            }
        }
    }
    return 0;
*/
