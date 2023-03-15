// https://leetcode.com/problems/linked-list-random-node/submissions/914580124/
// Only Solution class definition is submitted to leetcode.
#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

//  Define node of singly-linked list.
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
        //ListNode* curNode = head;
        while (head != nullptr){         
            values.push_back(head);
            head = head->next;
        }
    }
    int getRandom() {
        int index = rand() % values.size();
        return values[index]->val;
    }
private:    
    vector<ListNode*> values;
    
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
    int num = 0;
    for (int i = 0; i < 50; i++)
    {
        num = obj->getRandom();
        cout << num << endl;
    }
    return 0;
}