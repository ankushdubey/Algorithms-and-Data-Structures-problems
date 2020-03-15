#include <bits/stdc++.h>
#include "../crio/cpp/io/FastIO.hpp"
#include "../crio/cpp/io/PrintMatrix.hpp"
using namespace std;

string options[] = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};

class LetterCombinationsOfPhoneNumber {
public:
    // Implement your solution by completing the below function
		vector<string> res;
		char index=digits[0];
		string fil=options[index-'0'];
		if(fil.size()>0){
		for(int i=0;i<fil.size();i++)
            {
                res.push_back(string(1,fil[i]));
            }
		}
		else{
            res.push_back("");
		}
		for(int k=1;k<digits.size();k++)
        {
            index=digits[k];
            fil=options[index-'0'];
            if(fil.size()>0)
            {
                int ini=res.size();
                for(int i=0;i<fil.size();i++)
                {
                    for(int j=0;j<ini;j++)
                    {
                       // cout<<res[j]<<endl;
                        res.push_back(res[j]+string(1,fil[i]));
                    }
                }
                res.erase(res.begin(),res.begin()+ini);
            }
        }
        sort(res.begin(),res.end());
        for(int i=0;i<res.size();i++)
        {
            cout<<res[i]<<endl;
        }
        return res;
    }
};

int main() {
	FastIO();
	string digits;
	cin >> digits;
	vector<string> combinations = LetterCombinationsOfPhoneNumber().letterCombinations(digits);
	PrintMatrix<string>().OneDMatrix(combinations, " ");
	return 0;
}
