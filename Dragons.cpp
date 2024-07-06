#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
    int initialStrength, numberOfDragons;
    cin >> initialStrength >> numberOfDragons;

    vector<pair<int, int>> dragons; // pairs of dragon's strength and bonus

    for (int i = 0; i < numberOfDragons; i++) {
        int strength, bonus;
        cin >> strength >> bonus;
        dragons.push_back({strength, bonus});
    }

    // Sort dragons based on their strength in ascending order
    sort(dragons.begin(), dragons.end());

    // Simulate fights with dragons
    for (int i = 0; i < numberOfDragons; i++) {
        if (initialStrength > dragons[i].first) {
            // Defeat the dragon and get the bonus
            initialStrength += dragons[i].second;
        } else {
            // If Kirito's strength is not enough, print "NO" and exit
            cout << "NO" << endl;
            return 0;
        }
    }

    // If all dragons are defeated, print "YES"
    cout << "YES" << endl;

    return 0;
}

