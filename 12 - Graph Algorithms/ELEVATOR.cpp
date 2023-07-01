#include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;
using _ii = pair<i64,i64>;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	i64 n,a[2],c;
	cin >> n >> a[0] >> a[1] >> c;
	n--;
	vector <int> d(c,1e9),vistited(c);
	d[0] = 0;
	priority_queue<_ii,vector<_ii>,greater<_ii>> Queue;
	Queue.push({0,0});
	while(Queue.size())
	{
		_ii h = Queue.top();
		Queue.pop();
		if(vistited[h.second]) continue;
		vistited[h.second] = 1;
		for(auto &i : a)
		{
			i64 j = (h.second+i)%c;
			i64 new_d = h.first + (h.second+i)/c;
			if(new_d < d[j])
			{
				d[j] = new_d;
				Queue.push({d[j],j});
			}
		}
	}
	i64 ans = 0;
	for(int i = 0; i < c; ++i)
	{
		if(!vistited[i]) continue;
		i64 m = n- d[i]*c;
		if(m < 0) continue;
		ans += m/c;
		if(m%c >= i) ++ans;
	}
	cout << ans << '\n';
}