/*Search in Rotated Sorted Array
There is an integer array nums sorted in ascending order (with distinct values).
Prior to being passed to your function, nums is possibly rotated at an unknown pivot index k (1 <= k < nums.length) such that the resulting array is [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed). For example, [0,1,2,4,5,6,7] might be rotated at pivot index 3 and become [4,5,6,7,0,1,2].
Given the array nums after the possible rotation and an integer target, return the index of target if it is in nums, or -1 if it is not in nums.
You must write an algorithm with O(log n) runtime complexity.

Example 1:
Input: nums = [4,5,6,7,0,1,2], target = 0
Output: 4

Example 2:
Input: nums = [4,5,6,7,0,1,2], target = 3
Output: -1

Example 3:
Input: nums = [1], target = 0
Output: -1*/
#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
    int search(vector<int>& nums, int target) {

        //left pointer
        int left=0;

        //right pointer
        int right=nums.size()-1;
        while(left<=right){

            //finding the middle pointer
            int mid=left+((right-left)/2);

            //check if middle pointer is at the targeted value
            if(nums[mid]==target){
                return mid;    
            }

            //check whether the middle value is greater than the left pointer (meaning we would check in larger subarray)
            else if(nums[mid]>=nums[left]){

                //check whether the the target value is in range of larger subarray
                if(nums[left]<=target && nums[mid]>=target){
                    right=mid-1;
                }else{ //if not than means either the value is greater than the range or smaller
                    left=mid+1;
                }
            }

            //now we know that the middle value is smaller than the left pointer (meaning we are now check in smaller sub array)
            else{

                //now check whether the targeted value is in the smaller subarray
                if(nums[mid]<=target && nums[right]>=target){
                    left=mid+1;
                }else{ //if not this means it is in larger subarray
                    right=mid-1;
                }
            }
        }

        //we couldn't find the value
        return -1;
    }
};
int main() {
    Solution solution;

    // Example: Rotated sorted array and target value
    vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
    int target = 0;

    int result = solution.search(nums, target);
    cout << "Index of target " << target << ": " << result << endl;

    return 0;
}

/*Search in Rotated Sorted Array
1.as we know that it is sorted array but rotated in kth index
2.so we used binary search to find but being the kth rotated we need to use it twice
3.so lets consider their are 2 subarray
    i.one is larger from the rotated point to maximum
    ii.second the smaller from minimum to rest
Eg: [4 5 6 7 0 1 2]
    here the larger array is [4 5 6 7] and smaller array is [0 1 2]
4.now we use to check using binary search
5.if the middle value is target return mid
6.now we check whether the targeted value lies the range of the started and mid
    i.if it lies within it move the end pointer to this range
    ii.if not move to start pointer to the left of mid
7.we check whether the target value lies in smaller array
    i.if it lies in the range of smaller array then move the start to the smaller array
    ii.if not (means it does not lies in that range) move the end pointer above the smaller range
    */