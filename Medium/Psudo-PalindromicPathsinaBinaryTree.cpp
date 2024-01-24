/*
    Given a binary tree where node values are digits from 1 to 9. A path in
    the binary tree is said to be pseudo-palindromic if at least one
    permutation of the node values in the path is a palindrome.
    Return the number of pseudo-palindromic paths going from the root node to leaf nodes.
https://leetcode.com/problems/pseudo-palindromic-paths-in-a-binary-tree/description/?envType=daily-question&envId=2024-01-24  
*/
#include <iostream>
#include <string>

using namespace std;

//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
 
class Solution {
public:
    int pseudoPalindromicPaths (TreeNode* root) {
        
    }
};

// Sub-problem of original LC problem. Detect if given string is a pseudo-palidrome.
bool pseudoPalidrome(int nums[3]){
    // Only need to track character frequencies.
    // At most 1 character can appear an odd number of times.
    // Count frequency for each digit in string.
    int freqs[9]={0};
    for(int i=0; i<3; ++i){
        freqs[nums[i]-1]++;
    }
    int numOdds = 0;
    for (int i = 0; i < 9; ++i){
        if(freqs[i]%2!=0)
            numOdds++;
    }
    if(numOdds>1)
        return false;
    return true;
}

int main(){
    int nums1[3] = {2,1,2};
    pseudoPalidrome(nums1);
    return 1;
}