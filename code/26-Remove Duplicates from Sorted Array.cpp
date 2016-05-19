/*注意条件中的已排序数组，即可设计O(N)的算法
 *思路；每个不重复点j一定满足：nums[j-1]!=nums[j]
*/
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i=1,j=1;
        int numsLen = nums.size();
        if(numsLen==0) return 0;
        for(;j<numsLen;++j){
            if(nums[j-1]!=nums[j]){
                nums[i]=nums[j];
                ++i;
            }
        }
        return i;
    }
};