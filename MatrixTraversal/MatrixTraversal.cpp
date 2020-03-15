#include <bits/stdc++.h>
#include "../crio/cpp/io/FastIO.hpp"
#include "../crio/cpp/io/ReadMatrix.hpp"
#include "../crio/cpp/io/PrintMatrix.hpp"
using namespace std;

class MatrixTraversal {
public:
    // Implement your solution by completing the below function	
	int moveX(int x,int dir)
	{
		if(dir==1)
			return x;
		if(dir==2)
			return x+1;
		if(dir==3)
			return x;
		
		return x-1;
	}
	int moveY(int y,int dir)
	{
		if(dir==1)
			return y+1;
		if(dir==2)
			return y;
		if(dir==3)
			return y-1;
		
		return y;
	}
	bool valid(int x,int y,int n,int m)
	{
		if(x>=0 && x<n && y>=0 && y<m)
			return true;
		return false;
	}
    vector<int> traversalPath(vector<vector<int>>& matrix, int currPosX, int currPosY, int dirToMove, int stepsToMove) {
        vector<int> res;
		currPosX=moveX(currPosX,dirToMove);
		currPosY=moveY(currPosY,dirToMove);
		if(matrix.size()==0)
		{
			res.push_back(-1);
			return res;
		}
		if(matrix.size()!=0 && matrix[0].size()==0)
		{
			res.push_back(-1);
			return res;
		}
		if(stepsToMove==0)
			return res;

		int n=matrix.size();
		int m=matrix[0].size();
		if(valid(currPosX,currPosX,n,m)==false){
			res.push_back(-1);
			return res;
		}
		res.push_back(matrix[currPosX][currPosY]);
		stepsToMove--;
		if(stepsToMove==0)
			return res;
		while(true)
		{
			currPosX=moveX(currPosX,dirToMove);
			currPosY=moveY(currPosY,dirToMove);

			if(valid(currPosX,currPosY,n,m) && stepsToMove>0)
			{
				res.push_back(matrix[currPosX][currPosY]);
				stepsToMove--;
			}
			else
				break;
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

	int currPosX, currPosY, dirToMove, stepsToMove;
	cin >> currPosX >> currPosY;
	cin >> dirToMove >> stepsToMove;

	vector<int> result = MatrixTraversal().traversalPath(matrix, currPosX, currPosY, dirToMove, stepsToMove);
	PrintMatrix<int>().OneDMatrix(result, " ");
	return 0;
}
