#include <iostream>
using namespace std;

int rodCutting(int prices[], int n, int length) {
    if (length <= 0)
        return 0;

    int maxRevenue = 0;
    for (int i = 0; i < n; ++i) {
        if (i < length)
            maxRevenue = max(maxRevenue, prices[i] + rodCutting(prices, n, length - i - 1));
    }

    return maxRevenue;
}

int main() {
    int n;
    cout << "Enter the number of rod pieces: ";
    cin >> n;

    int prices[n];
    cout << "Enter the prices of rod pieces: ";
    for (int i = 0; i < n; ++i) {
        cin >> prices[i];
    }

    int length;
    cout << "Enter the length of the rod: ";
    cin >> length;

    cout << "Maximum revenue: " << rodCutting(prices, n, length) << endl;

    return 0;
}
