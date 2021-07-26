#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>


class Solution {

    void print(int** dp, int n, int m, std::string word1, std::string word2) const {
        std::cout << "  | $ ";

        for (int i = 0; i < m; ++i) {
                std::cout << word2[i] << " " ;
        }
        std::cout << std::endl;

        for (int i = 0; i < m * 2 + 5; ++i) {
            std::cout << "-";
        }
        std::cout << std::endl;

        for (int i = 0; i < n + 1; ++i) {
            if (i == 0) {
                std::cout << "$ | ";
            } else {
                std::cout << word1[i - 1] << " | ";
            }
            for (int j = 0; j < m + 1; ++j) {
                std::cout << dp[i][j] << " " ;
            }
            std::cout << std::endl;
        }
        std::cout << std::endl;
    }

public:
    int minDistance(const std::string word1, const std::string word2) {

        size_t const n = word1.length();
        size_t const m = word2.length();

        // execution version
        int dp[n + 1][m + 1];

        for (int i = 0; i < n + 1; ++i) dp[i][0] = i;
        for (int i = 0; i < m + 1; ++i) dp[0][i] = i;


        for (int i = 1; i < n + 1; ++i) {
            for (int j = 1; j < m + 1; ++j) {
                dp[i][j] = word1[i - 1] == word2[j - 1] ? 
                    dp[i - 1][j - 1] :
                    std::min(std::min(dp[i - 1][j], dp[i][j - 1]), dp[i - 1][j - 1]) + 1;
            }
        }

        return dp[n][m];
    }
};

int main() {
	Solution s;
	std::cout << s.minDistance("horse", "ros") << std::endl;
	std::cout << s.minDistance("intention", "execution") << std::endl;
}