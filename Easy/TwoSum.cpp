#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> answer;
        int sum = -1;
        // Brute force solution, linear search
        for (auto i = 0; i < nums.size(); i++)
        {
            for (auto j = i+1; j < nums.size(); j++)
            {
                sum = nums[i] + nums[j];
                if(sum == target){
                    cout << "solution: " << i << " " << j << endl;
                    answer.push_back(i);
                    answer.push_back(j);
                }
            }
        }   
        return answer;
    }
};

int main(){
    cout << "Test" << endl;
    vector<int> nums1 = vector<int>({2, 7, 11, 15});
    int target1 = 9;
    vector<int> nums2 = vector<int>({3,2,4});
    int target2 = 6;
    Solution sol;
    vector<int> answer = sol.twoSum(nums2, target2);
    cout << answer[0] << " " << answer[1] << endl;
    return 0;
}