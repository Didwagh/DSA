/*
Given an integer array nums, return true if any value appears at least twice in the array, and return false if every element is distinct.

Example 1:
Input: nums = [1,2,3,1]
Output: true
Explanation: The element 1 occurs at the indices 0 and 3.

Example 2:
Input: nums = [1,2,3,4]
Output: false
Explanation: All elements are distinct.

Example 3:
Input: nums = [1,1,1,3,3,4,3,2,4,2]
Output: true*/
#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {

        //unordered set to store the values
        unordered_set<int> duplicates;

        //iterating through the whole array
        for(int num:nums){

            //check the element till last of set
            if(duplicates.find(num)!=duplicates.end()){

                //if found return true
                return true;
            }else{

                //else insert in set
                duplicates.insert(num);
            }
        }

        //if no element is found duplicate
        return false;
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

    // Check for duplicates
    bool result = sol.containsDuplicate(nums);

    // Output the result
    if(result) {
        cout << "The array contains duplicates." << endl;
    } else {
        cout << "The array does not contain duplicates." << endl;
    }

    return 0;
}

/*
To check whether duplicates are present or not
1.we make use of unordered set
2.we store the value from array
3.we also check whether the element is present or not in set
4.if present return true
5.if not push the element in set
*/