#include <bits/stdc++.h>
using namespace std;

#define SKYLAGS UNSTOPPABLE
#define pb push_back
#define F first
#define S second
#define ALL(a) (a).begin(),(a).end()
#define SKY ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define int long long int
const int N=1e5+5;
const int INF=LLONG_MAX;
//Directed/Undirected Weighted Graph
//where first pair corresponds to second end of edge and second
//pair corresponds to the weight of the current edge
vector<pair<int,int>> adj[N];
vector<int> d,p;
vector<bool> visited;

void dijikstra(int s, int n)
{
    d.assign(n,INF);
    p.assign(n,-1);
    visited.assign(n,false);
    //Source vertex
    d[s]=0;
    for(int i=0;i<n;i++)
    {
        //Finding next vertex(unvisited) with shortest d[v]
        int v=-1;
        for(int j=0;j<n;j++)
        {
            if(!visited[j] and (v==-1 or d[j]<d[v]))
                v=j;
        }
        //Stop the Algorithm whenever we find d[v]=INF
        if(d[v]==INF)
            break;
        //else marked found v as visited
        visited[v]=true;
        for(auto it: adj[v])
        {
            int to=it.F;
            int len=it.S;
            if(d[v]+len<d[to])
            {
                d[to]=d[v]+len;
                p[to]=v;
            }
        }
    }
}
void solve()
{
    //n nodes & m edges of graph
    
    int n,m;
    cin>>n>>m;
    
    for(int i=0;i<m;i++)
    {
        int a,b,w;
        cin>>a>>b>>w;
        a--;
        b--;
        //Consider for now undirected
        adj[a].pb({b,w});
        adj[b].pb({a,w});
    }
    
    dijikstra(0,n);
    //Now we can print our d[] and p[] array
    
    for(int i=0;i<n;i++)
        cout<<d[i]<<" ";
    cout<<"\n";
    for(int j=0;j<n;j++)
        cout<<p[j]<<" ";
    cout<<"\n";
}


int32_t main()
{
    solve();
}
/*
 Dijisktra's Alogirthm Clean Code with comments
 */
/*
 Input:
 6 7
 1 2 3
 1 3 2
 3 6 1
 6 5 6
 4 5 7
 4 2 5
 3 4 4
 Output:
 0 3 2 6 9 3
 -1 0 0 2 5 2
 */
 
