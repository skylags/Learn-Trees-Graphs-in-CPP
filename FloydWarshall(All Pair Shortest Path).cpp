#include <bits/stdc++.h>
using namespace std;

#define SKYLAGS UNSTOPPABLE
#define pb push_back
#define F first
#define S second
#define ALL(a) (a).begin(),(a).end()
#define SKY ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define int long long int

//Floyd Warshall is generally used on Adjcenecy Matrix
//whereas Dijikstra can be used on both list or matrix
//Floyd Warshall - All Pair Shortest Path
//dijikstra - Single Source Shortest Path
//Consider nodes to be at max 10
//Consider graph[a][b] to be -1 if there isn't edge from a to b
const int INF = 1e5+5;
int graph[10][10];

void floyd_warshall(int v)
{
    int d[v][v];
    //Initialise the distance matrix same as graph
    
    for(int i = 0 ; i < v ; i++)
    {
        for(int j = 0 ; j < v ; j++)
        {
            if(graph[i][j] != -1)
                d[i][j] = graph[i][j];
            else d[i][j]  = INF;
        }
    }
    
    for(int k = 0; k < v ; k++)
    {
        for(int i = 0 ; i < v ; i++)
        {
            for(int j = 0 ; j < v ; j++)
            {
                d[i][j] = min(d[i][j] , d[i][k] + d[k][j]);
            }
        }
    }
    
    for(int i = 0 ; i < v ; i++)
    {
        for(int j = 0 ; j < v ; j++)
        {
            if(d[i][j] == INF)
                cout << "INF ";
            else cout << d[i][j] << " ";
        }
        cout<<"\n";
    }
    
    return;
}
int32_t main()
{
    int v;
    cin >> v;
    for(int i = 0 ; i < v ; i++)
        for(int j = 0 ; j < v ; j++)
            cin>>graph[i][j];
    
    floyd_warshall(v);
    return 0;
}
/*
 Adjacency Matrix Input
 4
 0 2 -1 6
 -1 0 3 -1
 -1 -1 0 5
 6 -1 -1 -1
 Output:
 0 2 5 6
 14 0 3 8
 11 13 0 5
 6 8 11 12
 */
