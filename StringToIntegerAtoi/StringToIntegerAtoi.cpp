#include <bits/stdc++.h>
#include "../crio/cpp/io/FastIO.hpp"
using namespace std;

class StringToIntegerAtoi {
public:
    // Implement your solution by completing the below function	
    long long myAtoi(string str) {
    	long long ans = 0;
		if(str.size()==0)
			return ans;
		string fin="";
		int sign=1,temp_flag=1;
		int ind;
		for(int i=0;i<(int)str.size();i++)
		{
			if(str[i]!=' ' && (int(str[i])>=48 && int(str[i])<=57))	
			{
				fin.push_back(str[i]);
			}
			if(str[i]=='-' && temp_flag==1){
				sign=-1;
				ind=i;
				temp_flag=0;
			}
		}
		
		if((int)fin.size()==0)
			return 0;
		
		int flag=0;
		for(int j=ind;j<(int)str.size();j++)
		{
			if(str[j]!=' ' && (int(str[j])>=48 && int(str[j])<=57))	
			{
				flag=1;
			}
		}
		if(flag==0)
			sign=1;
		
		int i=0;
		while(fin[i]=='0')
		{
			i++;
		}
		if(i==(int)fin.size())
			return 0;
		
		string final;
		final=fin.substr(i,(int)fin.size()-i);

		stringstream answer(final);
		answer>>ans;
        return ans*sign;
    }
};

int main() {
	FastIO();
	string str;
	cin >> str;
	long long result = StringToIntegerAtoi().myAtoi(str);
	cout << result;
	return 0;
}
