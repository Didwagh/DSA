/*Remove Consecutive Characters
You are given a string s, consisting of lowercase alphabets. Your task is to remove consecutive duplicate characters from the string. 
Example:

Input: s = "aabb"
Output:  "ab" 
Explanation: 
The character 'a' at index 2 is the same as 'a' at index 1, so it is removed.
Similarly, the character 'b' at index 4 is the same as 'b' at index 3, so it is removed.
The final string is "ab".

Input:s = "aabaa"
Output: "aba"
Explanation: 
The character 'a' at index 2 is the same as 'a' at index 1, so it is removed.
The character 'a' at index 5 is the same as 'a' at index 4, so it is removed.
The final string is "aba".

Input: s = "abcddcba"
Output: "abcdcba"
Explanation: 
The character 'd' at index 5 is the same as 'd' at index 4, so it is removed.
No other consecutive duplicates exist.
The final string is "abcdcba".
https://www.geeksforgeeks.org/problems/consecutive-elements2306/1*/
#include <iostream>
#include <string>

using namespace std;
class Solution {
  public:
    string removeConsecutiveCharacter(string& s) {
        // code here.
        string ans;
        for(int i=0;i<s.size();i++){
            if(s[i]!=s[i+1]){
                ans.push_back(s[i]);
            }
        }
        return ans;
    }
};
int main() {
    Solution solution;
    string input;

    cout << "Enter a string: ";
    cin >> input;

    string result = solution.removeConsecutiveCharacter(input);

    cout << "String after removing consecutive duplicate characters: " << result << endl;

    return 0;
}