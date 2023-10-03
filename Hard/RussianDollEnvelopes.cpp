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
        pair<int, int>** largest;

        for (auto i = 0; i < envelopes.size(); i++) {
            if (envelopes[i][0] > maxX) {
                maxX = envelopes[i][0];
            }
            if (envelopes[i][1] > maxY) {
                maxY = envelopes[i][1];
            }
        }
        // exists[i][j] = 1 if an envelope exists of dimension (i,j), else 0.
        exists = new int* [maxX + 1];
        // M[i][j] = max number of envelopes you can fit in dimensions (i,j)
        M = new int* [maxX + 1];
        largest = new pair<int, int>* [maxX + 1];

        // Declare 'exists' and 'M' matrices
        for (auto i = 0; i <= maxX; i++)
        {
            exists[i] =     new int[maxY + 1];
            M[i] =          new int[maxY + 1];
            largest[i] =    new pair<int, int>[maxY + 1];
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
        int topSolution = 0;
        int leftSolution = 0;
        bool topCanUseIJEnv = false;
        bool leftCanUseIJEnv = false;
        for (int i = 1; i <= maxX; ++i)
        {
            for (int j = 1; j <= maxY; ++j)
            {

                // If an envelope exists @ (i,j) and it will contain largest...
                // ...envelope of the sequence, update this cell.
                if (exists[i][j] == 1) {
                    // If top neighbor solution can use [i,j], increase topSolution value.
                    if (largest[i-1][j].first < i && largest[i-1][j].second < j) {

                        topSolution = M[i - 1][j] + 1;
                        topCanUseIJEnv = true;
                    }
                    else
                    {
                        topSolution = M[i - 1][j];
                        topCanUseIJEnv = false;
                    }
                    // If left neighbor solution can use [i,j], increase leftSolution value.
                    if (largest[i][j-1].first < i && largest[i][j - 1].second < j) {
                        leftSolution = M[i][j-1] + 1;
                        leftCanUseIJEnv = true;
                    }
                    else{
                        leftSolution = M[i][j-1];
                        leftCanUseIJEnv = false;
                    }
                    // Compare top & left solution values to decide at solution path intersections.
                    // If topSolution better, update subsolution (i,j) with solution of (i-1,j)
                    if (topSolution > leftSolution) {
                        // If the (i,j) envelope is usable, update largest(i,j)
                        if (topCanUseIJEnv) {
                            M[i][j] = M[i - 1][j] + 1;
                            largest[i][j].first = i;
                            largest[i][j].second = j;
                        }
                        // top solution path is better, but cannot use (i,j) envelope
                        else{
                            largest[i][j] = largest[i - 1][j];
                            M[i][j] = M[i - 1][j];
                        }
                    }
                    // If leftSolution better, update subsolution (i,j) with solution of (i-1,j)
                    else{
                        if (leftCanUseIJEnv) {
                            largest[i][j].first = i;
                            largest[i][j].second = j;
                            M[i][j] = M[i][j - 1] + 1;
                        }
                        else {
                            // If left solution is better but it cannot use
                            // (i,j) envelope, copy largest(i,j-1).
                            largest[i][j] = largest[i][j - 1];
                            M[i][j] = M[i][j - 1];
                        }
                    }
                }
                // No (i,j) envelope, just compare top and left neighbor solution values
                // to update subsolution (i,j)
                else {
                    if (M[i - 1][j] > M[i][j - 1]) {
                        M[i][j] = M[i - 1][j];
                        largest[i][j] = largest[i - 1][j];
                    }
                    else {
                        M[i][j] = M[i][j - 1];
                        largest[i][j] = largest[i][j - 1];
                    }
                }
                //// Propagate solution
                //// Check if not on maxX edge of matrix before indexing (x+1) neighbor.
                //if (i != maxX) {
                //    // Propagate this cells solution if it's better than
                //    //its neighbors solution
                //    if (M[i][j] > M[i + 1][j]) {
                //        M[i + 1][j] = M[i][j];
                //        largest[i + 1][j].first = largest[i][j].first;
                //        largest[i + 1][j].second = largest[i][j].second;
                //    }
                //}
                //// Check if not on MaxY edge of matrix before indexing (y+1) neighbor.
                //if (j != maxY) {
                //    // Propagate this cells solution if it's better than 
                //    //its neighbors solution
                //    if (M[i][j] > M[i][j + 1]) {
                //        M[i][j + 1] = M[i][j];
                //        largest[i][j + 1].first = largest[i][j].first;
                //        largest[i][j + 1].second = largest[i][j].second;
                //    }
                //}
                cout << "\ni: " << i << " j: " << j << endl;
                printGrid(M, maxX, maxY);
                printEnvGrid(largest, maxX, maxY);
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
    void printGrid(int** M, int maxX, int maxY) {
        cout << endl;
        cout << "M grid: " << endl;
        for (auto i = 1; i <= maxX; i++)
        {
            for (auto j = 1; j <= maxY; j++)
            {
                cout << " " << M[i][j];
            }
            cout << endl;
        }

    }

    void printEnvGrid(pair<int, int>** largest, int maxX, int maxY) {
        cout << endl;
        cout << "largest grid : " << endl;
        for (auto i = 1; i <= maxX; ++i)
        {
            for (auto j = 1; j <= maxY; ++j)
            {
                cout << "  (" << largest[i][j].first << "," << largest[i][j].second << ")";
            }
            cout << endl;
        }

    }

    // Return optimal sequence of envelopes 
    vector<vector<int>> getEnvelopeSeq(int** M, int maxX, int maxY) {
        int i = maxX;
        int j = maxY;
        vector<vector<int>> sequence;
        sequence.push_back(vector<int>{i, j});
        while (i + j > 0) {
            // If cur val != neighbor vals, record envelope
            if (i > 0) {
                if (M[i][j] > M[i - 1][j]) {

                }
            }
            // If not on either edge, compare top and left neighbors
            if (i * j > 0) {
                // If left neig. > top neig. move left
                if (M[i - 1][j] > M[i][j - 1]) {
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
    // Test Case 1
    /*envelopes.push_back(vector<int>{5, 4});
    envelopes.push_back(vector<int>{6, 4});
    envelopes.push_back(vector<int>{6, 7});
    envelopes.push_back(vector<int>{2, 3});*/
    
    // Test Case 3
    /*envelopes.push_back(vector<int>{6, 10});
    envelopes.push_back(vector<int>{11, 14});
    envelopes.push_back(vector<int>{6, 1});
    envelopes.push_back(vector<int>{16, 14});
    envelopes.push_back(vector<int>{13, 2});*/

    //[[19,17],[8,14],[11,4],[12,20],[19,13],[3,12],[5,12],[19,9],[20,3],
    // [11,19],[20,20],[7,14],[9,13],[2,8],[20,7],[16,6],[16,3],[10,2],[4,6],[3,17]]
    // Test Case 3: (answer 5)
    envelopes.push_back(vector<int>{19, 17});
    envelopes.push_back(vector<int>{8, 14});
    envelopes.push_back(vector<int>{11, 4});
    envelopes.push_back(vector<int>{12, 20});
    envelopes.push_back(vector<int>{19, 13});
    envelopes.push_back(vector<int>{3, 12});
    envelopes.push_back(vector<int>{5, 12});
    envelopes.push_back(vector<int>{19, 9});
    envelopes.push_back(vector<int>{20, 3});
    envelopes.push_back(vector<int>{11, 19});
    envelopes.push_back(vector<int>{20, 20});
    envelopes.push_back(vector<int>{7, 14});
    envelopes.push_back(vector<int>{9, 13});
    envelopes.push_back(vector<int>{2, 8});
    envelopes.push_back(vector<int>{20, 7});
    envelopes.push_back(vector<int>{16, 6});
    envelopes.push_back(vector<int>{16, 3});
    envelopes.push_back(vector<int>{10, 2});
    envelopes.push_back(vector<int>{4, 6});
    envelopes.push_back(vector<int>{3, 7});
    num = obj->maxEnvelopes(envelopes);
    cout << num << endl;
    return 0;
}