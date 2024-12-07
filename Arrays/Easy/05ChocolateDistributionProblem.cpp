#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;
class Solution {
  public:
    int findMinDiff(vector<int>& a, int m) {
        // code here
        sort(a.begin(),a.end());
        int miniDiff=INT_MAX;
        for(int i=0;i<=a.size()-m;i++){
            int diff=a[i+m-1]-a[i];
            miniDiff=min(diff,miniDiff);
        }
        return miniDiff;
    }
};
int main() {
    Solution solution;

    // Example: Chocolate Distribution Problem
    vector<int> arr = {12, 4, 7, 9, 2, 23, 25, 41, 30, 40, 28, 42, 30, 44, 48, 43, 50};
    int m = 7;

    int result = solution.findMinDiff(arr, m);
    cout << "Minimum difference: " << result << endl;

    return 0;
}