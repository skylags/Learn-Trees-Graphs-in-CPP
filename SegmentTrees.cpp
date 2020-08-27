/**********************Created By SKYLAGS***********************/

#include<bits/stdc++.h>
using namespace std;
#define int long long int

//Function to build segment tree
void buildTree(int* arr,int* tree, int start, int end, int treeNode)
{
    if(start==end)
    {
        tree[treeNode]=arr[start];
        return;
    }
    int mid=(start+end)/2;
    buildTree(arr,tree,start,mid,treeNode*2);
    buildTree(arr,tree,mid+1,end,treeNode*2+1);
    tree[treeNode]=tree[treeNode*2]+tree[treeNode*2+1];
}

//Function to get sum in range l to r
int getSum(int* tree, int start, int end,  int qs, int qe, int treeNode)
{
    if (qs <= start && qe >= end)
        return tree[treeNode];
  
    if (end < qs || start > qe)
        return 0;

    int mid = start+(end-start)/2;
    
    return getSum(tree, start, mid, qs, qe, 2*treeNode)+getSum(tree, mid+1, end, qs, qe, 2*treeNode+1);
}

//Function to update arr[i]=val where dif=val-arr[i]
void update(int* tree, int start, int end, int i, int dif, int treeNode)
{
    if(i<start or i>end)
    {
        return;
    }
    tree[treeNode]+=dif;
    if(start!=end)
    {
        int mid=start+(end-start)/2;
        update(tree,start,mid,i,dif,2*treeNode);
        update(tree,mid+1,end,i,dif,2*treeNode+1);
    }
}

int32_t main()
{
    int n,l,r,val,i;
    int t=1;
    //cin>>t;
    while(t--)
    {
        cin>>n;
        int arr[n];
        for(int i = 0 ; i < n ; i++)
        {
            cin>>arr[i];
        }
        //Constructing Segment Tree
        //Size of segment tree will always be 2*n-1
        //segment tree will always have 2*n-1 nodes represented by array
        int tree[2*n];
        buildTree(arr,tree,0,n-1,1);
        
        //Sum in a range query
        int q;
        cin>>q;
        int type;
        
        //type 1-> sum in a range l,r
        //type 2-> update arr[i]=val in segment tree as well as array
        while(q--)
        {
            cin>>type>>l>>r;
            if(type==1)
            cout<<getSum(tree,0,n-1,l,r,1)<<"\n";
            else
            {
                i=l;
                val=r;
                int dif=val-arr[i];
                arr[i]=val;
                //Update Query
                update(tree,0,n-1,i,dif,1);
            }
        }
    }
    return 0;
}
