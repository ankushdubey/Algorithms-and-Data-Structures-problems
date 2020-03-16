#include <bits/stdc++.h>
#include "../crio/cpp/io/FastIO.hpp"
#include "../crio/cpp/io/ReadMatrix.hpp"
#include "../crio/cpp/io/PrintMatrix.hpp"
using namespace std;

class TwoSum {
public:
    // Implement your solution by completing the below function	
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> v(2,0);
		map<int,int> mp;
		for(int i=0;i<(int)nums.size();i++)
		{
			mp[nums[i]]=i;
		}
		for(int i=0;i<(int)nums.size();i++)
		{
			if(mp.find(target-nums[i])!=mp.end() && mp[target-nums[i]]!=mp[nums[i]])
			{
				v[0]=i;
				v[1]=mp[target-nums[i]];
			}
		}
		sort(v.begin(),v.end());
        return v;
    }
};

int main() {
	FastIO();
	int n, target;
	cin >> n;
	vector<int> nums;
	ReadMatrix<int>().OneDMatrix(n, nums);
	cin >> target;
	vector<int> result = TwoSum().twoSum(nums, target);
	PrintMatrix<int>().OneDMatrix(result, " ");
	return 0;
}
