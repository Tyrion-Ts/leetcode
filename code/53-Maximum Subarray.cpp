class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int nSize = nums.size();
        int nMax = nums[0];
        int *nDp = new int[nSize];
        nDp[0] = nums[0];
        
        for(int i = 1; i < nSize; ++i)
        {
            if(nDp[i-1] >= 0) {
                nDp[i] = nDp[i-1] + nums[i] >= 0 ? nDp[i-1]+nums[i] : nums[i];
            }
            else {
                nDp[i] = nums[i];
            }
            
            if(nMax < nDp[i]){
                nMax = nDp[i];
            }
        }
        
        delete nDp;
        return nMax;
    }
};