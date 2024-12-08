/*
Given an array arr[] and an integer k where k is smaller than the size of the array, the task is to find the kth smallest element in the given array.

Follow up: Don't solve it using the inbuilt sort function.
Examples :

Input: arr[] = [7, 10, 4, 3, 20, 15], k = 3
Output:  7
Explanation: 3rd smallest element in the given array is 7.

Input: arr[] = [2, 3, 1, 20, 15], k = 4 
Output: 15
Explanation: 4th smallest element in the given array is 15.*/
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

        //int(the type of data) vector<int>(the way to store data) greater<int>(greater value we move down ie ascending order)
        priority_queue<int,vector<int>,greater<int>> pqmin;

        //iterating till the end of array
        for(int i=0;i<arr.size();i++){
            pqmin.push(arr[i]);
        }
        int top;

        //iterating till the kth element is reach
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

/*
Kth Smallest Element in an Array
1.so first we store each element in priority queue in ascending order(min-heap)
2.then we pop the top element from the priority queue
3.we do till we reach kth iteration
*/