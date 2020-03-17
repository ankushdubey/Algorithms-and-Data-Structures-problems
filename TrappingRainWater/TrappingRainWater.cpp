#include <bits/stdc++.h>
#include "../crio/cpp/io/FastIO.hpp"
#include "../crio/cpp/io/ReadMatrix.hpp"
using namespace std;

class TrappingRainWater
{
public:
	// Implement your solution by completing the below function`
	int trap(vector<int> &height)
	{
		int n = height.size();
		long long ans = 0;
		int mx_arr[n], mn_arr[n];
		int mx = height[n - 1];
		int mn = height[0];
		mx_arr[n - 1] = height[n - 1];
		for (int i = n - 2; i >= 0; --i)
		{
			if (height[i] > mx)
			{
				mx = height[i];
				mx_arr[i] = mx;
			}
			else
			{
				mx_arr[i] = mx;
			}
		}
		for (int i = 0; i < n; i++)
		{
			if (height[i] > mn)
			{
				mn = height[i];
				mn_arr[i] = mn;
			}
			else
			{
				mn_arr[i] = mn;
			}
		}

		for (int i = 0; i < n; ++i)
		{
			long long val = min(mx_arr[i], mn_arr[i]);
			ans += (val - height[i]);
		}
		return ans;
	}
};

int main()
{
	FastIO();
	int n;
	cin >> n;
	vector<int> heights;
	ReadMatrix<int>().OneDMatrix(n, heights);
	int result = TrappingRainWater().trap(heights);
	cout << result;
	return 0;
}
