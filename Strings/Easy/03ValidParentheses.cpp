/*Valid Parentheses
Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
An input string is valid if:
    1.Open brackets must be closed by the same type of brackets.
    2.Open brackets must be closed in the correct order.
    3.Every close bracket has a corresponding open bracket of the same type.
Example 1:
Input: s = "()"
Output: true

Example 2:
Input: s = "()[]{}"
Output: true

Example 3:
Input: s = "(]"
Output: false

Example 4:
Input: s = "([])"
Output: true
https://leetcode.com/problems/valid-parentheses/description/*/
#include <iostream>
#include <stack>
#include <string>

using namespace std;
class Solution {
public:
    bool isValid(string& s) {
        stack<char> stk;
        for(auto i:s){
            if(i == ')' || i == ']' || i == '}'){
                if(stk.empty()){
                    return false;
                }
                char top=stk.top();
                if ((i == ')' && top == '(') ||(i == ']' && top == '[') || (i == '}' && top == '{')) {
                    stk.pop(); 
                }else{
                    return false;
                }
            }else{
                stk.push(i);
            }
        }
        if(!stk.empty()){
            return false;
        }else{
            return true;
        }
    }
};
int main() {
    Solution solution;
    string input;

    cout << "Enter a string of brackets: ";
    cin >> input;

    if (solution.isValid(input)) {
        cout << "The string has valid parentheses/brackets." << endl;
    } else {
        cout << "The string has invalid parentheses/brackets." << endl;
    }

    return 0;
}