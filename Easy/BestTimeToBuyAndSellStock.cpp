#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0, tempProfit = 0;
        for (auto i = 0; i < prices.size()-1; i++)
        {
            for (auto j = i+1; j < prices.size(); j++)
            {
                tempProfit = prices[j] - prices[i];
                if(tempProfit > profit){
                    profit = tempProfit;
                }
                //If prices[j+1] < prices[j], skip it
                while(prices[j+1]<prices[j] && j < prices.size()) j++;
            }
            // If prices[i+1] > prices[i], skip it
            while(prices[i+1]>prices[i] && i < prices.size()-1) i++;
        }
        return profit;    
    }
};


int main() {
    Solution sol = Solution();
    vector<int> test1({7,1,5,3,6,4});
    vector<int> test2({7,6,4,3,1});
    cout << sol.maxProfit(test1) << endl;
    return 0;
}