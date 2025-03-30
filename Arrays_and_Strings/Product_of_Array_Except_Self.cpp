/*EXERCISE TEXT
Given an integer array nums, return an array answer such that answer[i] is equal to the product of all the elements of nums except nums[i].
The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.

You must write an algorithm that runs in O(n) time and without using the division operation.

 
Example 1:
    Input: nums = [1,2,3,4]
    Output: [24,12,8,6]
Example 2:
    Input: nums = [-1,1,0,-3,3]
    Output: [0,0,9,0,0]
 

Constraints:
    2 <= nums.length <= 105
    -30 <= nums[i] <= 30
    The input is generated such that answer[i] is guaranteed to fit in a 32-bit integer.
*/

#include <iostream>
#include <vector>

using namespace std; 

vector<int> productExceptSelf(vector<int>& nums) {
    ios::sync_with_stdio(false); // Disableing IO sync between C++ and C (gets faster time for bigger inputs)
    int n = nums.size();
    vector<int> result(n, 1);

    //Find prefix products for every element
    int prefix = 1;
    for (int i = 0; i < n; i++) {
        result[i] = prefix;
        prefix *= nums[i];
    }

    //Find sufix for every element --> combine prefix * sufix for final result
    int suffix = 1;
    for (int i = n - 1; i >= 0; i--) {
        result[i] *= suffix;
        suffix *= nums[i];
    }

    return result;
}



int main(){
    std::vector<int> nums = {-1,1,0,-3,3};
    for (int element : productExceptSelf(nums))
        std::cout << element << " ";
}