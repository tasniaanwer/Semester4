#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, a, b;
    cin >> n >> a >> b;

    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    long long max_sum = INT_MIN;
    long long current_sum = 0;
    int window_size = 0;

    for (int i = 0; i < n; ++i) {
        current_sum += arr[i];
        window_size++;

        if (window_size > b) {
            current_sum -= arr[i - b];
            window_size--;
        }

        if (window_size >= a) {
            max_sum = max(max_sum, current_sum);
        } else if (window_size < a) {
            current_sum = 0;
        }
    }

    cout << max_sum << endl;

    return 0;
}
