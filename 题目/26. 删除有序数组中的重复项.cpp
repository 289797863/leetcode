//只要找到一个与左指针同的数就把他移到前面去。
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int left = 0, right = 0;
        while(right<nums.size()){
            if(nums[left]!=nums[right]){
                ++left;
                nums[left] = nums[right];
            }
            ++right;
        }
        return left+1;
    }
};
