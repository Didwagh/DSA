/*Convert a sentence into its equivalent mobile numeric keypad sequence
Given a sentence in the form of a string in uppercase, convert it into its equivalent mobile numeric keypad sequence. Please note there might be spaces in between the words in a sentence and we can print spaces by pressing 0.
Example 1:

Input:
S = "GFG"
Output: 43334
Explanation: For 'G' press '4' one time.
For 'F' press '3' three times.
Example 2:

Input:
S = "HEY U"
Output: 4433999088
Explanation: For 'H' press '4' two times.
For 'E' press '3' two times. For 'Y' press '9' 
three times. For white space press '0' one time.
For 'U' press '8' two times.
https://www.geeksforgeeks.org/problems/convert-a-sentence-into-its-equivalent-mobile-numeric-keypad-sequence0547/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=practice_card*/
#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;
string printSequence(string S)
{
    //code here.
    unordered_map<char,string> keypad={
        {'A',"2"},{'B',"22"},{'C',"222"},
        {'D',"3"},{'E',"33"},{'F',"333"},
        {'G',"4"},{'H',"44"},{'I',"444"},
        {'J',"5"},{'K',"55"},{'L',"555"},
        {'M',"6"},{'N',"66"},{'O',"666"},
        {'P',"7"},{'Q',"77"},{'R',"777"},{'S',"7777"},
        {'T',"8"},{'U',"88"},{'V',"888"},
        {'W',"9"},{'X',"99"},{'Y',"999"},{'Z',"9999"},
        {' ',"0"}
    };
    
    string ans="";
    for(char c:S){
        ans+=keypad[c];
    }
    return ans;
}
int main() {
    string input;

    cout << "Enter a string: ";
    getline(cin, input);

    string result = printSequence(input);

    cout << "T9 Keypad Sequence: " << result << endl;

    return 0;
}