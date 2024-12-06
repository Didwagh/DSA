/*Maximum Subarray
Given an integer array nums, find the subarray with the largest sum, and return its sum.
Example 1:

Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
Output: 6
Explanation: The subarray [4,-1,2,1] has the largest sum 6.
Example 2:

Input: nums = [1]
Output: 1
Explanation: The subarray [1] has the largest sum 1.
Example 3:

Input: nums = [5,4,-1,7,8]
Output: 23
Explanation: The subarray [5,4,-1,7,8] has the largest sum 23.*/
#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum=0;
        int maxi=INT_MIN;

        //iterate the complete array
        for(int i=0;i<nums.size();i++){

            //add the element in sum
            sum=sum+nums[i];

            //find maximum of stored maxsum and sum
            maxi=max(maxi,sum);

            //if sum every becomes negative always return 0 for it to avoid negative
            if(sum<0){
                sum=0;
            }
        }
        return maxi;
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

    // Find the maximum subarray sum
    int result = sol.maxSubArray(nums);

    // Output the result
    cout << "Maximum subarray sum: " << result << endl;

    return 0;
}

/*
Maximum SubArray
1.we store the negative infinty in the maxi
2.we iterate through the array
3.we add the sum
4.then we check whether its maximum or not(becoz of negative number)
5.we return 0 if the sum goes below 0
*/