class Solution {
public:
    void merge(vector<pair<int, int>>& arr, int p, int q, int r, vector<int>& count) {
        int n1 = q - p + 1;
        int n2 = r - q;

        vector<pair<int,int>> L(n1);
        vector<pair<int,int>> R(n2);

        for (int i = 0; i < n1; i++) 
            L[i] = arr[p + i];
        for (int i = 0; i < n2; i++) 
            R[i] = arr[q + 1 + i];

        int i = 0, j = 0, k = p;

        while (i < n1 && j < n2) {
            if (L[i].first <= R[j].first) {
                arr[k] = R[j];
                j++;
            } else {
                count[L[i].second]+=(n2-j);
                arr[k] = L[i];
                i++;
            }
            k++;
        }

        while (i < n1) {
            arr[k] = L[i];
            i++;
            k++;
        }

        while (j < n2) {
            arr[k] = R[j];
            j++;
            k++;
        }
    }

    void mergeSort(vector<pair<int, int>>& arr, int l, int r, vector<int>& count) {
        if (l < r) {
            int m = l + (r - l) / 2;

            mergeSort(arr, l, m, count);
            mergeSort(arr, m + 1, r, count);
            merge(arr, l, m, r, count);
        }
    }

    vector<int> countSmaller(vector<int>& nums) {
        vector<int> count(nums.size(), 0);
        vector<pair<int, int>> arr;
        for (int i=0;i<nums.size();i++) {
            arr.push_back({nums[i],i});
        }
        mergeSort(arr,0,nums.size()-1,count);
        return count;
    }
};
