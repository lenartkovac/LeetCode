#include <iostream>
#include <string>
#include <vector>
#include <algorithm>


class Solution {
public:
	bool isPalindrome(std::string s, const size_t i, const size_t j) const {
		// Break conditions
		if (i >= j) {
			return true;
		}

		// continuation
		if (s[i] == s[j]) {
			return isPalindrome(s, i + 1, j - 1);
		} else {
			return false;
		}
	}

	void print(bool** dp, std::string s) {
		size_t const n = s.length();

		std::cout << "    ";
		for (int i = 0; i < n; ++i) {
			std::cout << s[i] << " ";
		}
		std::cout << std::endl;
	
		for (int i = 0; i < n * 2 + 3; ++i) {
			std::cout << "-";
		}
		std::cout << std::endl;

		for (int i = 0; i < n; ++i) {
			std::cout << s[i] << " | ";

			for (int j = 0; j < n; ++j) {
				std::cout << dp[i][j] << " ";
			}
			std::cout << std::endl;
		}

	}

	std::string longestPalindrome(const std::string s) {

		size_t const n = s.length();
		bool dp[n][n];
		//bool** dp = (bool**) malloc(n * sizeof(bool*));
		//for (int i = 0; i < n; ++i) dp[i] = (bool*) malloc(n * sizeof(bool));

		// init space
		for (int i = 0; i < n; ++i) dp[i][i] = true;
		for (int i = 0; i < n; ++i) 
			for (int j = 0; j < i; ++j) 
				dp[i][j] = true;

		// search
		for (int i = n - 1; i >= 0; --i) {
			for (int j = n - 1; j > i; --j) {
				if (s[i] == s[j]) {
					dp[i][j] = dp[i + 1][j - 1];
				} else {
					dp[i][j] = false;
				}
			}
		}

		//find best solution
		size_t maxI = -1;
		size_t maxJ = -1;
		int maxDistance = -1;

		for (int i = 0; i < n; ++i) {
			for (int j = i; j < n; ++j) {
				if (dp[i][j]) {
					//std::cout << i << " " << j << std::endl;
					int distance = j - i + 1;
					//std::cout << distance << " " << maxDistance << std::endl;
					if (distance > maxDistance) {
						maxI = i;
						maxJ = j;
						maxDistance = distance;
						//std::cout << "new max palindrome " << i << " " << j << std::endl;
						//std::cout << "with distance " << maxDistance << std::endl;
					}
				}
			}
		}

		//std::cout << "final max palindrome " << maxI << " " << maxJ << std::endl;
		//std::cout << "with distance " << maxDistance << std::endl;


		return s.substr(maxI, maxDistance);
	}

};

int main() {


	std::vector<std::string> tests {
		"babad",
		"cbbd",
		"aba",
		"a",
		"ac"
	};

	Solution s;

	for (const std::string test : tests) {
		std::cout << test << ": " << std::endl;
		std::cout << s.longestPalindrome(test) << std::endl;
	}

	return 0;
}
