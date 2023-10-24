#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    // O(n) time, no division operation allowed.
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> output(n);
        // suffixProduct[i] := product of [i:end] (inclusive)
        vector<int> suffixProduct(n);
        // prefixProduct[i] := product of 1st i elements.
        vector<int> prefixProduct;
        int product = nums[0];
        prefixProduct.push_back(product);
        for (int i = 1; i < n; i++)
        {
            product = product * nums[i];
            prefixProduct.push_back(product);
        }

        product = nums[n-1];
        suffixProduct[suffixProduct.size()-1] = product;
        for (int i = n-2; i >= 0; --i)
        {
            product = product * nums[i];
            suffixProduct[i] = product;
        }
        // Manually handle first and last elements
        output[0] = suffixProduct[1];
        output[n-1] = prefixProduct[n-2];
        for(int i = 1; i < nums.size()-1; i++)
        {
            //product = (prefixProduct[i-1] - (prefixProduct[i-1] * nums[i])) * (suffixProduct[i+1] - (suffixProduct[i+1] * nums[i]));
            product = prefixProduct[i-1] * suffixProduct[i+1];
            output[i] = product;
        }
        


        return output;
    }
};

int main(){
    Solution sol = Solution();
    vector<int> nums1{1,2,3,4};
    vector<int> nums2{-1,1,0,-3,3};
    vector<int> output = sol.productExceptSelf(nums2);
    for (auto i:output)
    {
        cout << i << " ";
    }
    cout << endl;
    
    return 0;
}