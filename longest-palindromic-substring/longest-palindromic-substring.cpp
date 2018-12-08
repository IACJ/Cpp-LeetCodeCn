//
// Created by AckleyJia on 2018/12/7.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        if (s=="") {
            return "";
        }

        string ans;
        bool ** DPArr = new bool* [s.size()];
        for (int i = 0; i < s.size(); ++i) {
            DPArr[i] = new bool [s.size()] {0};
        }

        for (int k = 0; k < s.size(); ++k) {
            DPArr[k][k] = true;
            ans = s.substr(k,1);
        }

        bool * working = new bool [s.size()]{false};
        working[0] = true;
        for (int i = 1; i < s.size(); ++i) {

            for (int j = 0; j < s.size() - i; ++j) {
                if (s[j] == s[j + i]) {
                    if ((j + 1 > j + i - 1) || (DPArr[j + 1][j + i - 1])) {
                        DPArr[j][j + i] = true;
                        ans = s.substr(j, i+1);
                        working[i] = true;
                    }
                }
            }
            if (!working[i] && !working[i-1]){
                break;
            }
        }
//        for (int i = 0; i < s.size(); ++i) {
//            for (int j = 0; j < s.size(); ++j) {
//                cout << DPArr[i][j] << '\t';
//            }
//            cout << endl;
//        }
        return ans;
    }
};


int main() {
    cout << "test" <<endl;
    Solution solution;
    cout << solution.longestPalindrome("hello") << endl;
    cout << solution.longestPalindrome("babad") << endl;
    cout << solution.longestPalindrome("cbbd") << endl;
    cout << solution.longestPalindrome("") << endl;
}