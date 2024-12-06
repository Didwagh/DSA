/*Array Reverse
Given an array arr[], the task is to reverse the array. Reversing an array means rearranging the elements such that the first element becomes the last, the second element becomes second last and so on.

Examples:

Input: arr[] = {1, 4, 3, 2, 6, 5}  
Output: {5, 6, 2, 3, 4, 1}
Explanation: The first element 1 moves to last position, the second element 4 moves to second-last and so on.


Input: arr[] = {4, 5, 1, 2} 
Output: {2, 1, 5, 4}
Explanation: The first element 4 moves to last position, the second element 5 moves to second last and so on.*/
#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;
class Solution {
  public:
    void reverseArray(vector<int> &arr) {
        // code here

        //iterate to half size
        for(int i=0;i<arr.size()/2;i++){

            //swap with the same i from both side
            swap(arr[i],arr[arr.size()-i-1]);
        }
    }
};

int main() {
    Solution sol;

    // Input size of array
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    // Input array elements
    vector<int> arr(n);
    cout << "Enter the elements of the array: ";
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Reverse the array
    sol.reverseArray(arr);

    // Output the reversed array
    cout << "Reversed array: ";
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}

/*
For reversing an array
1.start a pointer at 0 and iterate till size/2
2.also while iterating swap the ith element with left by using(n-i-1)
3.for even cases size/2 would be perfect
4.for odd cases size/2 takes the less whole number so the center number will always remain at same place
*/