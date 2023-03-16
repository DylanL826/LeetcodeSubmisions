// https://leetcode.com/problems/roman-to-integer/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    // Convert roman numeral to integer and return it.
    int romanToInt(string s) {
        int num = 0;
        int numeralSize = -1;
        
        for (int i = 0; i < s.length(); i++)
        {
            //I, V, X, L, C, D and M.
            switch (s[i])
            {
            case 'I':
                num+=1;
                numeralSize = 1;
                break;

            case 'V':
                // If preceded by an I, subtract 1 (undo previous addition)
                // ... then add 4
                if(numeralSize == 1){
                    num += 3;
                }
                // Not preceded by subtracting I, add 5.
                else{
                    num += 5;
                    numeralSize = 5;
                }
                break;

            case 'X':
                // Preceded by subtracting 'I', minus 1 & plus 9
                if (numeralSize == 1){
                    num+=8;
                }
                else{
                    num+=10;
                    numeralSize = 10;
                }
                break;    
            
            case 'L':
                // Preceded by subtracting 'X', -10 + 40
                if(numeralSize == 10)
                    num += 30;
                else{
                    num += 50;
                    numeralSize = 50;
                }
                break;

            case 'C':
                // Preceded by subtracting 'X', -10 + 90
                if(numeralSize == 10)
                    num += 80;
                else{
                    num += 100;
                    numeralSize = 100;
                }
                break;

            case 'D':
                // Preceded by subtracting 'C', -100 + 400
                if(numeralSize == 100)
                    num += 300;
                else{
                    num += 500;
                    numeralSize = 500;
                }
                break;

            case 'M':
                // Preceded by subtracting 'C', -100  + 900
                if(numeralSize == 100)
                    num += 800;
                else{
                    num += 1000;
                    numeralSize = 1000;
                }
                break;
            default:
                cout << "Invalid character in numeral string" << endl;
                return num;
                break;
            }
        }
        return num;
    }
};


int main(){

    string numeral = "III";
    int num = -1;
    Solution* obj;
    num = obj->romanToInt(numeral);    
    cout << num << endl;
    return 0;
}