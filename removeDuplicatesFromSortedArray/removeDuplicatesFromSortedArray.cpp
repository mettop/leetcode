// Source : https://leetcode.com/problems/remove-duplicates-from-sorted-array/
// Author : weekend27
// Date   : 2015-11-18

/**********************************************************************************

Given a sorted array, remove the duplicates in place such that each element appear only once and return the new length.

Do not allocate extra space for another array, you must do this in place with constant memory.

For example,

Given input array nums = [1,1,2],

Your function should return length = 2, with the first two elements of nums being 1 and 2 respectively. It doesn't matter what you leave beyond the new length.

**********************************************************************************/

// How to do it:
// Two pointers: when one index meets duplicates, another one will stay and not increase. 

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int index = 0;
        int len = nums.size();

        if (len == 0){
            return 0;
        }

        for (int i = 1; i < len; i++){
            if (nums[index] != nums[i])
                nums[++index] = nums[i];
        }
        return index + 1;
    }
};
