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
#define pbp(a,b)            push_back({a,b})
#define db                  double
#define ft                  float
#define ll                  long long
#define ull                 unsigned long long
#define ff                  first
#define ss                  second
#define sz(x)               x.size()
#define qu                  queue
#define pqu                 priority_queue
#define vc                  vector
#define vi                  vector<int>
#define vll                 vector<long long>
#define pii                 pair<int,int>
#define pis                 pair<int,string>
#define psi                 pair<string,int>
#define all(x)              x.begin(),x.end()
#define CIN                 ios_base::sync_with_stdio(0); cin.tie(0)
#define max3(a, b, c)       max(a, b) > max(b, c) ? max(a, b) : max(b, c)
#define min3(a, b, c)       min(a, b) < min(b, c) ? min(a, b) : min(b, c)
#define for0(i,n)          for(int i=0;i<n;i++)
#define for1(i,n)          for(int i=1;i<=n;i++)
#define forcmp(i,n)        for(int i=1;i<n;i++)
#define forrev(i,n)        for(int i=n-1; i>=0; i--)
#define forab(i,a,b)       for(int i=a;i<=b;i++)
#define forba(i,b,a)       for(int i=b;i>=a;i--)
#define stlloop(x)          for(__typeof(x.begin()) it=x.begin();it!=x.end();it++)
#define gcd(a, b)           __gcd(a, b)
#define lcm(a, b)           ((a)*((b)/gcd(a,b)))
#define case1(z)            cout<<"Case "<<z<<": "
#define case2(z)            printf("Case %d:\n",z)
#define PI                  acos(-1) //3.14159265358979323846264338328
#define valid(tx,ty)        tx>=0 && tx<row && ty>=0 && ty<col
#define intlim              2147483648
#define MAX                 1000000
#define inf                 100000000
#define mx                  100005

/*------------------------------Graph Moves----------------------------*/
//const int fx[]={+1,-1,+0,+0};
//const int fy[]={+0,+0,+1,-1};
//const int fx[]={+0,+0,+1,-1,-1,+1,-1,+1};   // Kings Move
//const int fy[]={-1,+1,+0,+0,+1,+1,-1,-1};  // Kings Move
//const int fx[]={-2, -2, -1, -1,  1,  1,  2,  2};  // Knights Move
//const int fy[]={-1,  1, -2,  2, -2,  2, -1,  1}; // Knights Move
/*---------------------------------------------------------------------*/

using namespace std;

struct data
{
    ll prop,sum;
};

data tree[3*mx];

void pushdown(int node, int low, int high)
{
    if(tree[node].prop!=0)
    {
        int mid=(low+high)/2;
        tree[node*2].sum+=(mid-low+1)*tree[node].prop;
        tree[node*2+1].sum+=(high-mid)*tree[node].prop;
        tree[node*2].prop+=tree[node].prop;
        tree[node*2+1].prop+=tree[node].prop;
        tree[node].prop=0;
    }
}

void update(int node, int low, int high, int qlow, int qhigh, ll val)
{
    if(qlow>high || qhigh<low) return;
    if(low>=qlow && high<=qhigh)
    {
        tree[node].sum+=(high-low+1)*val;
        tree[node].prop+=val;
        return;
    }

    pushdown(node,low,high);

    int left=node*2;
    int right=left+1;
    int mid=(low+high)/2;

    update(left,low,mid,qlow,qhigh,val);
    update(right,mid+1,high,qlow,qhigh,val);

    tree[node].sum=tree[left].sum+tree[right].sum;
}

ll query(int node, int low, int high, int qlow, int qhigh)
{
    if(qlow>high || qhigh<low) return 0;
    if(low>=qlow && high<=qhigh) return tree[node].sum;

    pushdown(node,low,high);

    int left=node*2;
    int right=left+1;
    int mid=(low+high)/2;

    ll l=query(left,low,mid,qlow,qhigh);
    ll r=query(right,mid+1,high,qlow,qhigh);
    return l+r;
}

int main()
{
    //CIN;
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int t;
    sf(t);
    for1(z,t)
    {
        int n,q,mark,qlow,qhigh,val;
        sff(n,q);
        for1(i,q)
        {
            sfff(mark,qlow,qhigh);
            if(mark==0)
            {
                sf(val);
                update(1,1,n,qlow,qhigh,val);
            }
            else pf("%lld\n",query(1,1,n,qlow,qhigh));
        }
        ms(tree,0);
    }
    return 0;
}

