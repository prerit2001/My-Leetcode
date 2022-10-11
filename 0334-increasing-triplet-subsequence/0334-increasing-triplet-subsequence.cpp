class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        if(nums.size()<=2)return false;
        vector<int>left(nums.size(),0);int mini=nums[0];
        for(int i=1;i<nums.size();i++){
            if(nums[i]>mini){
                left[i]=1;
            }
            else mini=min(mini,nums[i]);
        }
        int maxi=nums[nums.size()-1];
        for(int i=nums.size()-2;i>=0;i--){
            if(nums[i]<maxi){
                if(left[i])return true;
            }
            else maxi=max(maxi,nums[i]);
        }
        
        return false;
    }
};