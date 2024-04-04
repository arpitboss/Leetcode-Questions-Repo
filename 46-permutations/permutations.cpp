class Solution {
public:
    void permutation(vector<int>nums,int ind,vector<vector<int>>&arpit ){
        if(ind>=nums.size()){
            arpit.push_back(nums);
            return;
        }
            
        for (int i=ind;i<nums.size();i++) {
            swap(nums[i],nums[ind]);
            permutation(nums,ind+1,arpit);
            swap(nums[i],nums[ind]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>arpit;
        permutation(nums,0,arpit);
        return arpit;
    }
};