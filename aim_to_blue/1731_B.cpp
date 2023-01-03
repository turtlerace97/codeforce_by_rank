
/*
*   Time :
*   Subject : math, greedy 
* 
*	dp �� ó���ϱ⿣ n�� ������ ũ�Ƿ� �Ұ����ϴ�. 
*   �������� ���� ���󰡾� �ϴµ� ���� �����غ��� ��ܽ����� �������°� ���� �����̶�� ���� �� �� �ִ�. 
*	
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

const ll mod = 1e9 + 7;

void solve()
{
	ll n; cin >> n;
	ll a = n;
	ll b = n + (ll)1;
	ll c = (ll)4 * n - (ll)1;
	ll d = (ll)337;
	ll ans = a * b % mod;
	ans = (ans * c % mod) % mod;
	ans *= d; ans %= mod;
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


