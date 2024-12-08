/*Repeat and Missing Number Array
You are given a read only array of n integers from 1 to n.
Each integer appears exactly once except A which appears twice and B which is missing.
Return A and B.

Note: Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?
Note that in your output A should precede B.

Example:

Input:[3 1 2 5 3] 
Output:[3, 4] 
A = 3, B = 4*/
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> repeatedNumber(const vector<int>& A) {
        int n = A.size();

        int xr = 0;
        //first we find the xor of the array with (1-n) 
        //from this we can get relation of the missing and repeated value
        for (int i = 0; i < n; i++) {
            xr = xr ^ A[i];
            xr = xr ^ (i + 1);
        }

        //now we find the bit place from the answer which would differentiate them
        int bitNumber=0;
        while(1){

            //'&' we return 1 only when there is presence of 1 in xor
            if((xr & (1<<bitNumber))!=0){
                break;
            }
            bitNumber++;
        }

        //now we group them according to 0 and 1
        int zero = 0;
        int one = 0;
        for (int i = 0; i < n; i++) {

            //if the value from array '&' bitnumber return 1 means the differentiate place is 1 and we make them enter the onegroup and then xor them
            if ((A[i] & (1<<bitNumber))!= 0) {
                one = one ^ A[i];
            }
            else { //if not then zerogroup then xor them
                zero = zero ^ A[i];
            }
        }

        //now we group the (1-n) array
        for (int i = 1; i <= n; i++) {

            if ((i & (1<<bitNumber)) != 0) {
                one = one ^ i;
            }
            else {
                zero = zero ^ i;
            }
        }

        //now we have to identify the numbers
        int count = 0;
        for (int i = 0; i < n; i++) {

            //if the number found is from the zero group then increase the counter and it should be always 2 or 0(as they are repeating or missing)
            if (A[i] == zero){
                count++;
            }
        }
        //if 2 meaning it repeating lies in the zero group and mmissing lies in the one group
        if (count == 2){ 
            return {zero, one};
        }else{
            return {one, zero};
        }
    }
};

int main() {
    Solution solution;

    vector<int> A = {3, 1, 2, 5, 3};

    vector<int> result = solution.repeatedNumber(A);

    cout << "Repeated number: " << result[0] << endl;
    cout << "Missing number: " << result[1] << endl;

    return 0;
}
/*Repeat and Missing Number Array
Using XOR,
1.we would XOR the array with the range(1-n)
2.as we know the XOR with the same value will return 0 and XOR with 0 will return the same number
3.so from this we can get the XORed value of the missing and the repeated value
4.after this we would find the differentiate bit(as it is of form 0&1 so there would be 1 bit that distinguish both the number)
5.to find that we will iterate from right side using 1 and left shift to till we find 
6.we will also keep counter to keep its track
7.after getting the position we will now distinguish them into 2 group(zero and one)
8.this is done by using '&' operator 
9.we will do this for array as well as (1-n)
[the differentiate bit will always ditinguish the two numbers in different group]
10.now we will perform XOR on both group each
11.so the only thing left in both group will be the two numbers
12.so to find which one is missing or repeated
13.we will use a loop that goes through the array
14.it will check with zero group value and make the increase the counter
15.if the counter is 2 then the repeated number lies in the zero group 
    and if it does not then it lies in one group
https://www.youtube.com/watch?v=2D0D8HE6uak
*/
