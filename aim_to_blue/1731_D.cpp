
/*
*   Time : 
*   Subject : 이분탐색, prefix sum
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

int n, m;

bool check(int mid, vector<vector<int>> v)
{
	vector<vector<int>> psum(n + 1, vector<int>(m + 1, 0));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (v[i][j] >= mid) v[i][j] = 1;
			else v[i][j] = 0;
			psum[i + 1][j + 1] = psum[i][j + 1] + psum[i + 1][j] - psum[i][j] + v[i][j];
		}
	}

	for (int i = mid; i <= n; i++)
	{
		for (int j = mid; j <= m; j++)
		{
			int temp = psum[i][j] - psum[i - mid][j] - psum[i][j - mid] + psum[i - mid][j - mid];
			if (temp == mid * mid) return true;
		}
	}
	return false;
}

void solve()
{
	
	cin >> n >> m;
	vector<vector<int>> v(n, vector<int>(m));
	
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> v[i][j];
		}
	}
	int lo = 0, hi = min(n, m), ans = lo;
	while (lo <= hi)
	{
		int mid = (lo + hi) / 2;
		if (check(mid,v))
		{
			lo = mid + 1;
			ans = mid;
		}
		else
		{
			hi = mid - 1;
		}
	}
	cout << ans << "\n";
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


