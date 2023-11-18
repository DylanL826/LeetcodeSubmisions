#include <iostream>
#include<string>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size()==0)
            return 0;
        // Find the length of the longest substring in s of...
        // ...all distinct characters.
        int j = 0;
        int maxSubstring = 1, curMax = 1;
        string subStr = s.substr(0,1);
        // Iterate through characters
        for (int i = 1; i < s.length(); i++)
        {
            // Get substring
            //subStr = s.substr(j,curMax);
            // Search substring for i'th character
            if(subStr.find(s[i]) != string::npos){
                // i'th Character found in substring, increment j and recheck
                // ... until at single character or i'th character not in new substr
                while (j<=i && subStr.find(s[i]) != string::npos)
                {
                    j++;
                    curMax--;
                    subStr = s.substr(j, i-j);
                }   
            }
            // character not in substring, add i'th character to substring
            subStr = s.substr(j, i-j+1);
            curMax++;
            maxSubstring = max(maxSubstring, curMax);
            
        }
        return maxSubstring;
    }
};


int main(){
    Solution sol = Solution();
    string str1 = "dvdf";
    
    int num1 = sol.lengthOfLongestSubstring(str1);
    return 0;
}