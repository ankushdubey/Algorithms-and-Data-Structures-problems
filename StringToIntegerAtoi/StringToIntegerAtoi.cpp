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
		int sign=1;
		for(int i=0;i<(int)str.size();i++)
		{
			if(str[i]!=' ' && (int(str[i])>=48 && int(str[i])<=57))	
			{
				fin.push_back(str[i]);
			}
			if(str[i]=='-')
				sign=-1;
		}
		int i=0;
		if(fin.size()==0)
			return 0;
		while(fin[i]=='0')
		{
			i++;
		}
		if(i==(int)fin.size())
			return ans;
		fin=fin.substr(i,(int)fin.size()-i);
		stringstream answer(fin);
		answer>>ans;
        return ans*sign;
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
