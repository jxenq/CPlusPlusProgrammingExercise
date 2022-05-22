class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> solve;
        for(int i = 0;i < nums.size() - 1;i++)
        {
            for(int j = i + 1;j < nums.size();j++)
            {
                if(nums[i] + nums[j] == target)
                {    solve.push_back(i);
                     solve.push_back(j);
                     break;
                }
            }
        }
        return solve;
    }
};
