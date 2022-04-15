int findDuplicate(int* nums, int numsSize){
    int set[100001] = {0, };
    
    for (size_t i = 0; i < numsSize; i++) {
        if (set[nums[i]] == 1) {
            return nums[i];
        }
        set[nums[i]] = 1;
    }
    
    return -1;
}
