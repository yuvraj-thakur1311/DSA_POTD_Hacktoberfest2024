/*

Question link "https://leetcode.com/problems/rank-transform-of-an-array/"

*/ 

#include <bits/stdc++.h>
#include <cassert>  // Include for assertions

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

// Function to check if two vectors are equal
bool areVectorsEqual(const vector<int>& v1, const vector<int>& v2) {
    return v1 == v2;
}

void runTestCases() {
    Solution sol;
    
    // Test case 1: Basic test case with typical inputs
    vector<int> arr1 = {40, 10, 20, 30, 20, 10};
    vector<int> expected1 = {4, 1, 2, 3, 2, 1};
    vector<int> res1 = sol.arrayRankTransform(arr1);
    assert(areVectorsEqual(res1, expected1));  // Assertion for test case 1
    
    // Test case 2: Already sorted input
    vector<int> arr2 = {1, 2, 3, 4, 5};
    vector<int> expected2 = {1, 2, 3, 4, 5};
    vector<int> res2 = sol.arrayRankTransform(arr2);
    assert(areVectorsEqual(res2, expected2));  // Assertion for test case 2
    
    // Test case 3: Reverse sorted input
    vector<int> arr3 = {100, 90, 80, 70};
    vector<int> expected3 = {4, 3, 2, 1};
    vector<int> res3 = sol.arrayRankTransform(arr3);
    assert(areVectorsEqual(res3, expected3));  // Assertion for test case 3
    
    // Test case 4: All identical elements
    vector<int> arr4 = {5, 5, 5, 5};
    vector<int> expected4 = {1, 1, 1, 1};
    vector<int> res4 = sol.arrayRankTransform(arr4);
    assert(areVectorsEqual(res4, expected4));  // Assertion for test case 4
    
    // Test case 5: Negative and positive values
    vector<int> arr5 = {-10, 0, 10};
    vector<int> expected5 = {1, 2, 3};
    vector<int> res5 = sol.arrayRankTransform(arr5);
    assert(areVectorsEqual(res5, expected5));  // Assertion for test case 5
    
    // Test case 6: Minimum and maximum values
    vector<int> arr6 = {-1e9, 0, 1e9};
    vector<int> expected6 = {1, 2, 3};
    vector<int> res6 = sol.arrayRankTransform(arr6);
    assert(areVectorsEqual(res6, expected6));  // Assertion for test case 6
    
    // Test case 7: Empty input
    vector<int> arr7 = {};
    vector<int> expected7 = {};
    vector<int> res7 = sol.arrayRankTransform(arr7);
    assert(areVectorsEqual(res7, expected7));  // Assertion for test case 7
    
    // Test case 8: Single element array
    vector<int> arr8 = {42};
    vector<int> expected8 = {1};
    vector<int> res8 = sol.arrayRankTransform(arr8);
    assert(areVectorsEqual(res8, expected8));  // Assertion for test case 8
    
    // Test case 9: Performance test (large input, all same values)
    vector<int> arr9(1e5, 1);  // 100000 elements all set to 1
    vector<int> expected9(1e5, 1);  // All ranks should be 1
    vector<int> res9 = sol.arrayRankTransform(arr9);
    assert(areVectorsEqual(res9, expected9));  // Assertion for test case 9
    
    // Test case 10: Large input with distinct elements
    vector<int> arr10(1e5);
    iota(arr10.begin(), arr10.end(), -5e4);  // Generates numbers from -50000 to 49999
    vector<int> expected10(1e5);
    iota(expected10.begin(), expected10.end(), 1);  // Expected rank 1 to 100000
    vector<int> res10 = sol.arrayRankTransform(arr10);
    assert(areVectorsEqual(res10, expected10));  // Assertion for test case 10
    
    // Test case 11: Random values
    vector<int> arr11 = {-10, 50, 0, 50, -10};
    vector<int> expected11 = {1, 3, 2, 3, 1};
    vector<int> res11 = sol.arrayRankTransform(arr11);
    assert(areVectorsEqual(res11, expected11));  // Assertion for test case 11

    cout << "All test cases passed!" << endl;
}

int main() {
    runTestCases();  // Run all test cases with assertions
    return 0;
}
