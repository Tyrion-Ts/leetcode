/*
* 思路；模拟手算，非常简单，会用vector的基本函数即可
*/
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int digLen = digits.size();
        int plus = 1;
        int i = digLen - 1;
        while(plus>0 && i>=0){
            int tmp = (digits[i]+plus);
            plus = tmp/10;
            digits[i]= tmp%10;
            --i;
        }
        if(plus>0 && i<0){
            digits.insert(digits.begin(),plus);
        }
        return digits;
    }
};