/*Maximum and minimum of an array using minimum number of comparisons
Given an array of size N. The task is to find the maximum and the minimum element of the array using the minimum number of comparisons.

Examples:

Input: arr[] = {3, 5, 4, 1, 9}
Output: Minimum element is: 1
        Maximum element is: 9


Input: arr[] = {22, 14, 8, 17, 35, 3}
Output: Minimum element is: 3
        Maximum element is: 35*/
#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;
class Solution {
  public:
    pair<long long, long long> getMinMax(vector<long long int> arr) {

        //LLONG_MIN means the negative infinity
        long long maxi= LLONG_MIN;
        for(long long i=0;i<arr.size();i++){

            //check if current element is greater then stored maximun
            if(arr[i]>maxi){

                //then change to the current element
                maxi=arr[i];
            }
        }

        //LLONG_MAX means the positive infinity
        long long mini=LLONG_MAX;
        for(long long i=0;i<arr.size();i++){

            //check if current element is smaller then stored maximun
            if(arr[i]<mini){

                //then change to the current element
                mini=arr[i];
            }
        }

        //store in pair format
        pair<long long,long long> ans;
        ans.first=mini;
        ans.second=maxi;
        return ans;
    }
};
int main() {
    Solution sol;
    
    // Input size of array
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    // Input array elements
    vector<long long> arr(n);
    cout << "Enter the elements of the array: ";
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Get minimum and maximum
    pair<long long, long long> result = sol.getMinMax(arr);

    // Output the result
    cout << "Minimum element: " << result.first << endl;
    cout << "Maximum element: " << result.second << endl;

    return 0;
}

/*
(1)For finding Maximum
1.we would store the minimum value possible so it can check even for negative value
2.then we iterate through the array
3.whenever we find any maximum value then the stored value we replace it

(2)For finding Minimum
1.we would store the maximum value possible so it can check even for biggest value
2.then we iterate through the array
3.whenever we find any mainimum value then the stored value we replace it
*/ 