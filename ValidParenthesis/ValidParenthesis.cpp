#include <bits/stdc++.h>
#include "../crio/cpp/io/FastIO.hpp"
using namespace std;

class ValidParenthesis {
public:
    // Implement your solution by completing the below function	
    bool isValid(string s) {
	stack<char> st;
	int flag=0;
	for(int i=0;i<(int)s.size();i++)
	{
		if(s[i]=='['||s[i]=='{'||s[i]=='(')
		{
			st.push(s[i]);
		}
		else
		{
			if(st.top()=='[' && (s[i]==')' || s[i]=='}'))
			{
				flag=1;
				break;
			}
			if(st.top()=='{' && (s[i]==']' || s[i]==')'))
			{
				flag=1;
				break;
			}
			if(st.top()=='(' && (s[i]=='}' || s[i]==']'))
			{
				flag=1;
				break;
			}
			st.pop();
		}
	}
	if(flag==1 || st.size()>0)
		{
			return false;
		}

		return true;
    }
};

int main() {
	FastIO();
	string s;
	getline(cin, s);
	bool result = ValidParenthesis().isValid(s);
	cout << boolalpha << result;
	return 0;
}
