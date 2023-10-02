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
        // Binary matrix if an envelope exists at [i][j] dimensions.
        int** exists;
        // Matrix of optimal solutions. 
        int** M;
        // Dimensions of largest envelope in solution sequence at [i][j] dimensions.
        pair<int,int>** largest;
        
        for (auto i = 0; i < envelopes.size(); i++){
            if(envelopes[i][0] > maxX){
                maxX = envelopes[i][0];
            }
            if(envelopes[i][1] > maxY){
                maxY = envelopes[i][1];
            }
        }
        // exists[i][j] = 1 if an envelope exists of dimension (i,j), else 0.
        exists = new int*[maxX+1];
        // M[i][j] = max number of envelopes you can fit in dimensions (i,j)
        M = new int*[maxX+1];
        largest = new pair<int,int>*[maxX+1];

        // Declare 'exists' and 'M' matrices
        for (auto i = 0; i <= maxX; i++)
        {
            exists[i] = new int[maxY+1];
            M[i] = new int[maxY+1];
            largest[i] = new pair<int,int>[maxX+1];
        }
        // Assign 0 to all elements in 'exists' and 'M' 
        for (auto i = 0; i <= maxX; i++)
        {
            for (auto j = 0; j <= maxY; j++)
            {
                exists[i][j] = 0;
                M[i][j] = 0;
                largest[i][j].first = 0;
                largest[i][j].second = 0;
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

                // If an envelope exists @ (i,j) and it will contain largest...
                // ...envelope of the sequence, update this cell.
                if(exists[i][j] == 1){
                    // Needs to be M[i][j] comparison here before comparing 
                    // largest[i][j] to i & j.
                    /*
                        Logic is by only chde
                    */
                    if(largest[i][j].first < i && largest[i][j].second < j){
                        // Update largest envelope in solution sequence to this one.
                        largest[i][j].first = i;
                        largest[i][j].second = j;

                        // Update max num envlopes.
                        M[i][j] += exists[i][j];
                    }

                }
                // Propagate solution
                // Check if not on maxX edge of matrix before indexing (x+1) neighbor.
                if(i != maxX){
                    // Propagate this cells solution if it's better than
                    //its neighbors solution
                    if(M[i][j] >  M[i+1][j]){
                        M[i+1][j] = M[i][j];
                        largest[i+1][j].first = largest[i][j].first;
                        largest[i+1][j].second = largest[i][j].second;
                    }
                }
                // Check if not on MaxY edge of matrix before indexing (y+1) neighbor.
                if(j != maxY){
                    // Propagate this cells solution if it's better than 
                    //its neighbors solution
                    if(M[i][j] > M[i][j+1]){
                        M[i][j+1] = M[i][j];
                        largest[i][j+1].first = largest[i][j].first;
                        largest[i][j+1].second = largest[i][j].second;
                    }
                }
                printGrid(M, maxX, maxY);
                //printEnvGrid(largest, maxX, maxY);
            }
            
        }
        // Get envelope sequence from backtracing. 
        // if(M[i-1][j] + exists[i-1][j] == M[i][j]) // (x-1) neighbor in optimal path.

        int solution = M[maxX][maxY];
        // Deallocate dynamic matrices.
        for (auto i = 0; i < maxX; i++)
        {
            delete[] exists[i];
            delete[] M[i];
            delete[] largest[i];
        }
        delete[] exists;
        delete[] M;
        delete[] largest;
        return solution;
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

    void printEnvGrid(pair<int,int>** largest, int maxX, int maxY){
        cout << endl;
        for (auto i = 0; i <= maxX; ++i)
        {
            for (auto j = 0; j <= maxY; ++j)
            {
                cout << "  (" << largest[i][j].first << "," << largest[i][j].second << ")";
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
    envelopes.push_back(vector<int>{6, 10});
    envelopes.push_back(vector<int>{11, 14});
    envelopes.push_back(vector<int>{6, 1});
    envelopes.push_back(vector<int>{16, 14});
    envelopes.push_back(vector<int>{13, 2});
    num = obj->maxEnvelopes(envelopes);
    cout << num << endl;
    return 0;
}