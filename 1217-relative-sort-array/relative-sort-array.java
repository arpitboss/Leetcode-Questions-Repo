class Solution {
    public int[] relativeSortArray(int[] arr1, int[] arr2) {
        int maxi=0;
        for (int i:arr1) {
            maxi=Math.max(maxi,i);
        }

        int[] countArray = new int[maxi+1];

        for (int i:arr1) {
            countArray[i]++;
        }

        int[] ans = new int[arr1.length];
        int k=0;
        for (int i=0;i<arr2.length;i++) {
            while (countArray[arr2[i]]>0) {
                ans[k]=arr2[i];
                k++;
                countArray[arr2[i]]--;
            }
        }

        for (int i=0;i<countArray.length;i++) {
            while (countArray[i]>0) {
                ans[k]=i;
                k++;
                countArray[i]--;
            }
        }
        return ans;
    }
}