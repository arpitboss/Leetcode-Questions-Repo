class Solution {
public:
    void merge(vector<pair<int,int>> &arr, int p, int q, int r, vector<int> &count) {
      vector<pair<int,int>> tmp(r-p+1);
      int i = p, j = q+1, k = 0;
      
      while (i <= q && j <= r) {
        if (arr[i].first <= arr[j].first) {
          tmp[k] = arr[j];
          j++;
        } else {
          count[arr[i].second]+=(r-j+1);
          tmp[k] = arr[i];
          i++;
        }
        k++;
      }
      
      while (i <= q) {
        tmp[k] = arr[i];
        i++;
        k++;
      }
      
      while (j <= r) {
        tmp[k] = arr[j];
        j++;
        k++;
      }
      for (int l=p;l<=r;l++) {
        arr[l]=tmp[l-p];
      }
    }
    
    void mergeSort(vector<pair<int,int>> &arr, int l, int r, vector<int> &count) {
      if (l >= r) {
        return;
      }
      int m = l + (r - l) / 2;
        
        mergeSort(arr, l, m, count);
        mergeSort(arr, m + 1, r, count);
        merge(arr, l, m, r, count);
    }
    vector<int> countSmaller(vector<int>& nums) {
        vector<int> v(nums.size(),0);
        vector<pair<int,int>> arr;
        for (int i=0;i<nums.size();i++) {
            arr.push_back({nums[i],i});
        }
        mergeSort(arr,0,nums.size()-1,v);
        return v;
    }
};