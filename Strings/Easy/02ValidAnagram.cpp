/*Valid Anagram
Given two strings s and t, return true if t is an anagram of s, and false otherwise.

Example 1:
Input: s = "anagram", t = "nagaram"
Output: true

Example 2:
Input: s = "rat", t = "car"
Output: false
https://leetcode.com/problems/valid-anagram/description/*/
#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;
class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int> count;
        for(auto i:s){
            count[i]++;
        }

        for(auto i:t){
            count[i]--;
        }

        for(auto i:count){
            if(i.second!=0){
                return false;
            }
        }
        return true;
    }
};
int main() {
    Solution solution;
    string s1, s2;

    cout << "Enter the first string: ";
    cin >> s1;
    cout << "Enter the second string: ";
    cin >> s2;

    if (solution.isAnagram(s1, s2)) {
        cout << "The strings are anagrams of each other." << endl;
    } else {
        cout << "The strings are not anagrams of each other." << endl;
    }

    return 0;
}