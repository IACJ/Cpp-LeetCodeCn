//
// Created by AckleyJia on 2018/11/20.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        long m = nums1.size();
        long n = nums2.size();
        long min = 0;
        long max = nums1.size();
        long half = 0;
        long otherSide = 0;
        double ans = 0;

        while (max - min > 0) {
            half = (max + min) / 2;
            otherSide = (m+n) / 2 - half;

            if (otherSide > n) {
                min = half + 1;
                continue;
            }
            if (otherSide < 0) {
                max = half - 1;
                continue;
            }
            if ( (half > 0) && (otherSide < n) && (nums1[half - 1] > nums2[otherSide])){
                max = half - 1;
                continue;
            }
            if ( (otherSide > 0) && (half < m ) && (nums2[otherSide -1] > nums1[half])) {
                min = half + 1;
                continue;
            }
            cout << "fuck " << half << endl;
            break;
        }
        half = (max + min) / 2;
        otherSide = (m+n) / 2 - half;

        if ((n+m) % 2 == 1){
            if (half == m) {
                ans = nums2[otherSide];
            }
            else if (otherSide == n){
                ans = nums1[half];
            }
            else {
                ans =  (nums2[otherSide] < nums1[half]) ? nums2[otherSide] : nums1[half];
            }
        }
        else {
            long bigger = 0;
            long smaller = 0;

            if (half == m) {
                bigger = nums2[otherSide];
            }
            else if (otherSide == n){
                bigger = nums1[half];
            }
            else {
                bigger =  (nums2[otherSide] < nums1[half]) ? nums2[otherSide] : nums1[half];
            }

            if (half == 0) {
                smaller = nums2[otherSide -1];
            }
            else if (otherSide == 0){
                smaller = nums1[half -1];
            }
            else {
                smaller =  (nums2[otherSide-1] > nums1[half-1]) ? nums2[otherSide-1] : nums1[half-1];
            }

            ans = (double)(bigger + smaller) / 2;
        }
        return ans;
    }
};

int main() {
    Solution solution;

    vector<int> v1 ={1,3};
    vector<int> v2 ={2};
    cout << solution.findMedianSortedArrays(v1,v2)<< endl;

    vector<int> v3 ={1,2};
    vector<int> v4 ={3,4};
    cout << solution.findMedianSortedArrays(v3,v4)<< endl;

    vector<int> v5 ={};
    vector<int> v6 ={1,2,3,4};
    cout << solution.findMedianSortedArrays(v5,v6)<< endl;

    return 0;
}