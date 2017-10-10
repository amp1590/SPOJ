#include <bits/stdc++.h>

#define pf                  printf
#define sf(a)               scanf("%d",&a)
#define sfl(a)              scanf("%lld",&a)
#define sff(a,b)            scanf("%d %d",&a,&b)
#define sffl(a,b)           scanf("%lld %lld",&a,&b)
#define sfff(a,b,c)         scanf("%d %d %d",&a,&b,&c)
#define sfffl(a,b,c)        scanf("%lld %lld %lld",&a,&b,&c)
#define sffff(a,b,c,d)      scanf("%d %d %d %d",&a,&b,&c,&d)
#define sffffl(a,b,c,d)     scanf("%lld %lld %lld %lld",&a,&b,&c,&d)
#define sfffff(a,b,c,d,e)   scanf("%d %d %d %d %d",&a,&b,&c,&d,&e)
#define sfffffl(a,b,c,d,e)  scanf("%lld %lld %lld %lld %lld",&a,&b,&c,&d,&e)
#define sfc(a)              scanf("%c",&a)
#define ms(a,b)             memset(a,b,sizeof(a))
#define pb(a)               push_back(a)
#define db                  double
#define ll                  long long
#define ull                 unsigned long long
#define pii                 pair<int,int>
#define ff                  first
#define ss                  second
#define sz(x)               (int)x.size()
#define all(x)              x.begin(),x.end()
#define CIN                 ios_base::sync_with_stdio(0); cin.tie(0)
#define max3(a, b, c)       max(a, b) > max(b, c) ? max(a, b) : max(b, c)
#define min3(a, b, c)       min(a, b) < min(b, c) ? min(a, b) : min(b, c)
#define for0(i,n)           for(int i=0;i<n;i++)
#define for1(i,n)           for(int i=1;i<=n;i++)
#define forrev(i,n)         for(int i=n-1; i>=0; i--)
#define forab(i,a,b)        for(int i=a;i<=b;i++)
#define forba(i,b,a)        for(int i=b;i>=a;i--)
#define stlloop(x)          for(__typeof(x.begin()) it=x.begin();it!=x.end();it++)
#define gcd(a, b)           __gcd(a, b)
#define lcm(a, b)           ((a)*((b)/gcd(a,b)))
#define case1(z)            cout<<"Case "<<z<<": "
#define case2(z)            printf("Case %d: ",z)
#define PI                  acos(-1) //3.14159265358979323846264338328
#define valid(tx,ty)        tx>=0 && tx<row && ty>=0 && ty<col
#define intlim              2147483648
#define MAX                 100005
#define inf                 100000008

ll power(int n,int p)
{
    ll ans=1;
    for1(i,p) ans*=n;
    return ans;
}

ll m=1000001;
ll bigmod(ll n,ll p)
{
    if(p==0) return 1;
    else if(p%2==0)
    {
        ll x=(bigmod(n,p/2))%m;
        return (x*x)%m;
    }
    else return ((n%m)*(bigmod(n,p-1)%m))%m;
}


/*------------------------------Graph Moves----------------------------*/
//const int fx[]={+1,-1,+0,+0};
//const int fy[]={+0,+0,+1,-1};
//const int fx[]={+0,+0,+1,-1,-1,+1,-1,+1};   // Kings Move
//const int fy[]={-1,+1,+0,+0,+1,+1,-1,-1};  // Kings Move
//const int fx[]={-2, -2, -1, -1,  1,  1,  2,  2};  // Knights Move
//const int fy[]={-1,  1, -2,  2, -2,  2, -1,  1}; // Knights Move
/*---------------------------------------------------------------------*/

using namespace std;

ll tree[30004],input[30004];
map<string,int> mp;
vector<string> v;

ll query(ll idx)
{
    ll sum=0;
    while(idx>0)
    {
        sum+=tree[idx];
        idx-= idx & (-idx);
    }
    return sum;
}

void update(ll idx,ll val, int n)
{
    while(idx<=n)
    {
        tree[idx]+=val;
        idx+=idx&(-idx);
    }
}

int main()
{
    CIN;
//    freopen("in.txt","r",stdin);
//    freopen("out.txt","w",stdout);
    int t;
    cin>>t;
    for1(z,t)
    {
        int n,c=0;
        cin>>n;
        string s,ss,str;
        for1(i,n)
        {
            cin>>s;
            v.pb(s);
        }
        for1(i,n)
        {
            cin>>s;
            c++;
            mp[s]=c;
        }
        for0(i,sz(v)) {input[i+1]=mp[v[i]];}
        ll ans=0;
        for1(i,n)
        {
            update(input[i],1,n);
            ll x=query(input[i]-1);
            ans+=(input[i]-x-1);
        }
        cout<<ans<<endl;
        mp.clear();
        v.clear();
        ms(tree,0);
    }

    return 0;
}
