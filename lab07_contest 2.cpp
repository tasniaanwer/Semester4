
#include <iostream>
#include <vector>
#include <cmath>
#include <climits>
using namespace std;

int min_cost_to_reach_N(int N, int K, vector<int>& heights) {
    vector<int> dp(N, INT_MAX);
    dp[0] = 0;


    for (int i = 1; i < N; ++i) {

        for (int j = 1; j <= min(i + 1, K); ++j) {

            int cost = abs(heights[i] - heights[i - j]) + dp[i - j];

            dp[i] = min(dp[i], cost);
        }
    }


    return dp[N - 1];
}

int main() {
    int N, K;
    cin >> N >> K;
    vector<int> heights(N);
    for (int i = 0; i < N; ++i) {
        cin >> heights[i];
    }


    cout << min_cost_to_reach_N(N, K, heights) << endl;
    return 0;
}
