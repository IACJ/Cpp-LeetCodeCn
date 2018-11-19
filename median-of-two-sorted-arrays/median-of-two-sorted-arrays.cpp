//
// Created by AckleyJia on 2018/11/19.
//
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        long l1 = 0, l2 = 0, r1 = nums1.size()-1, r2 = nums2.size()-1;

        while ((r1 - l1 + 1) + (r2 - l2 + 1) > 2){
            if (r1 - l1 + 1 == 0) {
                l2++;
            }
            else if( (r2 - l2 + 1 == 0) || ( nums1[l1] < nums2[l2])){
                l1++;
            }
            else {
                l2 ++;
            }


            if (r1 - l1 + 1 == 0){
                r2--;
            }
            else if (  (r2 - l2 + 1 == 0) || ( nums1[r1] > nums2[r2])) {
                r1--;
            }
            else{
                r2--;
            }
        }

        if (r1 - l1 + 1 == 0) {
            return (double)(nums2[l2] + nums2[r2]) / 2;
        }
        else if (r2 - l2 + 1 == 0) {
            return (double)(nums1[l1] + nums1[r1]) / 2;
        }
        else {
            return (double)(nums1[l1] + nums2[l2]) / 2;
        }
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
