/* 
Given two integers an and b, return the sum of the two integers without 
using the operators '+' and '-'
https://leetcode.com/problems/sum-of-two-integers/description/
*/
#include <iostream>
#include <math.h>
#include <stack>
using namespace std;

class Solution {
    public:
        int getSum(int a, int b){
            // int aBit, bBit, aSignBit, bSignBit, carryBit;
            // int mask_bit_pos;
            // int curBit;
            // stack<int> sumBits;
            // aSignBit = (int(pow(2,31)) & a) >> 31;
            // bSignBit = (int(pow(2,31)) & b) >> 31;
            // for (int i = 31; i >= 0; --i){
            //     mask_bit_pos = int(pow(2,i));
            //     curBit = ((a & mask_bit_pos) >> i);
            //     cout << curBit;
            // }
            // cout << endl;
            // for (int i = 31; i >= 0; --i){
            //     mask_bit_pos = int(pow(2,i));
            //     curBit = ((b & mask_bit_pos) >> i);
            //     cout << curBit;
            // }
            // cout << "\n---------------------------------"<<endl;
            // NOTE: Does ++i break the rule???
            // for (int i = 0; i < 32; ++i){
            //     mask_bit_pos = int(pow(2,i));
            //     aBit = ((a & mask_bit_pos) >> i);
            //     bBit = ((b & mask_bit_pos) >> i);
            //     cout << "aBit: " << aBit <<" ";
            //     cout << "bBit: " << aBit <<" ";
            //     cout << "carBit: " << carryBit;
            //     // Both a & b bits are 1
            //     if(aBit * bBit == 1){
            //         if(carryBit == 1){
            //             // All bits 1, push 1 onto stack
            //             sumBits.push(1);
            //         }
            //         else{
            //             // a&b=1, carry=0; push 0 onto stack
            //             sumBits.push(0);
            //             carryBit = 1;
            //         }
            //     }
            //     // aBit XOR bBit is 1.
            //     else if(aBit ^ bBit == 1){
            //         cout << " XOR";
            //     }
            //     cout << endl;
            // }
            /*
            From this solution by kyshnivas10
            https://leetcode.com/problems/sum-of-two-integers/solutions/132479/simple-explanation-on-how-to-arrive-at-the-solution/
            */
           // *Standard/Intended Solution*: Binary manipulation.
            int carry = 1;
            while(carry != 0){
                // If both bits are 1, set caarry bit to 1.
                carry = a & b;
                // Sum of bits (neglecting carry bits)
                a = a ^ b;
                /*  Shift carry bits over 1 so they line up with the appropriate space.
                    Reassign to b since all the information from the original opperands
                    has been stored into carry & a. */ 
                b = carry << 1;
            }
            // NOTE: The rule does not cover the ++, --, +=, -= operators. 
            /*  I can't beleive I didn't think about this, especially after 
                liberally usiing '++' in my loops.*/
            // Chad solution
            //a +=b;
            return a;
        }
};

int main(){
    Solution sol = Solution();
    int a1 = 1;
    int b1 = 1;
    int a2 = -1;
    int b2 = 1;
    sol.getSum(a2,b2);
    return 0;
}