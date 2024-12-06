/*Kth Largest Element in an Array
Given an integer array nums and an integer k, return the kth largest element in the array.
Note that it is the kth largest element in the sorted order, not the kth distinct element.
Can you solve it without sorting?

Example 1:
Input: nums = [3,2,1,5,6,4], k = 2
Output: 5

Example 2:
Input: nums = [3,2,3,1,2,4,5,5,6], k = 4
Output: 4*/
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {

        //priority queue to store all element in descending order
        priority_queue<int> que;

        //iterating till the end of array
        for(int i=0;i<nums.size();i++){
            que.push(nums[i]);
        }
        int top;

        //iterating till the kth element is reach
        for(int i=0;i<k;i++){
            top=que.top();
            que.pop();
        }
        return top;
    }
};

int main() {
    Solution sol;

    // Input size of array
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    // Input array elements
    vector<int> nums(n);
    cout << "Enter the elements of the array: ";
    for(int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    // Input k for finding the kth largest element
    int k;
    cout << "Enter the value of k to find the kth largest element: ";
    cin >> k;

    int kthLargest = sol.findKthLargest(nums, k);
    cout << "The " << k << "th largest element is: " << kthLargest << endl;

    return 0;
}

/*
Kth Largest Element in an Array
1.so first we store each element in priority queue in descending order(max-heap)
2.then we pop the top element from the priority queue
3.we do till we reach kth iteration
*/