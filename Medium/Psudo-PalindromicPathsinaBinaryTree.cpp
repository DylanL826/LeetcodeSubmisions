/*
    Given a binary tree where node values are digits from 1 to 9. A path in
    the binary tree is said to be pseudo-palindromic if at least one
    permutation of the node values in the path is a palindrome.
    Return the number of pseudo-palindromic paths going from the root node to leaf nodes.
https://leetcode.com/problems/pseudo-palindromic-paths-in-a-binary-tree/description/?envType=daily-question&envId=2024-01-24  
*/
#include <iostream>
#include <string>
#include <vector>

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
        //TODO: Traverse binary tree and construct a set for each path.
        vector<int> path;
        vector<vector<int>> paths;
        makePath(root, path, paths);
        int numPsuedoPalindromes = 0;
        for (int i = 0; i < paths.size(); ++i)
        {
            if(pseudoPalidrome(paths[i])){
                ++numPsuedoPalindromes;
            }
        }
        return numPsuedoPalindromes;
    }
    // Recursively generate set of root-to-leaf paths from a binary tree.
    void makePath(TreeNode* node, vector<int> curPath, vector<vector<int>> &paths){
        // Add the current node's value to curPath
        curPath.push_back(node->val);
        // If at leaf node, the path is complete, return curPath
        if(node->left == nullptr && node->right == nullptr){
            paths.push_back(curPath);
            return;
        }
        // Else continue to child nodes.
        else{
            if(node->left != nullptr)
                makePath(node->left, curPath, paths);
            if(node->right != nullptr)
                makePath(node->right, curPath, paths);
        }
    }  
    // Sub-problem of original LC problem. Detect if given string is a pseudo-palidrome.
    bool pseudoPalidrome(vector<int> nums){
        // Only need to track character frequencies.
        // At most 1 character can appear an odd number of times.
        // Count frequency for each digit in string.
        int freqs[9]={0};
        for(int i=0; i<nums.size(); ++i){
            freqs[--nums[i]]++;
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
};
// Recursive helper function to generate the root-to-leaf paths in a tree.



int main(){
    int nums1[10] = {2,1,2,3,3,3,3,4,4,1};
    // Leaf nodes
    TreeNode* leaf1 = new TreeNode(3);
    TreeNode* leaf2 = new TreeNode(1);
    TreeNode* leaf3 = new TreeNode(1);

    // Child nodes
    TreeNode* lChild = new TreeNode(3, leaf1, leaf2);
    TreeNode* rChild = new TreeNode(1,nullptr, leaf3);

    // Root node
    TreeNode* root = new TreeNode(2, lChild, rChild);
    //pseudoPalidrome(nums1, 10);
    Solution sol;
    vector<int> path;
    vector<vector<int>> paths;
    sol.pseudoPalindromicPaths(root);
    
    //cout << "Num paths that are pseudopalindromes: " << numPsuedoPalindromes << endl;
    
    return 1;
}