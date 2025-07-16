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

vector<long long> generateArray(int n, int k){
    long long x, a, b, c;
    cin >> x >> a >> b >> c;
    vector<long long> arr(n);
    arr[0] = x;
    for (int i = 1; i < n; i++) {
        arr[i] = (a * arr[i - 1] + b) % c;
    }
    return arr;
}

int main() {
    fast_io;

    int t = 1;  
    while (t--) {
        int n,k;
        cin>>n>>k;
        vector<ll>nums=generateArray(n,k);
        ll ans=0,sum=0;
        for(int i=0;i<min(n,k);i++) sum+=nums[i];
        ans^=sum;
        int i=1,j=k;
        while(j<n){
            sum-=nums[i-1];
            sum+=nums[j];
            ans^=sum;
            i++;
            j++;
        }
        cout<<ans;
    }

    return 0;
}