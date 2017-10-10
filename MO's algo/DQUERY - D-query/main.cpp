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
#define pii                 pair<int,int>
#define ms(a,b)             memset(a,b,sizeof(a))
#define pb(a)               push_back(a)
#define pbp(a,b)            push_back({a,b})
#define db                  double
#define ft                  float
#define ll                  long long
#define ull                 unsigned long long
#define pii                 pair<int,int>
#define ff                  first
#define ss                  second
#define sz(x)               x.size()
#define all(x)              x.begin(),x.end()
#define CIN                 ios_base::sync_with_stdio(0); cin.tie(0)
#define max3(a, b, c)       max(a, b) > max(b, c) ? max(a, b) : max(b, c)
#define min3(a, b, c)       min(a, b) < min(b, c) ? min(a, b) : min(b, c)
#define for0(i,n)          for(int i=0;i<n;i++)
#define for1(i,n)          for(int i=1;i<=n;i++)
#define forrev(i,n)        for(int i=n-1; i>=0; i--)
#define forab(i,a,b)       for(int i=a;i<=b;i++)
#define forba(i,b,a)       for(int i=b;i>=a;i--)
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

/*------------------------------Graph Moves----------------------------*/
//const int fx[]={+1,-1,+0,+0};
//const int fy[]={+0,+0,+1,-1};
//const int fx[]={+0,+0,+1,-1,-1,+1,-1,+1};   // Kings Move
//const int fy[]={-1,+1,+0,+0,+1,+1,-1,-1};  // Kings Move
//const int fx[]={-2, -2, -1, -1,  1,  1,  2,  2};  // Knights Move
//const int fy[]={-1,  1, -2,  2, -2,  2, -1,  1}; // Knights Move
/*---------------------------------------------------------------------*/

using namespace std;

int a[30004],cnt[1000006],result[200005],block_sz,ans=0;

struct node
{
    int l,r,i;
}s[200005];

bool comp(node x,node y)
{
    if (x.l/block_sz != y.l/block_sz) /// Different blocks, sort by block.
        return x.l/block_sz < y.l/block_sz;
    return x.r < y.r; /// Same block, sort by R value
}

void add(int pos)
{
    cnt[a[pos]]++;
    if(cnt[a[pos]]==1) ans++;
}

void rmv(int pos)
{
    cnt[a[pos]]--;
    if(cnt[a[pos]]==0) ans--;
}

void MO(int n,int q)
{
    block_sz=(int)sqrt(n);
    sort(s,s+q,comp);
    int c_l=0, c_r=0;

    for0(i,q)
    {
        int l=s[i].l, r=s[i].r;

        while(c_l<l)
        {
            rmv(c_l);
            c_l++;
        }
        while(c_l>l)
        {
            add(c_l-1);
            c_l--;
        }
        while(c_r<=r)
        {
            add(c_r);
            c_r++;
        }
        while(c_r>r+1)
        {
            rmv(c_r-1);
            c_r--;
        }
        result[s[i].i]=ans;
    }
    for0(i,q) pf("%d\n",result[i]);
}

int main()
{
    //CIN;
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int n,q;
    sf(n);
    for0(i,n) sf(a[i]);
    sf(q);
    for0(i,q)
    {
        sff(s[i].l,s[i].r);
        s[i].l--;s[i].r--;
        s[i].i=i;
    }
    MO(n,q);
    return 0;
}
