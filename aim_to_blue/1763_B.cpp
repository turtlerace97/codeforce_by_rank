
/*
*   Time :
*   Subject : sorting, implementation 
* 
*	문제에서 요구하는 대로 구현하면 됨 
*	중요한 건 살아있는 몬스터 중 가장 약한 힘을 제거해야한다는 점
*	이를 위해서 hash map을 사용했음
*	
*	multiset.erase(val) : val에 속하는 모든 값을 삭제함 
*	하나만 삭제하고 싶을경우 
*	multiset.erase(multiset.find(val)); 
* 
*	map에서 가장 작은 원소 또는 가장 큰 원소를 참조하고 싶을경우 mp.begin()->first (mp.end()-1)->first; 
*	map의 가장 마지막원소는 비어있는 container를 가르키므로 
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

struct compare
{
	bool operator()(pii a, pii b)
	{
		return a.first > b.first;
	}
};


void solve()
{
	
	int n, k; cin >> n >> k;
	vector<int> h(n), p(n);
	for (int& x : h) cin >> x;
	for (int& x : p) cin >> x;

	priority_queue<pii, vector<pii>, compare> pq;
	multiset<int> st;
	map<int, int> mp;

	for (int i = 0; i < n; i++)
	{
		pq.push({ h[i],p[i] });
		st.insert(p[i]);
		mp[p[i]]++;
	}
	ll psum = k;
	while (psum > 0 && !pq.empty())
	{
		
		while (!pq.empty() && pq.top().first <= psum)
		{
			
			mp[pq.top().second]--; 
			if (mp[pq.top().second] == 0) mp.erase(pq.top().second);
			pq.pop();
		}
		
		if (!pq.empty()) k -= mp.begin()->first;
		psum += k;
	}
	cout << (pq.empty() ? "YES\n" : "NO\n");
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


