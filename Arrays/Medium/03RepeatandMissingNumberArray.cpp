#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> repeatedNumber(const vector<int>& A) {
        int n = A.size();

        int xr = 0;
        for (int i = 0; i < n; i++) {
            xr = xr ^ A[i];
            xr = xr ^ (i + 1);
        }

        int number = (xr & ~(xr - 1));

        int zero = 0;
        int one = 0;
        for (int i = 0; i < n; i++) {
            if ((A[i] & number) != 0) {
                one = one ^ A[i];
            }
            else {
                zero = zero ^ A[i];
            }
        }

        for (int i = 1; i <= n; i++) {
            if ((i & number) != 0) {
                one = one ^ i;
            }
            else {
                zero = zero ^ i;
            }
        }

        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if (A[i] == zero) cnt++;
        }

        if (cnt == 2) return {zero, one};
        return {one, zero};
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
