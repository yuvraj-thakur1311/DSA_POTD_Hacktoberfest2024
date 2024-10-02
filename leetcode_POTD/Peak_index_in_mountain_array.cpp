#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int left = 0, right = arr.size() - 1;
        while(left <= right) {
            int mid = (left + right) / 2;
            if(arr[mid] > arr[mid-1] && arr[mid] > arr[mid+1]) return mid;
            else {
                if(arr[mid] < arr[mid+1]) left = mid + 1; 
                else if(arr[mid] < arr[mid-1]) right = mid - 1;  
            }
        }
        return left;
    }
};

int main() {
    Solution solution;
    vector<int> mountainArray = {0, 2, 5, 3, 1};  
    int peakIndex = solution.peakIndexInMountainArray(mountainArray);
    cout << "Peak index: " << peakIndex << endl;
    return 0;
}
