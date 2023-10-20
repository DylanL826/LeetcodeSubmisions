// Greedy algo solution:
/*
https://leetcode.com/problems/best-time-to-buy-and-sell-stock/solutions/39039/sharing-my-simple-and-clear-c-solution/
*/

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0, minPrice = pow(10,4)+1;
        for (auto i = 0; i < prices.size(); i++)
        {
            // Record lowest price up to i'th day
            if (prices[i] < minPrice)
                minPrice = prices[i];
            if(prices[i]-minPrice > profit){
                profit = prices[i] - minPrice;
            }
            
        }
        return profit;    
    }
};


int main() {
    Solution sol = Solution();
    vector<int> test1({7,1,5,3,6,4});
    vector<int> test2({7,6,4,3,1});
    cout << sol.maxProfit(test2) << endl;
    return 0;
}