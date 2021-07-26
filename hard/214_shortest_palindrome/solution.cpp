//?You are given a string s. You can convert s to a palindrome by adding characters in front of it.
//?Return the shortest palindrome you can find by performing this transformation.

//*Example 1:
//*Input: s = "aacecaaa"
//*Output: "aaacecaaa"

//*Example 2:
//*Input: s = "abcd"
//*Output: "dcbabcd"


//!Constraints:
//!0 <= s.length <= 5 * 104
//!s consists of lowercase English letters only.

#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <chrono>
#include <algorithm>

class Solution {
	//! recursive
	//bool isPalindrome(const std::string s, size_t i, const size_t j) const {
	//	if (i >= j) return true;
	//	if (s[i] == s[j])
	//		return isPalindrome(s, i + 1, j - 1);
	//	return false;
	//}

	//size_t palindromeIndex(const std::string s) {
	//	size_t n = s.length();
	//	
	//	//bool dp[n / 2 + 1][n];
	//	size_t size = n / 2 + 1;

	//	bool** dp = (bool**) malloc((n / 2 + 1) * sizeof(bool*));

	//	for (int i = 0; i < size; ++i) {
	//		dp[i] = (bool*) malloc((n - i) * sizeof(bool));
	//	}

	//	//for (int i = 0; i < n / 2 + 1; ++i) {
	//	//	dp[i][i] = true;
	//	//}

	//	for (int i = n / 2; i >= 0; --i) {
	//		for (int j = n - i - 1; j > i; --j) {
	//			if (s[i] == s[j])  {
	//				if (i + 1 < j - 1) {
	//					dp[i][j] = dp[i + 1][j - 1];
	//				} else {
	//					dp[i][j] = true;
	//				}
	//			} else {
	//				dp[i][j] = false;
	//			}
	//		}
	//	}

	//	size_t maxJ = 0;
	//	for (maxJ = n - 1; maxJ > 0; --maxJ) {
	//		if (dp[0][maxJ]) {
	//			break;
	//		}
	//	}

	//	std::cout << "Longest palindrome: " << s.substr(0, maxJ + 1) << std::endl;

	//	return maxJ;
	//}

//public:

	//std::string shortestPalindrome(std::string s) {
	//	// do one pass to find the longest palindrome
	//	// TODO: optimize
	//	if (!s.compare("")) return "";

	//	size_t maxJ = palindromeIndex(s);

	//	//std::cout << maxJ << " " << s.substr(0, maxJ + 1) << std::endl;
	//	//std::cout << "remaining: " << s.substr(maxJ + 1, s.length() - maxJ + 1) << std::endl;

	//	std::string prefix = "";

	//	for (int i = s.length() - 1; i > maxJ; --i) {
	//		prefix += s[i];
	//	}

	//	// mirror and append the remaining bit
	//	return prefix + s;
 //   }

public:
    std::string shortestPalindrome(const std::string s) {
		size_t const n = s.length();
		size_t i = 0;

		for (int j = n - 1; j >= 0; --j) {
			//std::cout << "hello " << n  << " " << i << " " << j << std::endl;
			if (s[i] == s[j]) {
				++i;
			}
			//std::cout << "hi" << std::endl;
		}

		// string is palindrome
		if (i == n) {
			return s;
		}

		std::string rem = s.substr(i);
		std::cout << i << " rem: " << rem << std::endl;
		std::cout << i << "s: " << s << " rem: " << rem << std::endl;

		std::reverse(rem.begin(), rem.end());

		return rem + shortestPalindrome(s.substr(0, i)) + s.substr(i);
    }
};

int main() {

	std::vector< std::pair<std::string, std::string> > tests = {
		std::make_pair("aacecaaa", "aaacecaaa"),
		std::make_pair("abcd", "dcbabcd"),
		std::make_pair("aaaaaaaaaa", "aaaaaaaaaa"),
		std::make_pair("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa",
		"aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"),
		std::make_pair("abcdba", "abdcbabcdba")
	};

	Solution s;
	for (auto test : tests) {
		//std::cout << test.first << " " << test.second << std::endl;
		auto start = std::chrono::high_resolution_clock::now();

		std::string output = s.shortestPalindrome(test.first);

		bool result = test.second.compare(output) == 0;
		std::string status = result ? "OK" : "NOK";

		std::cout << test.first << ": " << std::endl;
		std::cout << "Expected: " << test.second << std::endl;
		std::cout << "Result: " << output << std::endl;
		std::cout << status << std::endl;
		
		auto stop = std::chrono::high_resolution_clock::now();
		auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
		
		std::cout << "Duration: " << duration.count() << " micros" << std::endl;
		
		for (int i = 0; i < 30; ++i) {
			std::cout << '-';
		}
		std::cout << std::endl;

	}

	return 0;
}