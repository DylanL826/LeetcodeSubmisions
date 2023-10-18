#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> answer;
        // Sort nums
        sort(nums.begin(), nums.end());
        int sum = 0;
        int j = 0, k = nums.size()-1;
        // Use set for duplicate detection w/ insert method.
        set<vector<int>> answerSet; 
        for (auto i = 0; i < nums.size()-1; i++){
                j = i + 1;
                k = nums.size()-1;
            while(j < k){
                sum = nums[i] + nums[j] + nums[k];
                if(sum < 0){
                    j++;
                }
                else if(sum > 0){
                    k--;
                }
                else{
                    answerSet.insert({nums[i], nums[j], nums[k]});
                    j++;
                    k--;
                }
            }
        }
        // Transfer set data to vector
        for (auto triplet : answerSet)
        {
            answer.push_back(triplet);
        }
        return answer;
    }
};


int main(){
    Solution sol;

    vector<int> nums1 = vector<int>({-1, 0, 1, 2, -1, -4});
    vector<int> nums2 = vector<int>({1, 0, 1});
    vector<int> nums3 = vector<int>({0, 0, 0});
    vector<int> nums4 = vector<int>({0, 0, 0, 0});
    //[[-4,0,4],[-4,1,3],[-3,-1,4],[-3,0,3],[-3,1,2],[-2,-1,3],[-2,0,2],[-1,-1,2],[-1,0,1]]
    vector<int> nums5 = vector<int>({-1, 0, 1, 2, -1, -4, -2, -3, 3, 0, 4});
    vector<vector<int>> answer = sol.threeSum(nums5);
    for (auto i = 0; i < answer.size(); i++)
    {
        cout << answer[i][0] << " " <<  answer[i][1]<< " " <<  answer[i][2] << endl;
    }
    // set<vector<int>> s1;
    // s1.insert({1,2,2});
    // s1.insert({1,2,2});
    // cout << s1.size() << endl;
    //cout << answer[0][0] << " " <<  answer[0][1]<< " " <<  answer[0][2] << endl;
    return 0;
}