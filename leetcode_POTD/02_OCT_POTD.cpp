#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        unordered_map<int, int> mp;
        vector<int> temp{arr.begin(), arr.end()};
        sort(temp.begin(), temp.end());
        int rank = 1;
        for (auto it : temp) {
            if (mp[it] == 0) {
                mp[it] = rank;
                rank++;
            }
        }
        for (int i = 0; i < arr.size(); i++) {
            arr[i] = mp[arr[i]];
        }
        return arr;
    }
};

int main() {
    Solution sol;
    vector<int> arr = {40, 10, 20, 30, 20, 10};
    
    vector<int> rankedArray = sol.arrayRankTransform(arr);

    cout << "Ranked Array: ";
    for (int i = 0; i < rankedArray.size(); i++) {
        cout << rankedArray[i] << " ";
    }
    cout << endl;

    return 0;
}
