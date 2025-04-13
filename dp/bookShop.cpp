#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <stack>
#include <cmath>
#include <climits>
#include <iomanip>
#include <numeric>
#include <cassert>
#include <cstring>

using namespace std;

#define ll long long
#define ld long double
#define pb push_back
#define mp make_pair
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define F first
#define S second
#define fast_io ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
#define rep(i, a, b) for (int i = a; i < b; ++i)
#define repr(i, a, b) for (int i = a; i >= b; --i)

const ll MOD = 1e9 + 7;
const ll INF = 1e18;

ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a % b); }
ll lcm(ll a, ll b) { return (a / gcd(a, b)) * b; }
ll mod_add(ll a, ll b, ll m = MOD) { return (a % m + b % m) % m; }
ll mod_sub(ll a, ll b, ll m = MOD) { return ((a % m - b % m) + m) % m; }
ll mod_mul(ll a, ll b, ll m = MOD) { return ((a % m) * (b % m)) % m; }
ll mod_exp(ll a, ll b, ll m = MOD) {
    ll res = 1;
    a %= m;
    while (b > 0) {
        if (b & 1) res = (res * a) % m;
        a = (a * a) % m;
        b >>= 1;
    }
    return res;
}

int f(vector<int>&prices,vector<int>&pages,int &m,int x,int idx,vector<vector<int>>&dp){
    if(idx==m) return 0;
    if(x<=0) return 0;
    if(dp[idx][x]!=-1) return dp[idx][x];
    int ans=0;
    if(prices[idx]<=x) ans=max(ans,pages[idx]+f(prices,pages,m,x-prices[idx],idx+1,dp));
    ans=max(ans,f(prices,pages,m,x,idx+1,dp));
    return dp[idx][x]=ans;
}

int main() {
    fast_io;

    int t = 1;  
    while (t--) {
        int m,x;
        cin>>m>>x;
        vector<int>prices(m);
        for(int i=0;i<m;i++) cin>>prices[i];
        vector<int>pages(m);
        for(int i=0;i<m;i++) cin>>pages[i];
        vector<vector<int>>dp(m+1,vector<int>(x+10,-1));
        int ans=f(prices,pages,m,x,0,dp);
        cout<<ans;
    }

    return 0;
}