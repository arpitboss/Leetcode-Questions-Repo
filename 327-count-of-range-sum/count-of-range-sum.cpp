class Solution {
private:
    int mergeSortAndCount(vector<long long>& prefixSum, int left, int right, int lower, int upper) {
        if (right - left <= 1) {
            return 0;
        }

        int mid = (left + right) / 2;
        int count = mergeSortAndCount(prefixSum, left, mid, lower, upper) +
                    mergeSortAndCount(prefixSum, mid, right, lower, upper);

        int i = left, j = mid, k = mid, l = mid;
        vector<long long> cache(right - left);
        int r = 0;

        for (; i < mid; ++i) {
            while (k < right && prefixSum[k] - prefixSum[i] < lower) k++;
            while (l < right && prefixSum[l] - prefixSum[i] <= upper) l++;

            count += l - k;

            while (j < right && prefixSum[j] < prefixSum[i]) {
                cache[r++] = prefixSum[j++];
            }
            cache[r++] = prefixSum[i];
        }
        copy(cache.begin(), cache.begin() + r, prefixSum.begin() + left);

        return count;
    }

public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        int n = nums.size();
        vector<long long> prefixSum(n + 1, 0);
        for (int i = 0; i < n; ++i) {
            prefixSum[i + 1] = prefixSum[i] + nums[i];
        }
        return mergeSortAndCount(prefixSum, 0, n + 1, lower, upper);
    }
};