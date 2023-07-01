#include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;
using _ii = pair<int,int>;
class Solution {
public:
	int Cal(vector <pair<_ii,_ii>> &a)
	{
		vector <vector<int>> matrix(100,vector<int>(100));
		for(auto &element : a)
		{
			for(int i = element.first.first; i < element.second.first; ++i)
			{
				for(int j = element.first.second; j < element.second.second; ++j)
				{
					matrix[i][j] = 1;
				}
			}
		}
		int ans = 0;
		for(auto &i: matrix)
		{
			for(auto &j: i) ans += j;
		}
		return ans;
	};
    int projectionArea(vector<vector<int>>& grid) {
        vector <pair<_ii,_ii>> xy, yz, xz;
        for(int i = 0; i < grid.size(); ++i)
        {
        	for(int j = 0; j < grid[i].size(); ++j)
        	{
        		int h = grid[i][j];
        		if(!h) continue;
        		xy.push_back({{i,j},{i+1,j+1}});
        		yz.push_back({{j,0},{j+1,h}});
        		xz.push_back({{i,0},{i+1,h}});
        	}
        }
        return Cal(xy)+Cal(yz)+Cal(xz);
    }
};
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	Solution sol;
	vector <vector<int>> input = {{1,2},{3,4}};
	cout << sol.projectionArea(input) << '\n';
}