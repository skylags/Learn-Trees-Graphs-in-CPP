//Frenwick Tree Trial!!
// A Level UP!
#include <bits/stdc++.h>
#define pb push_back
#define F first
#define S second
#define ALL(a) (a).begin(),(a).end()
#define MAX 105
#define int long long int
using namespace std;

//Getting the sum of ith index
int getSum(int fren[],int i)
{
    int sum=0;
    while(i>0)
    {
        sum+=fren[i];
        i-=(i&(-i));
    }
    return sum;
}

//Individual update
void update(int fren[],int i, int val, int n)
{
    while(i<=n)
    {
        fren[i]+=val;
        i+=(i&(-i));
    }
}

//Updating the tree for each value of the array
void buildTree(int* fren, int arr[],int n)
{
    
    for(int i=1;i<=n;i++)
    {
        update(fren,i,arr[i],n);
    }
    
}

int32_t main()
{
    //Input Your Array
    int n;
    cin>>n;
    
    //1-based indexing
    int arr[n+1];
    
    for(int i=1;i<=n;i++)
    {
        cin>>arr[i];
    }
    
    //Creating frenwick tree
    int fren[n+1];
    for(int i=0;i<=n;i++)
    {
        fren[i]=0;
    }
    buildTree(fren,arr,n);
    
    //Check your built frenwick tree
    for(int i=1;i<=n;i++)
    {
        cout<<fren[i]<<" ";
    }
    //It may be checked! You are smart!!
    
    //Now make any trial with this tree
    //Things you can do with this Binary IndexedTree
    //1. Update operation in log(n) time
    //2. Prefix Sum in log(n) time
    
    
    //for getting sum from (1-10) just write getSum(10)-getSum(0)
    
    //Generalised Way (a,b) sum=> getSum(b)-getSum(a-1)
    
    //That's it!
    //Thank you @skylags
    return 0;
}
