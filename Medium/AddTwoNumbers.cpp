// https://leetcode.com/problems/add-two-numbers/

#include<iostream>
#include<stack>
#include<vector>
#include<cmath>

using namespace std;

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int numDigits = 0;
        // Initialize numbers represented by linkedLists 1 & 2.
        stack<int> listNums;
        int num1 = 0;
        int num2 = 0;
        // Reverse number sequence w/ stack.
        // TODO: Try adding one digit at a time so you could iterate both...
        // ... LL's in one loop & not need to store the values into a stack.
        while (l1 != nullptr)
        {
            listNums.push(l1->val);
            l1 = l1->next;
        }
        numDigits = listNums.size();
        while(!listNums.empty()){
            num1 += listNums.top();
            // TODO: how to not do this on last iteration. 
            num1 *= 10;
            listNums.pop();
        }

        while (l2 != nullptr)
        {
            listNums.push(l2->val);
            l2 = l2->next;
        }
        while(!listNums.empty()){
            num2 += listNums.top();
            num2 *= 10;
            listNums.pop();
        }
        int num3 = (num1 + num2) / 10;
        // Initialize head.
        ListNode* solutionNode = new ListNode();
        // Initialize iterator node variable.
        ListNode* node = solutionNode;
        int temp;
        for (int i = 0; i < numDigits; i++){  
            // TODO: Check speed & memory improvement after removing
            // ... temp variable          
            // TODO: Could remove one pow() by shifting first and then num3 & 10.
            temp = num3 % int(pow(10,i+1)); // Remove digits left of i'th digit.
            temp = temp / int(pow(10, i)); // Shift i'th digit to ones place.           
            node->val = temp;
            // TODO: Cheaper way to do this than checking every iteration?
            (i<numDigits-1) ? node->next = new ListNode(): node->next = nullptr;            
            node = node->next;
        }        
        return solutionNode;
    }
};

int main(){
    // (node1c node1b node1a + node2c node2b node2a = node3c node3b node3a)
    ListNode* node1a = new ListNode(2);
    ListNode* node1b = new ListNode(6);
    ListNode* node1c = new ListNode(1);
    node1a->next = node1b;
    node1b->next = node1c;
    
    ListNode* node2a = new ListNode(2);
    ListNode* node2b = new ListNode(1);
    ListNode* node2c = new ListNode(5);
    node2a->next = node2b;
    node2b->next = node2c;

    // 162 + 512 = 674
    
    Solution* obj = new Solution();
    ListNode* solNode = new ListNode();
    solNode = obj->addTwoNumbers(node1a, node2a);
    stack<int> solutionS;
    while (solNode != nullptr)
    {
        solutionS.push(solNode->val);
        solNode = solNode->next;
    }
    while (!solutionS.empty())
    {
        cout << solutionS.top() << endl;
        solutionS.pop();
    }
    
    return 0;
}