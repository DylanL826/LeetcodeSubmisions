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
 
 //TODO: MLE for large trees.
class Solution {
public:
    int pseudoPalindromicPaths (TreeNode* root) {
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
    // TODO: Pass curPath by reference to reduce memory usage in large trees.
    // Recursively generate set of root-to-leaf paths from a binary tree.
    void makePath(TreeNode* node, vector<int> &curPath, vector<vector<int>> &paths){
        // Add the current node's value to curPath
        curPath.push_back(node->val);
        // If at leaf node add completed curPath to list of paths and terminate.
        if(node->left == nullptr && node->right == nullptr){
            paths.push_back(curPath);
            return;
        }
        // Else continue to child nodes.
        else{
            // Only make a copy vector if node has 2 children.
            if(node->left != nullptr && node->right != nullptr){
                vector<int> copyPath = curPath;
                // Give left child original path, give right the copy.
                makePath(node->left, curPath, paths);
                makePath(node->right, copyPath, paths);
            }
            // Only 1 child, pass curPath to the child.
            else{
                if(node->left != nullptr)
                    makePath(node->left, curPath, paths);
                else
                    makePath(node->right, curPath, paths);
            }
        }
    }  
    // Detect if given set of numbers is a pseudo-palidrome.
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

    // Tree 2
    TreeNode* llNode = new TreeNode(1);
    TreeNode* lrrNode = new TreeNode(1);
    TreeNode* rNode = new TreeNode(1);
    TreeNode* lrNode = new TreeNode(3, nullptr, lrrNode);
    TreeNode* lNode = new TreeNode(3, llNode, lrNode);
    TreeNode* root2 = new TreeNode(3, lNode, rNode);

    // Tree3
    TreeNode* root3 = new TreeNode(9);


    Solution sol;
    vector<int> path;
    vector<vector<int>> paths;
    sol.pseudoPalindromicPaths(root);
    
    //cout << "Num paths that are pseudopalindromes: " << numPsuedoPalindromes << endl;
    
    return 1;
}