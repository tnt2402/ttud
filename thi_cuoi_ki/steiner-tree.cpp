#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
int hmt() {int x=0;int c=getchar(),n=0;for(;!isdigit(c);c=getchar()) n=(c=='-');for(;isdigit(c);c=getchar()) x=x*10+c-'0';if(n) x=-x;return x;}
#define in hmt()
#define ins ({string x;char c=getchar();for(;c==' '||c=='\n';c=getchar());for(;c!=' '&&c!='\n';c=getchar()) x+=c;x;})
#define forinc(i,a,b) for(int i=a,_b=b;i<=_b;++i)
#define fordec(i,a,b) for(int i=a;i>=b;--i)
#define forb(i,BS) for(int i=BS._Find_first();i< BS.size();i = BS._Find_next(i))
#define timer 1.0*clock()/CLOCKS_PER_SEC
#define forv(a,b) for(auto &a:b)
#define pb push_back
#define pii pair<int,int>
#define fi first
#define se second
#define all(a) a.begin(),a.end()
#define reset(f,x) memset(f,x,sizeof(f))
#define bit(x,i) ((x>>(i-1))&1)
#define onbit(x,i) (x|(1<<(i-1)))
#define offbit(x,i) (x&~(1<<(i-1)))
const int N=32;
int n,m,k,dd[N];
int x[N],cot,ans=INT_MAX;
struct oo {
    int u,v,w;
};
oo a[N];
vector<int> ke[N];
int rt,co[N];
void DFS(int u) {
    co[u]=1;
    forv(v,ke[u]) if(!co[v]) {
        co[v]=1;
        DFS(v);
    }
}
bool check() {
    forinc(i,1,n) ke[i].clear();
    forinc(i,1,m) if(x[i]) {
        int u=a[i].u,v=a[i].v;
        ke[u].pb(v);
        ke[v].pb(u);
    }
    reset(co,0);
    DFS(rt);
    forinc(i,1,n) if(dd[i]&&!co[i]) return 0;
    return 1;
}
void Init() {
    cot=0;
    random_shuffle(a+1,a+m+1);
    forinc(i,1,m) {
        cot+=a[i].w;
        x[i]=1;
    }
}
int cp() {
    if(!check()) return -1;
    int ret=0;
    forinc(i,1,m) if(x[i]) ret+=a[i].w;
    return ret;
}
void Search() {
    Init();
    //bai cho thoi gian bao nhieu thi de cai timer<timelimit-0.1
    while(timer<0.9) {
        bool ok=0;
        forinc(i,1,m) if(x[i]) {
            x[i]=0;
            int _cot=cp();
            if(_cot==-1||_cot>=cot) x[i]=1;
            else cot=_cot,ok=1;
        }
        forinc(i,1,m) if(x[i])
        forinc(j,1,m) if(!x[j]) {
            x[i]=0,x[j]=1;
            int _cot=cp();
            if(_cot==-1||_cot>=cot) x[i]=1,x[j]=0;
            else cot=_cot,ok=1;
        }
        if(!ok) {
            ans=min(ans,cot);
            Init();
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    //freopen("steiner-tree.inp","r",stdin);
    //neu tong do dai cac canh > INT_MAX thi define int long long, ans=1e18
    cin>>n>>m;
    forinc(i,1,m) {
        int u,v,w;
        cin>>u>>v>>w;
        a[i]={u,v,w};
    }
    cin>>k;
    forinc(i,1,k) {
        int x;
        cin>>x;
        dd[x]=1;
        rt=x;
    }
    Search();
    cout<<ans<<"\n";
}
