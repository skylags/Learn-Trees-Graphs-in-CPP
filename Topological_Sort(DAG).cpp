//C++ Code for printing topological sort of the graph
//Used in Job Scheduling
//High Application
//Graph Theory
//Comments are added wherever necessary for better understanding
//Well tested and simplified..:)
#include<bits/stdc++.h>
using namespace std;
#define int long long int

//g is my graph
vector<int> g[100005];
//visited is to keep track of the visited nodes
bool visited[100005];
//store the result
stack<int> res;
//sort of DFS with some modifications
//Modification is : Inserting the current node in stack instead of
//printing it
void topological_sort(int v)
{
    visited[v]=true;
    for(int i = 0 ; i < g[v].size() ; i++)
    {
        if(!visited[g[v][i]])
        {
            topological_sort(g[v][i]);
            
        }
        
    }
    res.push(v);
}
int32_t main()
{
    int n,m;
    cin>>n>>m;
    // n-> nodes, m-> edges
    //Get the graph
    int a,b;
    //Refresh the graph and visited array
    memset(visited,false,sizeof(visited));
    for(int i = 0 ; i < n ; i++)
    {
        g[i].clear();
        
    }
    //Get the edges
    //Consider for Directed Graph
    //For undirected graph simply we should add
    //g[b].pb(a)
    //Hope you know that ..;)
    //But topological sort is only defined for DAG
    //DAG- Directed Acylic Graph
    while(m--)
    {
        cin>>a>>b;
        g[a].push_back(b);
    }
    for(int i = 0 ; i < n ; i++)
    {
        if(!visited[i])
        {
            topological_sort(i);
            
        }
        
    }
    //Print the result, i.e, topological_sort of the given graph
    while(!res.empty())
    {
        cout<<res.top()<<" ";
        res.pop();
        
    }
    //Thank You
    return 0;
}
