/*Chocolate Distribution Problem
Given an array arr[] of positive integers, where each value represents the number of chocolates in a packet. Each packet can have a variable number of chocolates. There are m students, the task is to distribute chocolate packets among m students such that -
    i. Each student gets exactly one packet.
    ii. The difference between maximum number of chocolates given to a student and minimum number of chocolates given to a student is minimum and return that minimum possible difference.
Examples:

Input: arr = [3, 4, 1, 9, 56, 7, 9, 12], m = 5
Output: 6
Explanation: The minimum difference between maximum chocolates and minimum chocolates is 9 - 3 = 6 by choosing following m packets :[3, 4, 9, 7, 9].
Input: arr = [7, 3, 2, 4, 9, 12, 56], m = 3
Output: 2
Explanation: The minimum difference between maximum chocolates and minimum chocolates is 4 - 2 = 2 by choosing following m packets :[3, 2, 4].
Input: arr = [3, 4, 1, 9, 56], m = 5
Output: 55
Explanation: With 5 packets for 5 students, each student will receive one packet, so the difference is 56 - 1 = 55.*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;
class Solution {
  public:
    int findMinDiff(vector<int>& a, int m) {
        // code here

        //sort the array
        sort(a.begin(),a.end());
        int miniDiff=INT_MAX;

        //window iteration
        for(int i=0;i<=a.size()-m;i++){

            //find the difference between the last(maximum) and first(minimum) of the window
            int diff=a[i+m-1]-a[i];

            //check the minimum difference
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

/*Chocolate Distribution Problem
"i. Each student gets exactly one packet."
from this statement we can understand that we need to use window(smaller array)

" ii. The difference between maximum number of chocolates given to a student and minimum number of chocolates given to a student is minimum and return that minimum possible difference."
from this we can understand that we need to find the difference between the minimum and maximum of that window 
the difference should be minimum

1.we will sort the array
2.we will use a sliding window to iterate
3.from the window we find the difference of the minimum and maximum value
4.then we will find the minimum difference using 'min()'
*/