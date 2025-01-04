class Solution {
public:
    static const int MOD = 1e9 + 7;
    void merge_sort(vector<int> & instructions, vector<int> & orders, vector<int> & tmp, vector<int> & less_than, vector<int> & greater_than, int begin, int end) {
        if (begin >= end) return;
        int mid = begin + (end - begin) / 2;
        merge_sort(instructions, orders, tmp, less_than, greater_than, begin, mid);
        merge_sort(instructions, orders, tmp, less_than, greater_than, mid + 1, end);

        copy(orders.begin() + begin, orders.begin() + end + 1, tmp.begin() + begin);    
        int i = mid, j = end, k = begin;
        while (i >= begin) {
            if (j >= mid + 1 && instructions[tmp[j]] >= instructions[tmp[i]]) {
                greater_than[tmp[j]] += mid - i;
                greater_than[tmp[j]] %= MOD;
                j--;
            }
            else 
                i--;                
        }
        while (j >= mid + 1) {
            greater_than[tmp[j]] += mid - i;
            greater_than[tmp[j]] %= MOD;
            j--;
        }
        i = begin, j = mid + 1;
        while (i <= mid) {
            if (j <= end && instructions[tmp[j]] <= instructions[tmp[i]]) {                
                less_than[tmp[j]] += i - begin;
                less_than[tmp[j]] %= MOD;
                orders[k] = tmp[j];
                j++;
            }
            else {
                orders[k] = tmp[i];
                i++;  
            }
            k++;          
        }
        while (j <= end) {
            less_than[tmp[j]] += i - begin;
            less_than[tmp[j]] %= MOD;
            j++;
        }            
    }
    int createSortedArray(vector<int>& instructions) {
        vector<int> less_than(instructions.size()), greater_than(instructions.size()),
                    tmp(instructions.size());
        vector<int> orders;
        for (int i = 0; i < instructions.size(); i++) {
            orders.push_back(i);
        }
        merge_sort(instructions, orders, tmp, less_than, greater_than, 0, instructions.size() - 1);
        int ans = 0;
        for (int i = 0; i < instructions.size(); i++) {
            ans += min(less_than[i], greater_than[i]);
            ans %= MOD;
        }
        return ans;
    }
};