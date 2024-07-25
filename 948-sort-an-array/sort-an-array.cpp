class Solution {
public:
    void merge(vector<int>& nums, int low, int mid, int high){
        int n1 = mid - low + 1;
        int n2 = high - mid;
        vector<int>l1(n1);
        vector<int>l2(n2);

        for(int i=0;i<n1;i++){
            l1[i] = nums[low+i];
        }
        for(int i=0;i<n2;i++){
            l2[i] = nums[mid+i+1];
        }

        int i=0, j=0, k=low;
        while(i<n1 && j<n2){
            if(l1[i] < l2[j]){
                nums[k] = l1[i];
                i++;
                k++;
            }
            else{
                nums[k] = l2[j];
                j++;
                k++;
            }
        }

        while(i < n1){
            nums[k] = l1[i];
            i++;
            k++;
        }
        while(j < n2){
            nums[k] = l2[j];
            j++;
            k++;
        }
    }

    void mergeSort(vector<int>& nums, int low, int high){
        if(low < high){
            int mid = low + (high - low)/2;
            mergeSort(nums, low, mid);
            mergeSort(nums, mid+1, high);
            merge(nums, low, mid, high);
        }
    }
    vector<int> sortArray(vector<int>& nums) {
        mergeSort(nums, 0, nums.size()-1);
        return nums;
    }
};