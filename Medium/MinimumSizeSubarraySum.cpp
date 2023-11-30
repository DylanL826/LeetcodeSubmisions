//https://leetcode.com/problems/minimum-size-subarray-sum/

#include <iostream>
#include <vector>

using namespace std;

/*
    TODO: clean up logic
    1.) Remove end < nums.size()-1, used to compensate 
    2.) Remove break statement
*/ 
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int minLength = nums.size()+1, curLength = 1, start = 0, curSum = 0;
        // Sliding windows approach
        for(int end =0; end < nums.size(); end++){
            if(curSum < target){ // if under target, add end number.
                curSum += nums[end];
                curLength++;
            }
            /* if at or above target, record length and remove start 
                ...numbers until back under target or at single element. */
            while(curSum >= target){
                minLength = min(minLength, curLength);
                // End early condition.
                if(minLength == 1){
                    return 1;
                }
                curSum -= nums[start++];
                curLength--;
            }
        }
        // If using all elements doesn't meet target, return 0.
        if(minLength == nums.size()+1){
            return 0;
        }
        return minLength;
    }
};

int main(){

    Solution sol;
    int t1 = 7;
    vector<int> nums1{2, 2, 1, 2, 4, 3};
    int t2 = 4;
    vector<int> nums2{1, 4, 4};
    int t3 = 11;
    vector<int> nums3{1,1,1,1,1,1,1,1};
    int t4 = 15;
    vector<int> nums4{1,2,3,4,5};
    int t5 = 7;
    vector<int> nums5{8};

    cout << sol.minSubArrayLen(t1, nums1) << endl;
    cout << sol.minSubArrayLen(t2, nums2) << endl;
    cout << sol.minSubArrayLen(t3, nums3) << endl;
    cout << sol.minSubArrayLen(t4, nums4) << endl;
    cout << sol.minSubArrayLen(t5, nums5) << endl;
    return 0;
}