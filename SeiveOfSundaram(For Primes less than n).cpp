#include <bits/stdc++.h>
using namespace std;

#define SKYLAGS UNSTOPPABLE
#define pb push_back
#define F first
#define S second
#define ALL(a) (a).begin(),(a).end()
#define SKY ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define int long long int

//Seive of Sundaram is an Algorithm to print all primes less than or equal to n
//Since it finds no less than 2*x+1, for given x, so
//we create an array (n-1)/2 which is enough to find primes
//less than or equal to n

void seive_of_sundaram(int n)
{
    int n1=(n-1)/2;
    bool visited[n1+1];
    memset(visited,false,sizeof(visited));
    
    for(int i=1;i<=n1;i++)
    {
        for(int j = i ; (i+j+2*i*j) <= n1 ; j++)
        {
            visited[i+j+2*i*j]=true;
        }
    }
    
    if(n>2)
        cout<<2<<" ";
    
    for(int i=1;i<=n1;i++)
    {
        if(!visited[i])
            cout<<2*i+1<<" ";
    }
}


int32_t main()
{
    int n;
    cin>>n;
    seive_of_sundaram(n);
    return 0;
}

 
/*
 Input: 50
 Output : 2 3 5 7 11 13 17 19 23 29 31 37 41 43 47
 */
