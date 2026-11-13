class Solution {
public:

    long long dp[205][10005];

    bool partition_equal_subset_sum(vector<int>& nums, int i, int target){

        if(i < 0){

            if(target == 0) return true;
            else return false;
        }

        if(dp[i][target] != -1) return dp[i][target];

        if(nums[i] <= target){

            bool op1 = partition_equal_subset_sum(nums, i-1, target - nums[i]);
            bool op2 = partition_equal_subset_sum(nums, i-1, target);

            return dp[i][target] = op1 || op2;
        }
        else{

            return dp[i][target] = partition_equal_subset_sum(nums, i-1, target);
        }
    }
    bool canPartition(vector<int>& nums) {

        int size = nums.size(), sum = 0;
        for(int i = 0; i < size; i++) sum += nums[i];

        if(sum % 2 != 0) return false;
        else{

            memset(dp, -1, sizeof(dp));
            bool ans = partition_equal_subset_sum(nums, size-1, sum/2);

            if(ans) return true;
            else return false;
        }  
    }
};