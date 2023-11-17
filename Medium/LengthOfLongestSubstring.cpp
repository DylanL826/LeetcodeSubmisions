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
                // i'th Character found in substring, reset at i'th character
                j = i;
                subStr = s.substr(i,1);
                curMax = 1;
            }
            else{
                // character not in substring, add i'th character to substring
                subStr = s.substr(j, i-j+1);
                curMax++;
                maxSubstring = max(maxSubstring, curMax);
            }
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