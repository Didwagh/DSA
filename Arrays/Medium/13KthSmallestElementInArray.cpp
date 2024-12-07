#include <iostream>
#include <vector>
#include <queue> 

using namespace std;
class Solution {
  public:
    // arr : given array
    // k : find kth smallest element and return using this function
    int kthSmallest(vector<int> &arr, int k) {
        // code here
        priority_queue<int,vector<int>,greater<int>> pqmin;
        for(int i=0;i<arr.size();i++){
            pqmin.push(arr[i]);
        }
        int top;
        for(int i=0;i<k;i++){
            top=pqmin.top();
            pqmin.pop();
        }
        return top;
    }
};

int main() {
    Solution solution;

    // Example: Array and k value
    vector<int> arr = {7, 10, 4, 3, 20, 15};
    int k = 3;

    int result = solution.kthSmallest(arr, k);
    cout << k << "-th smallest element: " << result << endl;

    return 0;
}