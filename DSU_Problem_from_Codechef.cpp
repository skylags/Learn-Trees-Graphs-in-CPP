//Disjoint Union Set Implementation in Codechef Problem
//Problem Link : https://www.codechef.com/problems/GALACTIK

#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define F first
#define S second
#define ALL(a) (a).begin(),(a).end()
#define SKY ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define int long long int
const int MAX = 100005;
int dsu[MAX];
int ranks[MAX];
void create(int n)
{
    for(int i = 0 ; i <= n ; i++)
        dsu[i] = i;
    for(int i = 0 ; i <= n ; i++)
        ranks[i] = 0;
}

int find_set(int v)
{
    if(dsu[v] == v)
        return v;
    return dsu[v] = find_set(dsu[v]);
}
void union_set(int a,int b)
{
    int r1 = find_set(a);
    int r2 = find_set(b);
    if(r1!=r2)
    {
        if(ranks[r1] > ranks[r2])
            dsu[r2] = r1;
        else dsu[r1] = r2;
        if(ranks[r1] == ranks[r2])
            ranks[r2]++;
    }
    return;
}
void solve()
{
    int n , m ;
    cin >> n >> m;
    create(n);
    int a,b;
    for(int i = 0 ; i < m ; i++)
    {
        cin >> a >> b;
        union_set(a,b);
    }
    int cost[n+1];
    int dp[n+1];
    for(int i = 1 ; i <= n ; i++)
    {
        cin >> cost[i];
        dp[i] = 1e16;
    }
    int ans = 0 , temp = 0;
    for(int  i = 1 ; i <= n ; i++)
    {
        if(cost[i] >= 0)
        {
            dp[find_set(i)] = min(dp[find_set(i)], cost[i]);
        }
        if(find_set(i) == i)
        temp++;
    }
    if(temp == 1)
    {
        cout << 0 ;
        return;
    }
    int mn = LLONG_MAX;
    int num = 0;
    for(int i = 1 ; i <= n ; i++)
    {
        if(find_set(i) == i and dp[i] == 1e16)
        {
            cout << "-1";
            return;
        }
        if(find_set(i) == i)
        {
            ans += dp[i];
            mn = min(mn,dp[i]);
            num ++;
        }
    }
    ans += (num-2)*mn;
    cout << ans ;
    return;
    
}
int32_t main()
{
    SKY;
    int T = 1;
    //cin >> T;
    for(int i = 1 ; i <= T ; i++)
    {
        solve();
    }
    return 0;
}

