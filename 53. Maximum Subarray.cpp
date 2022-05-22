class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int cur_sum = nums[0];
        int max_sum = nums[0];
        for(int i = 1;i< nums.size();i++)
        {   
            cur_sum += nums[i];
            cur_sum = max(nums[i],cur_sum);
            max_sum = max(cur_sum,max_sum);
        }
        return max_sum;
    }
};
