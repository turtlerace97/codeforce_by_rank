
/*
*   Time :
*   Subject : greedy constructive
* 
*	n>3 인 경우를 먼저 살펴보면 문제 조건에 맞게 무조건 mx * n으로 만들 수 있다. 
*	
*	n==3인 경우 , n==2 인 경우는 따로 처리해주면 된다. 
*
*   Coded by soonyubing
*/

#include <bits/stdc++.h>
#define ll long long
#define pii  pair<int, int>
#define pll pair<ll, ll>
// INT_MAX INT_MIN LLONG_MAX LLONG_MIN
using namespace std;
inline long long gcd(long long a, long long b) { return b ? gcd(b, a % b) : a; }

void solve()
{
	ll n; cin >> n;
	vector<ll> v(n);
	for (ll& x : v) cin >> x;
	if (n == 2)
	{
		cout << max(v[0] + v[1], 2 * abs(v[0] - v[1])) << "\n";
		return;
	}
	if (n == 3)
	{
		ll mx = 0;
		mx = max(3 * v[0],mx);
		mx = max(3 * v[2], mx);
		mx = max(v[0] + v[1] + v[2],mx);
		mx = max(3 * abs(v[0] - v[1]), mx);
		mx = max(3 * abs(v[1] - v[2]), mx);
		cout << mx << "\n";
		return;
	}
	cout <<  *max_element(v.begin(), v.end()) * n << "\n";
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t; cin >> t;
	while (t--) solve();
	return 0;
}


