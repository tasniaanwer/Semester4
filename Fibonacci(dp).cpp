#include <iostream>

using namespace std;

const int MAX = 100;
int memo[MAX];

int fibonacci(int n) {
    if (n <= 1)
        return n;

    if (memo[n] == 0)
        memo[n] = fibonacci(n - 1) + fibonacci(n - 2);

    return memo[n];
}

int main() {
    int n ;
    cin>>n;
    cout << "Fibonacci(" << n << ") = " << fibonacci(n) << endl;
    return 0;
}

