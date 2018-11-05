//
// Created by AckleyJia on 2018/11/5.
//

#include <iostream>
#include <unordered_set>
using namespace std;


class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> charSet;
        int res = 0;
        unsigned int i = 0, j = 0;

        while (j < s.length()){

            while (charSet.find(s[j]) != charSet.end()){
                charSet.erase(s[i]);
                i++;
            }
            charSet.insert(s[j]);
            j++;
            res = j - i > res ? j - i : res;
        }
        return res;
    }
};

int main(){
    cout <<"hello" << endl;
    Solution solution;
    cout << solution.lengthOfLongestSubstring("abcabcbb") << endl;
    cout << solution.lengthOfLongestSubstring("bbbbb") << endl;
    cout << solution.lengthOfLongestSubstring("pwwkew") << endl;
}