#include <bits/stdc++.h>
#include "../crio/cpp/io/FastIO.hpp"
#include "../crio/cpp/io/ReadMatrix.hpp"
#include "../crio/cpp/io/PrintMatrix.hpp"
using namespace std;

class MergeIntervals {
public:
	// Implement your solution by completing the below function
	// I have submitted the same code on leetcode too https://leetcode.com/user1329f/ this is my account.
	//
	vector<vector<int>> merge(vector<vector<int>>& intervals) {
	long long sz=intervals.size();
        vector<vector<int>> res(sz);
        if(intervals.size()==0)
            return res;
        if(intervals.size()!=0 && intervals[0].size()==0)
            return res;
        if(intervals.size()==1)
            return intervals;
        if(intervals.size()==2)
        {
            sort(intervals.begin(),intervals.end());
            vector<vector<int> > ans(1);
            if(intervals[0][1]>=intervals[1][0])
            {
                ans[0].push_back(min(intervals[0][0],intervals[1][0]));
                ans[0].push_back(max(intervals[0][1],intervals[1][1]));
                return ans;
            }
            
            return intervals;
        }
        sort(intervals.begin(),intervals.end());
        
        int i=0;
        int ctr=0;
        int flag=0;
        int start,j;
        while(i<sz-1)
        {
            start=i,j=i+1;
            int end=intervals[start][1];
            //cout<<intervals[i][0]<<endl;
            while(j!=intervals.size() && end>=intervals[j][0]){
                end=max(end,intervals[j][1]);
                j++;
                flag=1;
            }
            if(flag==1){
                res[ctr].push_back(intervals[i][0]);
                res[ctr].push_back(end);
                ctr++;
                i=j;
                flag=0;
            }
            else{   
                res[ctr].push_back(intervals[i][0]);
                res[ctr].push_back(intervals[i][1]);
                ctr++;
                flag=0;
                i++;
            }
        }
        if(j!=sz){
        res[ctr].push_back(intervals[sz-1][0]);
        res[ctr].push_back(intervals[sz-1][1]);
        }
        vector<vector<int> > ans;
        for(int i=0;i<res.size();i++)
        {
            if(res[i].size()>0)
                ans.push_back(res[i]);
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};

int main() {
    FastIO();
	int n;
	cin >> n;
	vector<vector<int>> nums;
	ReadMatrix<int>().TwoDMatrix(n, 2, nums);
	vector<vector<int>> result = MergeIntervals().merge(nums);
	PrintMatrix<int>().TwoDMatrix(result);
	return 0;
}
