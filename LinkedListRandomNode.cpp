// https://leetcode.com/problems/linked-list-random-node/submissions/914580124/
// Only Solution class definition is submitted to leetcode.
#include <iostream>
#include <cstdlib>

using namespace std;

//  Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 
class Solution {
public:
    Solution(ListNode* head) {
        this->head = head;
        ListNode* curNode = head;
        //cout << "head address: " << head << endl;        
        while (curNode != nullptr){
            listLength++;            
            //cout << curNode->val << endl;
            curNode = curNode->next;
        }
        //cout << "(after) head address: " << head << endl;        
    }
    int getRandom() {
        //srand((unsigned) time(NULL));
        //cout << "head address from getRandom(): " << head << endl;
        int index = rand() % listLength;
        ListNode* curNode = head;
        for (int i = 0; i < index; i++)
        {
            curNode = curNode->next;
        }
        cout << curNode->val << endl;
        return curNode->val;
    }
private:
    ListNode* head = nullptr;
    int listLength = 0;
    
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */

// main() function is used for testing solution obj.
int main(){
    ListNode* head = new ListNode(1);
    ListNode* secNode = new ListNode(2);
    ListNode* thirdNode = new ListNode(3);
    ListNode* fourthNode = new ListNode(4);
    head->next = secNode;
    secNode->next = thirdNode;
    thirdNode->next = fourthNode;
    Solution* obj = new Solution(head);
    for (int i = 0; i < 50; i++)
    {
        obj->getRandom();
    }
    return 0;
}