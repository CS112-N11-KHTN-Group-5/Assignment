#include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;
using _ii = pair<int,int>;

int main()
{
    freopen("input1.txt","r",stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n,k; cin >> n >> k;
	vector <vector<i64>> a(n,vector<i64>(n));
	i64 maxx = -1;
	for(auto &i: a)
	{
		for(auto &j: i) cin >> j;
		maxx = max(maxx,*max_element(i.begin(),i.end()));
	}
	auto Check = [&](i64 val)
	{
		vector <int> dsu(n);
		for(int i = 0; i < n; ++i) dsu[i] = i;
		auto Find = [&](int h)
		{
			int g = h;
			while(dsu[g] != g) g = dsu[g];
			dsu[h] = g;
			return dsu[h];
		};
		for(int i = 0; i < n; ++i)
		{
			for(int j = 0; j < n; ++j)
			{
				if(a[i][j] >= val) continue;
				int x = Find(i);
				int y = Find(j);
				if(x < y) dsu[y] = x;
				if(x > y) dsu[x] = y;
			}
		}
		int cnt = 0;
		for(int i = 0; i < n; ++i)
		{
			if(Find(i) == i) ++cnt;
		}
		return cnt >= k;
	};
	i64 L = 0, R = maxx;
	while(L < R)
	{
		int mid = (L+R+1) >> 1;
		if(Check(mid)) L = mid;
		else R = mid-1;
	}
	cout << L << '\n';
}