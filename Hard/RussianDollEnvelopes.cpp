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
        
        for (auto i = 0; i < envelopes.size(); i++){
            if(envelopes[i][0] > maxX){
                maxX = envelopes[i][0];
            }
            if(envelopes[i][1] > maxY){
                maxY = envelopes[i][1];
            }
        }
        // exists[i][j] = 1 if an envelope exists of dimension (i,j), else 0.
        int** exists = new int*[maxX+1];
        // M[i][j] = max number of envelopes you can fit in dimensions (i,j)
        int** M = new int*[maxX+1];
        
        // Declare 'exists' and 'M' matrices
        for (auto i = 0; i <= maxX; i++)
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
        for (auto i = 0; i < envelopes.size(); i++)
        {
            exists[envelopes[i][0]][envelopes[i][1]] = 1;
            //M[envelopes[i][0]][envelopes[i][1]] = 1;
        }
        // At each element of M, propagate the cells solution to (i+1) & (j+1)
        // for each pair of dimensions.
        for (int i = 1; i <= maxX; ++i)
        {
            for (int j = 1; j <= maxY; ++j)
            {
                // Update cells where an envelope exists.
                M[i][j] += exists[i][j];
                // Check if not on maxX edge of matrix before indexing (x+1) neighbor.
                if(i != maxX){
                    // Propagate this cells solution if it's better than 
                    //its neighbors solution
                    if(M[i][j] >  M[i+1][j]){
                        M[i+1][j] = M[i][j];
                    }
                }
                // Check if not on MaxY edge of matrix before indexing (y+1) neighbor.
                if(j != maxY){
                    // Propagate this cells solution if it's better than 
                    //its neighbors solution
                    if(M[i][j] > M[i][j+1]){
                        M[i][j+1] = M[i][j];
                    }
                }
                //printGrid(M, maxX, maxY);
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

    // Print values of dynamic matrix
    void printGrid(int** M, int maxX, int maxY){
        cout << endl;
        for (auto i = 0; i <= maxX; i++)
        {
            for (auto j = 0; j <= maxY; j++)
            {
                cout << " " << M[i][j];
            }
            cout << endl;
        }
        
    }

    // Return optimal sequence of envelopes 
    vector<vector<int>> getEnvelopeSeq(int** M, int maxX, int maxY){
        int i = maxX;
        int j = maxY;
        vector<vector<int>> sequence;
        sequence.push_back(vector<int>{i,j});
        while(i + j > 0){
            // If cur val != neighbor vals, record envelope
            if(i > 0){
                if(M[i][j] > M[i-1][j]){

                }
            }
            // If not on either edge, compare top and left neighbors
            if(i * j > 0){
                // If left neig. > top neig. move left
                if(M[i-1][j] > M[i][j-1]){
                    i--;
                }
            }
        }
        return sequence;
    }
};

int main() {
    Solution* obj = new Solution();
    int num = -1;
    vector<vector<int>> envelopes;
    envelopes.push_back(vector<int>{5,4});
    envelopes.push_back(vector<int>{6,4});
    envelopes.push_back(vector<int>{6,7});
    envelopes.push_back(vector<int>{2,3});
    envelopes.push_back(vector<int>{3,2});
    envelopes.push_back(vector<int>{10,7});
    envelopes.push_back(vector<int>{15,9});
    envelopes.push_back(vector<int>{12,8});
    envelopes.push_back(vector<int>{1,2});
    envelopes.push_back(vector<int>{1,2});
    envelopes.push_back(vector<int>{4,8});
    envelopes.push_back(vector<int>{4,8});
    envelopes.push_back(vector<int>{4,150});
    envelopes.push_back(vector<int>{200,150});
    num = obj->maxEnvelopes(envelopes);
    cout << num << endl;
    return 0;
}