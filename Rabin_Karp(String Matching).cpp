#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define F first
#define S second
#define ALL(a) (a).begin(),(a).end()
#define SKY ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define int long long int

vector<int> rabin_karp(string &pat,string &txt)
{
    int S=pat.size();
    int T=txt.size();
    const int p=31;
    const int m=1e9+9;
    vector<int> pow_of_p(max(S,T),1);
    for(int i=1;i<pow_of_p.size();i++)
        pow_of_p[i]=((pow_of_p[i-1]*p))%m;
    int pat_hash=0;
    for(int i=0;i<S;i++)
    {
        pat_hash+=(pat[i]-'a'+1)*pow_of_p[i];
        pat_hash%=m;
    }
    int pre[T+1];
    memset(pre,0,sizeof(pre));
    for(int i=0;i<T;i++)
    {
        pre[i+1]=pre[i]+(txt[i]-'a'+1)*pow_of_p[i];
        pre[i+1]%=m;
    }
    vector<int> ans;
    for(int i=0;i+S-1<T;i++)
    {
        int hash=pre[i+S]+m-pre[i];
        hash%=m;
        if(hash==(pat_hash*pow_of_p[i])%m)
            ans.pb(i);
    }
    return ans;
}
int32_t main()
{
    string pat="ababa";
    string txt="ababbbababababababbabababababa";
    vector<int> ans=rabin_karp(pat,txt);
    for(auto it: ans)
        cout<<it<<" ";
}
/*
 Output:
 6 8 10 12 19 21 23 25
 */
