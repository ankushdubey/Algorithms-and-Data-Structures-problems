#include <bits/stdc++.h>
#include "../crio/cpp/io/FastIO.hpp"
#include "../crio/cpp/io/PrintMatrix.hpp"
using namespace std;

string options[] = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};

class LetterCombinationsOfPhoneNumber {
public:
    // Implement your solution by completing the below function

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
