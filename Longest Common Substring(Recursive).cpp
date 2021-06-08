/*
    ENJOY CP !!!!
    Author :- Malav Gajjar
*/
#include<bits/stdc++.h>
//#include<ext/pd_ds/assoc_container.hpp>
//#include<ext/pd_ds/tree_policy.hpp>
//#include<ext/pd_ds/trie_policy.hpp>
using namespace std;

#define fio             ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define ll              long long int 
#define ld              long double
#define mod             1000000007
#define inf             1e18
#define endl            "\n"
#define pb              push_back
#define vi              vector<ll>
#define vs              vector<string>
#define pi              pair<ll, ll>
#define ump             unordered_map
#define mp              make_pair
#define pq_max          priority_queue<ll>
#define pq_min          priority_queue<ll, vi, greater<ll> >
#define all(v)          v.begin(), v.end()
#define ff              first
#define ss              second
#define rs              resize
#define ub              upper_bound
#define lb              lower_bound
#define mid(l, r)       (l + (r-l)/2)
#define bitc(x)         __builtin_popcount(x)
#define sp(a)           setprecision(a)
#define loop(a, b, c)   for(a=b; a<=c; a++)
#define loop_r(a, b, c) for(a=b; a<=c; a++)
#define itr(c)          for(auto it=c.begin(); it!=c.end(); it++)
#define log(x)          cout << #x << ' ' << x;
#define out(arr, a, b)  for(ll i=(a); i<=(b); i++)  cout << arr[i] << ' ';  cout << '\n';

template <typename T> T gcd(T a, T b) { if(a%b) return gcd(b, a%b); return b; }
template <typename T> T lcm(T a, T b) { return (a*b/gcd(a, b)); }

void file_i_o()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
}

ll LCS(string s, string t, ll n, ll m, ll ans){
    if(m == 0 || n == 0)
        return ans;

    if(s[n-1] == t[m-1])
        return LCS(s, t, n-1, m-1, ans+1);

    ans = max(ans, max(LCS(s, t, n-1, m, 0), LCS(s, t, n, m-1, 0)));

    return ans;
}

int main(int argc, char const *argv[])
{
    /* code */
    fio;
    file_i_o();

    ll t;
    cin >> t;

    while(t--){
        string s, t;
        cin >> s >> t;
        ll n = s.length(), m = t.length(), ans=0;
        cout << LCS(s, t, n, m, ans) << '\n';
    }
    
    return 0;
}
