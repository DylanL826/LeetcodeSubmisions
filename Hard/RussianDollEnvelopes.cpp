//https://leetcode.com/problems/russian-doll-envelopes/description/LIS/
// Only Solution class definition is submitted to leetcode.
#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;



class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        // Get largest x & y dimensions across all the envelopes.
        int maxX, maxY = 0;
        for (auto i = 0; i < envelopes.size(); i++){
            if(envelopes[i][0] > maxX){
                maxX = envelopes[i][0];
            }
            if(envelopes[i][1] > maxY){
                maxY = envelopes[i][1];
            }
        }
        
        // Declare exists matrix 
        int** exists = new int*[maxX];
        for (auto i = 0; i < maxX; i++)
        {
            exists[i] = new int[maxY]{0};
        }
        // Assign 1 to (x,y) dimensions corresponding to envelope in envelopes.
        for (auto i = 0; i < envelopes.size(); i++)
        {
            exists[envelopes[i][0]][envelopes[i][1]] = 1;
        }
        
        // Construct e matrix, e(i,j) = envelope exists? 1 : 0
        // for (auto i = 0; i < count; i++)
        // {
        //     /* code */
        // }
        
        // Initialize M(maxX,maxY) matrix, tracks maximum amount of envelopes 
        // for each pair of dimensions.
        // for i,
        //  for j,
        // if()

        // Deallocate dynamic matrices.
        for (auto i = 0; i < maxX; i++)
        {
            delete[] exists[i];
        }
        delete[] exists;
        return -1;
    }
};

int main() {
    Solution* obj;
    int num = -1;
    vector<vector<int>> envelopes;
    envelopes.push_back(vector<int>{5,4});
    envelopes.push_back(vector<int>{6,4});
    envelopes.push_back(vector<int>{6,7});
    envelopes.push_back(vector<int>{2,3});
    num = obj->maxEnvelopes(envelopes);
    return 0;
}