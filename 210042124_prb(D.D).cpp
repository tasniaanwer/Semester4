


/*Tasnia Anower Medha
  ID-210042124
  problem:D.D

*/



#include <iostream>
#include <unordered_map>

using namespace std;

int main() {
    int T;
    cin >> T;

    while (T--) {
        int N;
        cin >> N;

        unordered_map<int, int> stoneCount;


        for (int i = 0; i < N; ++i) {
            int type;
            cin >> type;
            stoneCount[type]++;
        }


        int missingStoneType;
        for (auto it = stoneCount.begin(); it != stoneCount.end(); ++it) {
            if (it->second % 2 != 0) {
                missingStoneType = it->first;
                break;
            }
        }

        cout << missingStoneType << endl;
    }

    return 0;
}
