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

int f(vector<vector<char>>&nums,int i,int j,int &m,int &n,vector<vector<int>>&dp){
    if(nums[m-1][n-1]=='*') return 0;
    if(i==m-1 && j==n-1) return 1;
    if(i>=m || j>=n) return 0;
    if(nums[i][j]=='*') return 0;
    if(dp[i][j]!=-1) return dp[i][j];
    int ans=0;
    ans=(ans+(f(nums,i+1,j,m,n,dp)%MOD)%MOD);
    ans=(ans+(f(nums,i,j+1,m,n,dp)%MOD)%MOD);
    return dp[i][j]=ans%MOD;
}

int main() {
    fast_io;

    int t = 1;  
    while (t--) {
        int n;
        cin>>n;
        int m=n;
        vector<vector<char>>nums(m,vector<char>(n));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                cin>>nums[i][j];
            }
        }
        vector<vector<int>>dp(m+5,vector<int>(n,-1));
        int ans=f(nums,0,0,m,n,dp);
        cout<<ans;
    }

    return 0;
}