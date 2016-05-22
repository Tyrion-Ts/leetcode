/*
* 思路：用两个下标记录当前生成的新数组以及当前遍历到的原数组的位置即可，O(N)
*/
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int i,j;
        int numsLen = nums.size();
        if(numsLen == 0) return 0;
        for(j=0,i=0;j<numsLen;++j){
            if(nums[j] == val){
                continue;
            }
            else{
                nums[i]=nums[j];
                ++i;
            }
        }
        return i;
    }
};