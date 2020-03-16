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
		map<int,int> mp2;
		for(int i=0;i<(int)nums.size();i++)
		{
			mp[nums[i]]=i;
			mp[nums[i]]++;
		}
		int flag=0,val;
		for(int i=0;i<(int)nums.size();i++)
		{
			if(mp.find(target-nums[i])!=mp.end())
			{
				if((mp[target-nums[i]]!=mp[nums[i]]) && (target!=(2*nums[i]))){
					v[0]=i;
					v[1]=mp[target-nums[i]];
				}
				else if(mp2[target-nums[i]]>1){
					flag=1;
					val=target-nums[i];
					break;
				}
			}
		}
		if(flag==1)
		{
			int ctr=0;
			for(int i=0;i<(int)nums.size();i++)
			{
				if(nums[i]==val)
				{
					v[ctr]=i;
					ctr++;
				}
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
