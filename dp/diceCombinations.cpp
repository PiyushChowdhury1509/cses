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

int f(int n,ll sum,vector<ll>&dp){
    if(sum==n) return 1;
    if(sum>n) return 0;
    if(dp[sum]!=-1) return dp[sum];
    int ans=0;
    for(int i=1;i<=6;i++){
        ans=(ans+f(n,sum+i,dp))%MOD;
    }
    return dp[sum]=ans%MOD;
}

int bu(int n,vector<ll>&dp2){
    dp2[0]=1;
    dp2[1]=1;
    dp2[2]=2;
    for(int i=3;i<=n;i++){
        for(int j=1;j<=6;j++){
            if(i-j<0) continue;
            else dp2[i]=(dp2[i]+dp2[i-j])%MOD;
        }
    }
    return dp2[n];
}

int main() {
    fast_io;

    int t = 1;  
    while (t--) {
        int n;
        cin>>n;
        vector<ll>dp(n+5,-1);
        vector<ll>dp2(n+1,0);
        ll ans = bu(n,dp2);
        cout<<ans;
    }

    return 0;
}