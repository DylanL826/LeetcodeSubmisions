//https://leetcode.com/problems/minimum-size-subarray-sum/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int minLength = nums.size(), curLength = 1, start = 0, end = 0, curSum = nums[start];
        // Slidg 
        while(end < nums.size()-1){
            if(curSum < target){ // if under target, add end number.
                curSum += nums[++end];
                curLength++;
            } else { // if at least target, record length then remove start number
                minLength = min(minLength, curLength);
                // Avoid start pointer from crossing end in single element subarray case.
                if(minLength == 1){
                    return 1;
                }
                curSum -= nums[start++];
                curLength--;
            }
        }
        return minLength;
    }
};

int main(){

    Solution sol;
    int t1 = 7;
    vector<int> nums1{2, 2, 1, 2, 4, 3};

    cout << sol.minSubArrayLen(t1, nums1);
    return 0;
}