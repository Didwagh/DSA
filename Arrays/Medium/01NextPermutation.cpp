#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int index=-1;
        for(int i=nums.size()-2;i>=0;i--){
            if(nums[i]<nums[i+1]){
                index=i;
                break;
            }
        }
        if(index==-1){
            reverse(nums.begin(),nums.end());
            return;
        }
        for(int i=nums.size()-1;i>index;i--){
            if(nums[i]>nums[index]){
                swap(nums[i],nums[index]);
                break;
            }
        }
        reverse(nums.begin()+index+1,nums.end());
        return;
    }
};

int main() {
    Solution solution;

    // Example: Input array for next permutation
    vector<int> nums = {1, 2, 3};

    cout << "Original permutation: ";
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;

    solution.nextPermutation(nums);

    cout << "Next permutation: ";
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}