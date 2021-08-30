class Solution {
    
    void merge(vector<pair<int, int> > &aug_nums, vector<pair<int, int> > &temp, vector<int> &ans, int st, int mid, int en) {
        int i = st, j = mid+1, k = st;
        
        while (i <= mid && j <= en) {
            if (aug_nums[i].first <= aug_nums[j].first) {
                temp[k] = aug_nums[i];
                ans[aug_nums[i].second] += j-mid-1;
                i++, k++;
            } else {
                temp[k] = aug_nums[j];
                k++, j++;
            }
        }
        while (i <= mid) {
            ans[aug_nums[i].second] += (j-mid-1);
            temp[k++] = aug_nums[i++];
            
        }
        while (j <= en) {
            temp[k++] = aug_nums[j++];
        }
        
        for (i = st; i <= en; i++) {
            aug_nums[i] = temp[i];
        }
    }
    
    void mergeSortUtil(vector<pair<int, int> > &aug_nums, vector<pair<int, int> > &temp, vector<int> &ans, int st, int en) {
        if (st < en) {
            int mid = st+(en-st)/2;
            
            mergeSortUtil(aug_nums, temp, ans, st, mid);
            mergeSortUtil(aug_nums, temp, ans, mid+1, en);
            
            merge(aug_nums, temp, ans, st, mid, en);
        }
    }
    
public:
    vector<int> countSmaller(vector<int>& nums) {
        vector<pair<int, int> > temp(nums.size());
        vector<pair<int, int> > aug_nums(nums.size());
        for (int i = 0; i < nums.size(); i++) {
            aug_nums[i] = {nums[i], i};
        }
        vector<int> ans(nums.size(), 0);
        mergeSortUtil(aug_nums, temp, ans, 0, nums.size()-1);
        for (int i = 0; i < nums.size(); i++) {
            cout << aug_nums[i].first << " ";
        }
        cout << endl;
        return ans;
    }
};