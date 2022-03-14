//使用滑动窗口解决了带负数的数组的问题
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int left=0,right=0,max_sum=-pow(10,8),sum = 0 ;
        int n = nums.size();
        while(right<n){
            while((sum+nums[right] <= 0 || nums[left]<=0)&&left<right){
                sum -=nums[left];
                left++;
                if(left==right-1) max_sum = max(sum,max_sum);
            }
            sum += nums[right];
            right++;
            max_sum = max(sum,max_sum);
        }
    return max_sum;
    }
};
