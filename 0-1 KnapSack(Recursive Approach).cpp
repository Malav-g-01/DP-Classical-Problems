// By Malav Gajjar
#include<bits/stdc++.h>
//#include<ext/pd_ds/assoc_container.hpp>
//#include<ext/pd_ds/tree_policy.hpp>
//#include<ext/pd_ds/trie_policy.hpp>
using namespace std;

#define fio 			ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define ll	 			long long int 
#define ld 				long double
#define mod 			1000000009
#define inf 			1e18
#define endl 			"\n"
#define pb 				push_back
#define vi 				vector<ll>
#define vs 				vector<string>
#define pii 			pair<ll, ll>
#define ump				unordered_map
#define mp 				make_pair
#define pq_max			priority_pueue<ll>
#define pq_min			priority_pueue<ll, vi, greater<ll> >
#define all(v)			v.begin(), v.end()
#define ff				first
#define ss				second
#define rs				resize
#define ub				upper_bound
#define lb				lower_bound
#define mid(l, r)		(l + (r-l)/2)
#define bitc(x)			__builtin_popcount(x)
#define sp(a)			setprecision(a)
#define loop(a, b, c)		for(ll i=(a); i<=(b); i+=c)
#define loop_r(a, b, c)	for(ll i=(a); i>=(b); i-=c)
#define itr(c)			for(auto it=c.begin(); it!=c.end(); it++)
#define log(x) 			cout << #x << ' ' << x;
#define out(arr, a, b)	for(ll i=(a); i<=(b); i++)	cout << arr[i] << ' ';	cout << '\n';
#define MAX(a, b, c) max(a, max(b, c))

template <typename T> T gcd(T a, T b) { if(a%b) return gcd(b, a%b); return b; }
template <typename T> T lcm(T a, T b) { return (a*b/gcd(a, b)); }

void file_i_o()
{
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
}

ll knapSack(vi &val, vi &wt, ll w, ll n)
{
	if(n == 0 || w == 0)
		return 0;

	if(wt[n-1] > w)
		return knapSack(val, wt, w, n-1);

	else 
		return max(knapSack(val, wt, w, n-1), val[n-1] + knapSack(val, wt, w-wt[n-1], n-1));
}

int main(int argc, char const *argv[])
{
	fio;
	file_i_o();
	/* code */

	ll n, w;
	cin >> n >> w;
	vi val(n);
	vi wt(n);

	loop(0, n-1, 1)
		cin >> val[i];

	loop(0, n-1, 1)
		cin >> wt[i];

	cout << knapSack(val, wt, w, n);

	return 0;
}
