#include <bits/stdc++.h>
#include "../crio/cpp/io/FastIO.hpp"
#include "../crio/cpp/io/ReadMatrix.hpp"
#include "../crio/cpp/io/PrintMatrix.hpp"
using namespace std;

class SpiralMatrix {
public:
    // Implement your solution by completing the below function	
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
		int i,j,n,m;
		i=0;j=0;
		n=matrix.size();
		m=matrix[0].size();
		while(i<n && j<m){
			for(int k=i;k<m;k++)
				res.push_back(matrix[i][k]);
			for(int k=j+1;k<n;k++)
				res.push_back(matrix[k][m-1]);
			for(int k=m-2;k>j;--k)
				res.push_back(matrix[n-1][k]);
			for(int k=n-2;k>j;--k)
				res.push_back(matrix[k][i]);
			
			i++;j++;m--;n--;
		}
        return res;
    }
};

int main() {
    FastIO();
	int n, m;
	cin >> n >> m;
	vector<vector<int>> matrix;
	ReadMatrix<int>().TwoDMatrix(n, m, matrix);
	vector<int> result = SpiralMatrix().spiralOrder(matrix);
	PrintMatrix<int>().OneDMatrix(result, " ");
	return 0;
}
