
/*
*   Time :
*   Subject : greedy 
* 
*	가장 작은 원소를 만들기 위해선 모든 bit를 0으로 해야되고 
*	가장 큰 원소를 만들기 위해선 모든 bit를 1로 만들어야 함 
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
	int n; cin >> n;
	vector<int> v(n);
	int mx = 0, mn = 1024;
	for (int& x : v) cin >> x;
	sort(v.begin(), v.end());

	for (int i = 0; i < 11; i++)
	{
		if ((v[n-1] & (1 << i)) == 0)
		{
			for (int j = 0; j < n - 1; j++)
			{
				if (v[j] & (1 << i))
				{
					v[j] &= ~(1 << i);
					v[n - 1] |= (1 << i);
					break;
				}
			}
		}
		if ((v[0] & (1 << i)) )
		{
			for (int j = 1; j < n; j++)
			{
				if (!(v[j] & (1 << i)))
				{
					v[j] |= (1 << i);
					v[0] &= ~(1 << i);
					break;
				}
			}
		}
	}
	//cout << v[n - 1] << " " << v[0] << "\n";
	cout <<v[n-1] - v[0] << "\n";
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


