#include<fstream>
#include<map>
using namespace std;
ifstream fin("date.in");
ofstream fout("date.out");
char a[30000];
int aux,ii,jj,i,x,y,rez,nr;
map<pair<int,int> , int> m;
inline int mod(int a)
{
    if(a<0) return-a;
    return a;
}
int main()
{
    fin>>a;
    x=15000;y=15000;nr=0;
    for(i=0;a[i];i++)
    {
        //int s=i;
        if(a[i]=='R') ii=1,jj=0;
        if(a[i]=='L') ii=-1,jj=0;
        if(a[i]=='U') ii=0,jj=-1;
        if(a[i]=='D') ii=0,jj=1;
        i++;aux=0;
        while(a[i]>='0'&&a[i]<='9')
            aux=aux*10+a[i++]-'0';
        ii*=aux;jj*=aux;
        while(ii!=0)
        {
            if(ii<0) x--,ii++;
            if(ii>0) x++,ii--;
            nr++;
            m[make_pair(x,y)]=nr;
        }
        while(jj!=0)
        {
            if(jj<0) y--,jj++;
            if(jj>0) y++,jj--;
            nr++;
            m[make_pair(x,y)]=nr;
        }
    }
    //return 0;
    fin>>a;rez=1500000;
    x=15000;y=15000;nr=0;
    for(i=0;a[i];i++)
    {
        if(a[i]=='R') ii=1,jj=0;
        if(a[i]=='L') ii=-1,jj=0;
        if(a[i]=='U') ii=0,jj=-1;
        if(a[i]=='D') ii=0,jj=1;
        i++;aux=0;
        while(a[i]>='0'&&a[i]<='9')
            aux=aux*10+a[i++]-'0';
        ii*=aux;jj*=aux;
        while(ii!=0)
        {
            if(ii<0) x--,ii++;
            if(ii>0) x++,ii--;
            nr++;
            if(m[make_pair(x,y)]!=0&&x!=15000&&y!=15000) rez=min(m[make_pair(x,y)]+nr,rez);
            m[make_pair(x,y)]=0;
        }
        while(jj!=0)
        {
            if(jj<0) y--,jj++;
            if(jj>0) y++,jj--;
            nr++;
            if(m[make_pair(x,y)]!=0&&x!=15000&&y!=15000) rez=min(m[make_pair(x,y)]+nr,rez);
            m[make_pair(x,y)]=0;
        }
    }
    fout<<rez;
    return 0;
}