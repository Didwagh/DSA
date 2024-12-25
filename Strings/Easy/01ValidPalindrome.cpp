/*Valid Palindrome
A phrase is a palindrome if, after converting all uppercase letters into lowercase letters and removing all non-alphanumeric characters, it reads the same forward and backward. Alphanumeric characters include letters and numbers.
Given a string s, return true if it is a palindrome, or false otherwise.

Example 1:
Input: s = "A man, a plan, a canal: Panama"
Output: true
Explanation: "amanaplanacanalpanama" is a palindrome.

Example 2:
Input: s = "race a car"
Output: false
Explanation: "raceacar" is not a palindrome.

Example 3:
Input: s = " "
Output: true
Explanation: s is an empty string "" after removing non-alphanumeric characters.
Since an empty string reads the same forward and backward, it is a palindrome.
https://leetcode.com/problems/valid-palindrome/description/*/
#include <iostream>
#include <string>
#include <cctype>
using namespace std;
class Solution {
public:
    char lowercase(char ch){
        if(ch>='a' && ch<='z'){
            return ch;
        }else{
            ch=ch-'A'+'a';
            return ch;
        }
    }

    bool Valid(char ch){
        if((ch>='a' && ch <='z') || (ch>='A' && ch <='Z') || (ch>='0' && ch <='9')){
            return true;
        }
        return false;
    }

    bool isPalindrome(string s) {
        string temp="";
        for(int i=0;i<s.size();i++){
            char ch=s[i];
            if(Valid(ch)){
                temp.push_back(ch);
            }
        }
        int start=0;
        int end=temp.size()-1;
        while(start<=end){
            if(lowercase(temp[start])==lowercase(temp[end])){
                start++;
                end--;
            }else{
                return false;
            }
        }
        return true;
    }
};
int main() {
    Solution solution;
    string s;

    // Test case 1: Input a valid palindrome string
    s = "A man, a plan, a canal, Panama";
    if (solution.isPalindrome(s)) {
        cout << "\"" << s << "\" is a palindrome.\n";
    } else {
        cout << "\"" << s << "\" is not a palindrome.\n";
    }

    // Test case 2: Input a non-palindrome string
    s = "Hello, World!";
    if (solution.isPalindrome(s)) {
        cout << "\"" << s << "\" is a palindrome.\n";
    } else {
        cout << "\"" << s << "\" is not a palindrome.\n";
    }

    return 0;
}