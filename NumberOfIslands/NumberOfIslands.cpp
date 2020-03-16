 #include <bits/stdc++.h>
#include "../crio/cpp/io/FastIO.hpp"
#include "../crio/cpp/io/ReadMatrix.hpp"
#include "../crio/cpp/io/PrintMatrix.hpp"
using namespace std;
int vis[1000][1000];
int n,m;
class NumberOfIslands {
public:
    // Implement your solution by completing the below function
	bool valid(int i,int j)
	{
		if(i>=0 && i<n && j>=0 && j<m)
			return true;
		return false;
	}
	void dfs(vector<string> grid,int i,int j)
	{
		queue<pair<int,int>> q;
		q.push({i,j});
		vis[i][j]=true;
		while(!q.empty())
		{
			pair<int,int> p=q.front();
			q.pop();
			vis[p.first][p.second]=true;
			if(valid(p.first+1,p.second) && grid[p.first+1][p.second]=='1' && vis[p.first+1][p.second]==false)
			{
				q.push({p.first+1,p.second});
			}
			if(valid(p.first-1,p.second) && grid[p.first-1][p.second]=='1' && vis[p.first-1][p.second]==false)
			{
				q.push({p.first-1,p.second});
			}
			if(valid(p.first,p.second+1) && grid[p.first][p.second+1]=='1' && vis[p.first][p.second+1]==false)
			{
				q.push({p.first,p.second+1});
			}
			if(valid(p.first,p.second-1) && grid[p.first][p.second-1]=='1' && vis[p.first][p.second-1]==false)
			{
				q.push({p.first,p.second-1});
			}
		}
	}
    int numIslands(vector<string>& grid) {
        int x = 0;
		n=grid.size();
		m=grid[0].size();
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
			{
				vis[i][j]=false;
			}
		}
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
			{
				if(grid[i][j]=='1' && vis[i][j]==false)
				{
					dfs(grid,i,j);
					x++;
				}
			}
		}
        return x;
    }
};

int main() {
    FastIO();
	int n, m;
	cin >> n >> m;
	vector<string> grid;
	ReadMatrix<string>().OneDMatrix(n, grid);
	int result = NumberOfIslands().numIslands(grid);
	cout << result;
	return 0;
}
