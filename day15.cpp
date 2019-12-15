#include <bits/stdc++.h>
using namespace std;
ifstream fin("date.in");
ofstream fout("date.out");
long long d,n,b,i,sol,f[100],a[10000],v1,v2,ok,aux,nr,poz,base,sep,X,Y,maxi;
long long m[2010][2010],x,y,drum[2010][2010],op[2010][2010];
vector<pair<int,int> > pot;
queue<pair<int,int> > v;
long long di[4]={-1,1,0,0};
long long dj[4]={0,0,-1,1};
void lee()
{
    for(int i=0;i<=2000;i++) for(int j=0;j<=2000;j++) drum[i][j]=0;
    for(auto it:pot)
    {
        v.push(it);
        drum[it.first][it.second]=1;
    }
    while(!v.empty())
    {
        int x=v.front().first;
        int y=v.front().second;
        v.pop();
        for(int d=0;d<=3;d++)
        {
            int i=x+di[d];
            int j=y+dj[d];
            if(m[i][j]==1&&drum[i][j]==0)
            {
                drum[i][j]=drum[x][y]+1;
                maxi=max(drum[i][j],maxi);
                v.push(make_pair(i,j));
            }
        }
    }
}
int cauta()
{
    int d,rez=100000,p;
    for(d=0;d<=3;d++)
        if(rez>drum[x+di[d]][y+dj[d]]&&drum[x+di[d]][y+dj[d]]!=0)
            rez=drum[x+di[d]][y+dj[d]],p=d;
    return p;
}

void elim()
{
    for(unsigned int i=0;i<pot.size()-1;i++)
        if(m[pot[i].first][pot[i].second]!=0)
            swap(pot[i],pot[i+1]);
    pot.pop_back();
}

void add()
{
    for(int d=0;d<=3;d++)
        if(m[x+di[d]][y+dj[d]]==0&&op[x+di[d]][y+dj[d]]==0)
        {
            op[x+di[d]][y+dj[d]]=1;
            pot.push_back(make_pair(x+di[d],y+dj[d]));
        }
}

int main()
{
    while(fin>>b) a[++n]=b;
    base=1;sep=3;
    x=1000;y=1000;m[x][y]=1;
    add();
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
           // fout<<sep<<"\n";
            if(sep==0)
            {
                m[x+di[d]][y+dj[d]]=2;
                elim();
                //fout<<"ok"<<"\n";
            }
            else if(sep==1||sep==2)
            {
                x+=di[d];y+=dj[d];
                if(m[x][y]==0)
                {
                    m[x][y]=1;
                    elim();
                }
                if(sep==2) X=x,Y=y;
                add();
            }
            fout<<x<<" "<<y<<"\n";
            /*

            int o=20;
            for(int oi=1000-o;oi<=1000+o;oi++,fout<<"\n")
                for(int oj=1000-o;oj<=1000+o;oj++) fout<<drum[oi][oj];

            */
            //for(auto it:pot) fout<<it.first<<" "<<it.second<<"\n";
            lee();
            if(pot.size()==0)
                break;
            d=cauta();
           // fout<<d+1<<"\n";
           // fout<<"\n";
            a[poz]=d+1;
        }
        else if(f[1]==4)
        {
            if(f[3]==0) poz=a[++i]+1;
            else if(f[3]==1) poz=++i;
            else if(f[3]==2) poz=a[++i]+base;
            sep=a[poz];
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
    fout<<X<<" "<<Y<<"\n";
    pot.push_back(make_pair(X,Y));
    lee();
    //fout<<drum[1000][1000]-1;
    fout<<maxi-1;
    return 0;
}
