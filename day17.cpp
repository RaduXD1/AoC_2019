#include <bits/stdc++.h>
using namespace std;
ifstream fin("date.in");
ofstream fout("date.out");
long long n,b,i,sol,f[100],a[10000],v1,v2,ok,aux,nr,poz,base,k,x,y,j,rez;
char c[100000],v[1000][1000],U[100000];
int pi,pj,si,sj,di,dj,diri[4][2],dirj[4][2],t,u;
pair<char,int> ini[1000];
int main()
{
    fin>>U;
    for(i=0;U[i];i++) if(U[i]=='d') U[i]=10;u=-1;
    while(fin>>b) a[++n]=b;
    base=1;
    for(i=1;i<=n;i++)
    {
        aux=a[i];nr=0;
        for(ok=1;ok<=7;ok++) f[ok]=0;
        while(aux) f[++nr]=aux%10,aux/=10;
        if(f[1]==9&&f[2]==9) break;
        if(f[1]==3)
        {
            if(f[3]==0) poz=a[++i]+1;
            else if(f[3]==1) poz=++i;
            else if(f[3]==2) poz=a[++i]+base;
            a[poz]=U[++u];
            //a[poz]=0;
        }
        else if(f[1]==4)
        {
            if(f[3]==0) poz=a[++i]+1;
            else if(f[3]==1) poz=++i;
            else if(f[3]==2) poz=a[++i]+base;
            if(a[poz]>256) rez=a[poz];
            else c[++k]=a[poz];
        }
        else if(f[1]==2||f[1]==1||f[1]==7||f[1]==8)
        {
            if(f[3]==0) v1=a[a[++i]+1];
            else if(f[3]==1) v1=a[++i];
            else v1=a[a[++i]+base];

            if(f[4]==0) v2=a[a[++i]+1];
            else if(f[4]==1) v2=a[++i];
            else v2=a[a[++i]+base];

            if(f[5]==0) poz=a[++i]+1;
            else if(f[5]==1) poz=++i;
            else if(f[5]==2) poz=a[++i]+base;

            if(f[1]==1) a[poz]=v1+v2;
            if(f[1]==2) a[poz]=v1*v2;
            if(f[1]==7) a[poz]=(v1<v2);
            if(f[1]==8) a[poz]=(v1==v2);
        }
        else if(f[1]==5||f[1]==6)
        {
            if(f[3]==0) v1=a[a[++i]+1];
            else if(f[3]==1) v1=a[++i];
            else v1=a[a[++i]+base];

            if(f[4]==0) v2=a[a[++i]+1];
            else if(f[4]==1) v2=a[++i];
            else v2=a[a[++i]+base];

            if(f[1]==5&&v1!=0) i=v2;
            else if(f[1]==6&&v1==0) i=v2;
        }
        else if(f[1]==9)
        {
            if(f[3]==0) v1=a[a[++i]+1];
            else if(f[3]==1) v1=a[++i];
            else v1=a[a[++i]+base];
            base+=v1;
        }
    }
    fout<<c+1<<"\n\n\n\n";
    //fout<<strlen(c);
    //for(i=strlen(c)-1;i>=strlen(c)-10;i--) fout<<int(c)<<" ";
    //fout<<"\n\n";
    fout<<rez;
    /*
    x=1;y=0;
    for(i=1;i<k-1;i++)
    {
        if(c[i]==10) x++,y=0;
        else v[x][++y]=c[i];
    }
    for(i=1;i<=x;i++,fout<<"\n")
        for(j=1;v[i][j];j++) fout<<v[i][j];
     /*
    for(i=1;i<=x;i++) for(j=1;j<=y;j++)
        if(i>1&&i<x&&j>1&&j<y)
        {
            if(v[i][j]=='#'&&v[i-1][j]=='#'&&v[i+1][j]=='#'&&v[i][j-1]=='#'&&v[i][j+1]=='#')
                sol+=(i-1)*(j-1);
        }
    fout<<sol;
    */
    /*
    int pi,pj;
    for(i=1;i<=x;i++) for(j=1;j<=y;j++) if(v[i][j]=='^') pi=i,pj=j;
    t=0;
    dirj[0][0]=-1;dirj[0][1]=1;
    diri[1][0]=1;diri[1][1]=-1;
    dirj[2][0]=1;dirj[2][1]=-1;
    diri[3][0]=-1;diri[3][1]=1;
    ok=0;
    while(true)
    {
        si=pi+diri[t][0],sj=pj+dirj[t][0];
        di=pi+diri[t][1],dj=pj+dirj[t][1];
        if(v[si][sj]=='#')
        {
            nr=0;
            while(v[si][sj]=='#')
            {
                pi=si;pj=sj;nr++;
                si=pi+diri[t][0],sj=pj+dirj[t][0];
            }
            ini[++u].first='L';
            ini[u].second=nr;
            t++;if(t==4) t=0;
        }
        else if(v[di][dj]=='#')
        {
            nr=0;
            while(v[di][dj]=='#')
            {
                pi=di;pj=dj;nr++;
                di=pi+diri[t][1],dj=pj+dirj[t][1];
            }
            ini[++u].first='R';
            ini[u].second=nr;
            t--;if(t==-1) t=3;
        }
        else break;
    }
    for(i=1;i<=u;i++)
        fout<<ini[i].first<<","<<ini[i].second<<",";
    /*
    ce obtin
    L,8,R,12,R,12,R,10, A
    R,10,R,12,R,10, B
    L,8,R,12,R,12,R,10, A
    R,10,R,12,R,10, B
    L,10,R,10,L,6, C
    L,10,R,10,L,6, C
    R,10,R,12,R,10, B
    L,8,R,12,R,12,R,10, A
    R,10,R,12,R,10, B
    L,10,R,10,L,6, C
    pe care le bag in fisierul de citire
    */
    return 0;
}
