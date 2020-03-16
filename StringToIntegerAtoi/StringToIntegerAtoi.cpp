#include <bits/stdc++.h>
#include "../crio/cpp/io/FastIO.hpp"
using namespace std;

class StringToIntegerAtoi {
public:
    // Implement your solution by completing the below function	
    int myAtoi(string str) {
    	int ans = 0;
		if(str.size()==0)
		return ans;
		string fin;
		for(int i=0;i<str.size();i++)
		{
			if(str[i]!=' ' && (int(str[i])>=48 && int(str[i])<=57))	
			{
				fin.push_back(str[i]);
			}
		}
		int i=0;
		while(fin[i]=='0')
		{
			i++;
		}
		fin=fin.substr(i,(int)fin.size()-i);
		stringstream answer(fin);
		answer>>ans;
        return ans;
    }
};

int main() {
	FastIO();
	string str;
	cin >> str;
	int result = StringToIntegerAtoi().myAtoi(str);
	cout << result;
	return 0;
}
