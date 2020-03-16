#include <bits/stdc++.h>
using namespace std;

// Implement your solution by completing the below function
vector<int> spiralOrder(vector<vector<int> > &matrix)
{
        vector<int> res;
        if (matrix.size() == 0)
                return res;
        if (matrix.size() != 0 && matrix[0].size() == 0)
                return res;
        int i, j, n, m;
        i = 0;
        j = 0;
        n = matrix.size();
        m = matrix[0].size();
        while (i < n && j < m)
        {
                for (int k = j; k < m; k++)
                        res.push_back(matrix[i][k]);
                for (int k = i + 1; k < n; k++)
                        res.push_back(matrix[k][m - 1]);
                if (i + 1 < n)
                {
                        for (int k = m - 2; k >= j; --k)
                                res.push_back(matrix[n - 1][k]);
                }
                if (j < m - 1)
                {
                        for (int k = n - 2; k > i; --k)
                                res.push_back(matrix[k][j]);
                }

                i++;
                j++;
                m--;
                n--;
        }
        return res;
}
vector<vector<int> > merge(vector<vector<int> > &intervals)
{
        long long sz = intervals.size();
        vector<vector<int> > res(sz);
        if (intervals.size() == 0)
                return res;
        if (intervals.size() != 0 && intervals[0].size() == 0)
                return res;
        if (intervals.size() == 1)
                return intervals;
        if (intervals.size() == 2)
        {
                sort(intervals.begin(), intervals.end());
                vector<vector<int> > ans(1);
                if (intervals[0][1] >= intervals[1][0])
                {
                        ans[0].push_back(min(intervals[0][0], intervals[1][0]));
                        ans[0].push_back(max(intervals[0][1], intervals[1][1]));
                        return ans;
                }

                return intervals;
        }
        sort(intervals.begin(), intervals.end());

        int i = 0;
        int ctr = 0;
        int flag = 0;
        int start, j;
        while (i < sz - 1)
        {
                start = i, j = i + 1;
                int end = intervals[start][1];
                //cout<<intervals[i][0]<<endl;
                while (j != sz && end >= intervals[j][0])
                {
                        end = max(end, intervals[j][1]);
                        j++;
                        flag = 1;
                }
                if (flag == 1)
                {
                        res[ctr].push_back(intervals[i][0]);
                        res[ctr].push_back(end);
                        ctr++;
                        i = j;
                        flag = 0;
                }
                else
                {
                        res[ctr].push_back(intervals[i][0]);
                        res[ctr].push_back(intervals[i][1]);
                        ctr++;
                        flag = 0;
                        i++;
                }
        }
        if (j != sz)
        {
                res[ctr].push_back(intervals[sz - 1][0]);
                res[ctr].push_back(intervals[sz - 1][1]);
        }
        vector<vector<int> > ans;
        for (int i = 0; i < (int)res.size(); i++)
        {
                if (res[i].size() > 0)
                        ans.push_back(res[i]);
        }
        sort(ans.begin(), ans.end());

        return ans;
}
bool canMessageBePassed(int n, vector<vector<int> > maze)
{
        bool possible = true;
        vector<int> spi = spiralOrder(maze);

        vector<vector<int> > ranges((int)spi.size());
        int ctr = 0;
        for (int i = 0; i < (int)spi.size(); ++i)
        {
                if (spi[i] != 0)
                {
                        ranges[ctr].push_back(i);
                        ranges[ctr].push_back(i + spi[i]);
                        ctr++;
                }
        }

        vector<vector<int> > ans = merge(ranges);
        int lst=ans.size();
        if(ans[lst-1][1] < n*n - 1)
            possible=false;

        return possible;
}

int main()
{
        int n, s, m;
        cin >> n >> s >> m;
        assert(1 <= n && n <= 500);
        assert(1 <= s && s <= 1e5);
        assert(1 <= m && m <= 1e5);

        vector<vector<int> > maze(n, vector<int>(n, 0));
        maze[0][0] = s;

        for (int i = 0; i < m; ++i)
        {
                int x, y, p;
                cin >> x >> y >> p;
                assert(0 <= x && x < n);
                assert(0 <= y && y < n);
                assert(1 <= p && p <= 1e5);
                maze[x][y] = max(maze[x][y], p);
        }
        bool possible = canMessageBePassed(n, maze);
        cout << (possible ? "Yes\n" : "No\n");
}
