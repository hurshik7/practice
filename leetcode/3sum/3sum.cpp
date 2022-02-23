class Solution {
public:
    bool isIn(vector<vector<int>>& nums, vector<int>& val) {
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i][0] != val[0] || nums[i][1] != val[1] || nums[i][2] != val[2]) {
                continue;
            }
            return true;
        }
        return false;
    }
    
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ret;
        if (nums.size() < 3) {
            return ret;
        }
        
        sort(nums.begin(), nums.end());
        if (nums[0] > 0) {
            return ret;
        }
        
        vector<int> temp;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > 0) {
                break;
            }
            int want = -nums[i];
            int hi = nums.size() - 1;
            int low = i + 1;
            while (low < hi) {
                if (nums[low] + nums[hi] == want) {
                    temp.clear();
                    temp.push_back(nums[i]);
                    temp.push_back(nums[low]);
                    temp.push_back(nums[hi]);
                    if (ret.size() == 0 || isIn(ret, temp) == false) {
                            ret.push_back(temp);   
                    }
                    hi--;
                } else if (nums[low] + nums[hi] < want) {
                    low++;
                } else {
                    hi--;
                }      
            }
        }
        
        return ret;
    }
};
