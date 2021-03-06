#include<bits/stdc++.h>
#define assn(n,a,b) assert(n<=b and n>=a)
#define pb push_back
#define mp make_pair
#define PB push_back
#define MP make_pair
#define F first
#define S second
#define SZ(a) (int)(a.size())
#define SET(a,b) memset(a,b,sizeof(a))
#define LET(x,a) __typeof(a) x(a)
#define TR(v,it) for( LET(it,v.begin()) ; it != v.end() ; it++)
#define repi(i,n) for(int i=0; i<(int)n;i++)
#define sd(n) scanf("%d",&n)
#define si(n) scanf("%d",&n)
#define sl(n) scanf("%lld",&n)
#define sortv(a) sort(a.begin(),a.end())
#define all(a) a.begin(),a.end()
using namespace std;

#define TRACE
#ifdef TRACE
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1){
       cerr << name << " : " << arg1 << std::endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
       const char* comma = strchr(names + 1, ',');cerr.write(names, comma - names) << " : " << arg1<<" | ";__f(comma+1, args...);
}
#else
#define trace(...)
#endif

typedef long long LL;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector< PII > VPII;

#define MOD 1000000007ll
LL mpow(LL a, LL n) 
{LL ret=1;LL b=a;while(n) {if(n&1) 
ret=(ret*b)%MOD;b=(b*b)%MOD;n>>=1;}
return (LL)ret;}

//FILE *fin = freopen("in","r",stdin);
//FILE *fout = freopen("out","w",stdout);

int MAXVAL;

int BIT[200005];

int pos[100001];

void sett(int ps, int val)
{
    while(ps<MAXVAL)
    {
        BIT[ps]+=val;
        ps=ps+(ps&(-ps));
    }
}

int get(int ps)
{
    int val=0;
    while(ps>0)
    {
        val+=BIT[ps];
        ps=ps-(ps&(-ps));
    }
    return val;
}

int main()
{
    //ios_base::sync_with_stdio(false);
    int T;
    si(T);
    while(T--)
    {
        int n,m;
        si(n);si(m);
        MAXVAL=n+m+1;
        memset(BIT,0,sizeof(BIT));
        int cur=n+1;
        for(int i=1; i<=n; i++)
        {
            pos[i]=n-i+1;
            sett(pos[i],1);
        }
        for(int i=0; i<m; i++)
        {
            int tmp;
            si(tmp);
            printf("%d ",get(n+m)-get(pos[tmp]-1)-1);
            sett(pos[tmp],-1);
            pos[tmp]=cur++;
            sett(pos[tmp],1);
        }
        printf("\n");
    }
    return 0;
}


