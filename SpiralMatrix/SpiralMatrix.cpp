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
		if(matrix.size()==0)
			return res;
		if(matrix.size()!=0 && matrix[0].size()==0)
			return res;
		int i,j,n,m;
		i=0;j=0;
		n=matrix.size();
		m=matrix[0].size();
		while(i<n && j<m){
			for(int k=j;k<m;k++)
				res.push_back(matrix[i][k]);
			for(int k=i+1;k<n;k++)
				res.push_back(matrix[k][m-1]);
			if(i+1 < n){
			for(int k=m-2;k>=j;--k)
				res.push_back(matrix[n-1][k]);
			}
			if(j < n-1){
			for(int k=n-2;k>i;--k)
				res.push_back(matrix[k][j]);
			}
			
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
