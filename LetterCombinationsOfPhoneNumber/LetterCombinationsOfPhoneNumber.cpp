#include <bits/stdc++.h>
#include "../crio/cpp/io/FastIO.hpp"
#include "../crio/cpp/io/PrintMatrix.hpp"
using namespace std;

class LetterCombinationsOfPhoneNumber {
public:
    // Implement your solution by completing the below function

	string options[]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};

    vector<string> letterCombinations(string digits) {
    	vector<string> res;
		res.push_back(options[0]);	

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
