/*Common in 3 Sorted Arrays
You are given three arrays sorted in increasing order. Find the elements that are common in all three arrays.
If there are no such elements return an empty array. In this case, the output will be -1.

Note: can you handle the duplicates without using any additional Data Structure?
Examples :

Input: arr1 = [1, 5, 10, 20, 40, 80] , arr2 = [6, 7, 20, 80, 100] , arr3 = [3, 4, 15, 20, 30, 70, 80, 120]
Output: [20, 80]
Explanation: 20 and 80 are the only common elements in arr, brr and crr.

Input: arr1 = [1, 2, 3, 4, 5] , arr2 = [6, 7] , arr3 = [8,9,10]
Output: [-1]
Explanation: There are no common elements in arr, brr and crr.

Input: arr1 = [1, 1, 1, 2, 2, 2], B = [1, 1, 2, 2, 2], arr3 = [1, 1, 1, 1, 2, 2, 2, 2]
Output: [1, 2]
Explanation: We do not need to consider duplicates
https://www.geeksforgeeks.org/problems/common-elements1132/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=practice_card*/
#include <iostream>
#include <vector>

using namespace std;
class Solution {
  public:
    // Function to find common elements in three arrays.
    vector<int> commonElements(vector<int> &arr1, vector<int> &arr2,
                               vector<int> &arr3) {
        // Code Here
        int i=0;
        int j=0;
        int k=0;
        vector<int> ans;
        while(i<arr1.size() && j<arr2.size() && k<arr3.size()){
            if(arr1[i]==arr2[j] && arr2[j]==arr3[k]){
                ans.push_back(arr1[i]);
                while(i+1<arr1.size() && arr1[i]==arr1[i+1]){
                    i++;
                }
                while(j+1<arr2.size() && arr2[j]==arr2[j+1]){
                    j++;
                }
                while(k+1<arr3.size() && arr3[k]==arr3[k+1]){
                    k++;
                }
                i++;
                j++;
                k++;
            }else if(arr1[i]<arr2[j]){
                i++;
            }else if(arr2[j]<arr3[k]){
                j++;
            }else{
                k++;
            }
        }
        return ans;
    }
};
int main() {
    Solution solution;

    int n1, n2, n3;
    cout << "Enter the size of the first array: ";
    cin >> n1;
    vector<int> arr1(n1);
    cout << "Enter elements of the first array: ";
    for (int i = 0; i < n1; i++) {
        cin >> arr1[i];
    }

    cout << "Enter the size of the second array: ";
    cin >> n2;
    vector<int> arr2(n2);
    cout << "Enter elements of the second array: ";
    for (int i = 0; i < n2; i++) {
        cin >> arr2[i];
    }

    cout << "Enter the size of the third array: ";
    cin >> n3;
    vector<int> arr3(n3);
    cout << "Enter elements of the third array: ";
    for (int i = 0; i < n3; i++) {
        cin >> arr3[i];
    }

    vector<int> result = solution.commonElements(arr1, arr2, arr3);

    cout << "Common elements in the three arrays: ";
    if (result.empty()) {
        cout << "No common elements" << endl;
    } else {
        for (int elem : result) {
            cout << elem << " ";
        }
        cout << endl;
    }

    return 0;
}