
/*
*   Time :
*   Subject : math
*	
*	자세한 내용은 md 파일에
* 
*   Coded by soonyubing
*/

#include <bits/stdc++.h>
#define ll long long
#define pii  pair<ll, ll>
#define pll pair<ll, ll>
// ll_MAX ll_MIN LLONG_MAX LLONG_MIN
using namespace std;
inline long long gcd(long long a, long long b) { return b ? gcd(b, a % b) : a; }

void solve()
{
	ll n; cin >> n;
	vector<ll> v(n); vector<ll> chk(2 * n,0);
	for (ll& x : v) cin >> x;

	chk[0]++;
	ll cur = 0;
	ll ans = n * (n + 1) / 2;
	for (ll i = 0; i < n; i++)
	{
		cur ^= v[i];
		for (ll j = 0; j * j < 2 * n; j++)
		{
			if ((cur ^ (j * j)) < 2 * n)
			{
				ans -= chk[(cur ^ (j* j))];
			}
		}
		chk[cur]++;
	}
	cout << ans << "\n";
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll t; cin >> t;
	while (t--) solve();
	return 0;
}


