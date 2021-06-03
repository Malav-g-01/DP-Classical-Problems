/*Given number of pages in n different books and m students. 
The books are arranged in ascending order of number of pages. 
Every student is assigned to read some consecutive books. 
The task is to assign books in such a way that the maximum 
number of pages assigned to a student is minimum. */

/* 						CP IS FUN !!!!!
	Author :- Malav Gajjar
*/
#include<bits/stdc++.h>
//#include<ext/pd_ds/assoc_container.hpp>
//#include<ext/pd_ds/tree_policy.hpp>
//#include<ext/pd_ds/trie_policy.hpp>
using namespace std;

#define fio 			ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define ll	 			long long int 
#define ld 				long double
#define mod 			1000000007
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
#define loop(i,a,b)		for(i=(a); i<=(b); i++)
#define loop_r(i,a,b)	for(i=(a); i>=(b); i--)
#define itr(c)			for(auto it=c.begin(); it!=c.end(); it++)
#define log(x) 			cout << #x << ' ' << x;
#define out(arr, a, b)	for(ll i=(a); i<=(b); i++)	cout << arr[i] << ' ';	cout << '\n';

template <typename T> T gcd(T a, T b) { if(a%b) return gcd(b, a%b); return b; }
template <typename T> T lcm(T a, T b) { return (a*b/gcd(a, b)); }

void file_i_o()
{
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif
}

bool isPossible(vi &a, ll n, ll m, ll mid)
{
	ll students = 1;
	ll sum = 0;

	for(ll i=0; i<n; i++){

		if(a[i] > mid)
			return false;

		sum += a[i];

		if(sum > mid){
			students++;
			sum = a[i];
		}

		if(students > m)
			return false;
	}

	return true;
}

ll maxPages(vi &a, ll n, ll m)
{
	ll sum = accumulate(all(a), 0);
	ll h = sum;
	ll l = 0;
	ll ans = INT_MAX;

	while(l<h){
		ll mid = (l+h)/2;

		if(isPossible(a, n, m, mid)){
			ans = min(ans, mid);
			h = mid-1;
		}

		else
			l = mid+1;
	}

	return ans;
}

int main(int argc, char const *argv[])
{
	fio;
	file_i_o();
	/* code */

	ll n, m;
	cin >> n >> m;
	vi a(n);
	ll i, j;

	loop(i, 0, n-1)
		cin >> a[i];

	cout << maxPages(a, n ,m);

	return 0;
}
