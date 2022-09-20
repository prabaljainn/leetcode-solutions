class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int num = -1;
        int freq =0;
        for(int i=0; i<nums.size(); i++){
            if(num==nums[i]){
                freq++;
            }
            else{
                freq--;
                if(freq==-1 or freq==0){
                    freq =1;
                    num= nums[i];
                }
            }
        }
        return num;
    }
};