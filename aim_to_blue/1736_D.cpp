
/*
*   Time :
*   Subject :
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

const ll MAXN = 111;
const ll mod = 1e9 + 7;

ll nCr[MAXN][MAXN];

void precompute()
{
	for (int i = 0; i < MAXN; i++)
	{
		nCr[i][0] = 1;
	}

	for (int i = 1; i < MAXN; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			nCr[i][j] += nCr[i - 1][j]; nCr[i][j] %= mod;
			if (j - 1 >= 0) nCr[i][j] = (nCr[i][j] + nCr[i - 1][j - 1]) % mod;
			//cout << i << "C" << j << " " << nCr[i][j] << "\n";
		}
	}

}

void solve()
{
	ll n, i, j, x, y; cin >> n >> i >> j >> x >> y;
	
	if (x > y)
	{
		i = n - i + 1;
		j = n - j + 1;
		swap(i, j);
		swap(x, y);
	}

	if (y == n)
	{
		if (j == n) cout << "0\n";
		else
		{
			ll ans = nCr[x - 1][i - 1];
			ans = (ans * nCr[y - x - 1][j - i - 1]) % mod;
			cout << ans << "\n";
		}

		return;
	}

	ll ans1 = 0;

	if(x-1>=0&&i-1>=0) ans1 = nCr[x - 1][i - 1];
	
	if ((y - x - 1 >= 0) && (n - j - (x - i) >= 0)) ans1 = (ans1 * nCr[y - x - 1][n - j - (x - i)]) % mod;
	else ans1 = 0;
	ll temp = 0;
	for (int k = i + 1; k <= j - 1; k++)
	{
		if(n-y-1>=0&&j-k-1>=0) temp += nCr[n - y - 1][j - k - 1];
		temp %= mod;
	}
	ans1 = (ans1 * temp) % mod;

	ll ans2 = 0;
	temp = 0;

	if (x - 1 >= 0 && i - 1 >= 0)ans2 = nCr[x - 1][i - 1];
	if (y - x - 1 >= 0 && j - i - 1 >= 0)ans2 = (ans2 * nCr[y - x - 1][j - i - 1]) % mod;
	else ans2 = 0;
	
	for (int k = j + 1; k <= n - 1; k++)
	{
		if (n - y - 1 >= 0 && k-j - 1 >= 0)temp += nCr[n - y - 1][k - j - 1];
		temp %= mod;
	}
	ans2 = (ans2 * temp) % mod;
	
	ll ans = (ans1 + ans2) % mod;
	
	cout << ans << "\n";

}

int main()
{

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	precompute();
	int t; cin >> t;
	while (t--) solve();
	return 0;
}


