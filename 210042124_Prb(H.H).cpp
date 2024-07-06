
/*Tasnia Anower Medha
  ID-210042124
  problem:H.H

*/

#include <iostream>
using namespace std;

const int MOD = 1e9 + 7;

int countWays(int n) {
    int dp[n + 1];
    dp[0] = 1;

    for (int i = 1; i <= n; ++i) {
        dp[i] = 0;
        for (int j = 1; j <= 6 && i - j >= 0; ++j) {
            dp[i] = (dp[i] + dp[i - j]) % MOD;
        }
    }

    return dp[n];
}

int main() {
    int n;
    cin >> n;

    cout << countWays(n) << endl;

    return 0;
}
