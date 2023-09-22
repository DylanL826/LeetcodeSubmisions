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
        int maxX = 0;
        int maxY = 0;
        // exists[i][j] = 1 if an envelope exists of dimension (i,j), else 0.
        int** exists = new int*[maxX+1];
        // M[i][j] = max number of envelopes you can fit in dimensions (i,j)
        int** M = new int*[maxX+1];
        for (auto i = 0; i < envelopes.size(); i++){
            if(envelopes[i][0] > maxX){
                maxX = envelopes[i][0];
            }
            if(envelopes[i][1] > maxY){
                maxY = envelopes[i][1];
            }
        }
        
        // Declare 'exists' and 'M' matrices
        for (auto i = 0; i < maxX+1; i++)
        {
            exists[i] = new int[maxY+1];
            M[i] = new int[maxY+1];
        }
        // Assign 0 to all elements in 'exists' and 'M' 
        for (auto i = 0; i <= maxX; i++)
        {
            for (auto j = 0; j <= maxY; j++)
            {
                exists[i][j] = 0;
                M[i][j] = 0;
            }
            
        }
        // Update exists & M matrices at indeces where an envelope exists.
        for (auto i = 1; i < envelopes.size(); i++)
        {
            exists[envelopes[i][0]][envelopes[i][1]] = 1;
            //M[envelopes[i][0]][envelopes[i][1]] = 1;
        }
        
        // At each element of M, propagate the cells solution to (i+1) & (j+1)
        // for each pair of dimensions.
        for (auto i = 1; i <= maxX; ++i)
        {
            for (auto j = 1; j <= maxY; ++j)
            {
                // Check if not on maxX edge of matrix before indexing (x+1) neighbor.
                if(i != maxX){
                    // Propagate this cells solution if it's better than 
                    //its neighbors solution
                    if(exists[i][j] + M[i][j] > exists[i+1][j] + M[i+1][j]){
                        M[i+1][j] = M[i][j] + exists[i][j];
                    }
                }
                // Check if not on MaxY edge of matrix before indexing (y+1) neighbor.
                if(i != maxY){
                    // Propagate this cells solution if it's better than 
                    //its neighbors solution
                    if(exists[i][j] + M[i][j] > exists[i][j+1] + M[i][j+1]){
                        M[i][j+1] = M[i][j] + exists[i][j];
                    }
                }
                //if(exists[i][j] + M[i][j] > exists[i][j+1] + M[i][j+1])
            }
            
        }
        // Get envelope sequence from backtracing. 
        // if(M[i-1][j] + exists[i-1][j] == M[i][j]) // (x-1) neighbor in optimal path.


        // Deallocate dynamic matrices.
        for (auto i = 0; i < maxX; i++)
        {
            delete[] exists[i];
        }
        delete[] exists;
        return M[maxX][maxY];
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
    cout << num << endl;
    return 0;
}