#include <iostream>
#include <vector>
#include <chrono>

using namespace std;

int linear_peak_finding(const vector<int>& arr) {
    for (int i = 0; i < arr.size(); ++i) {
        if ((i == 0 || arr[i] >= arr[i - 1]) && (i == arr.size() - 1 || arr[i] >= arr[i + 1])) {
            return i;
        }
    }
    return -1;
}

int divide_and_conquer_peak_finding(const vector<int>& arr, int low, int high) {

    int mid = (low + high) / 2;

    if ((mid == 0 || arr[mid] >= arr[mid - 1]) && (mid == arr.size() - 1 || arr[mid] >= arr[mid + 1])) {
        return mid;
    } else if (arr[mid - 1] > arr[mid]) {
        return divide_and_conquer_peak_finding(arr, low, mid - 1);
    } else {
        return divide_and_conquer_peak_finding(arr, mid + 1, high);
    }
}

int main() {
    vector<int> arr = {3,15,22,30,100,2,3,45,67,1};
{


    auto start = std::chrono::high_resolution_clock::now();

    int peak_index = linear_peak_finding(arr);

    auto end = std::chrono::high_resolution_clock::now();



    if (peak_index != -1) {
        cout << "Peak found at index (Linear Approach): " << peak_index << ", value: " << arr[peak_index] << endl;
    } else {
        cout << "No peak found." << endl;
    }
     std::chrono::duration<double> duration = end - start;

    std::cout << "Execution time: " << duration.count() << " seconds." << std::endl;

}
{


 auto start = std::chrono::high_resolution_clock::now();
    int peak_index2 = divide_and_conquer_peak_finding(arr, 0, arr.size() - 1);
     auto end = std::chrono::high_resolution_clock::now();


    if (peak_index2 != -1) {
        cout << "Peak found at index (Divide and Conquer Approach): " << peak_index2 << ", value: " << arr[peak_index2] << endl;
    } else {
        cout << "No peak found." << endl;
    }
 std::chrono::duration<double> duration = end - start;

    // Print the duration in seconds
    std::cout << "Execution time: " << duration.count() << " seconds." << std::endl;

    return 0;
}
}
