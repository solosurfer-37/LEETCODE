void merge(int* nums, int start, int mid, int end) {
    int size = end - start + 1;
    int* temp = (int*)malloc(size * sizeof(int));
    if (!temp) return;

    int i = start;
    int j = mid + 1;
    int k = 0;

    while (i <= mid && j <= end) {
        if (nums[i] <= nums[j]) {
            temp[k++] = nums[i++];
        } else {
            temp[k++] = nums[j++];
        }
    }

    while (i <= mid) {
        temp[k++] = nums[i++];
    }
    while (j <= end) {
        temp[k++] = nums[j++];
    }

    for (int idx = 0; idx < size; idx++) {
        nums[start + idx] = temp[idx];
    }

    free(temp);
}

void mergeSort(int* nums, int start, int end) {
    if (start >= end) return;
    
    int mid = start + (end - start) / 2;
    mergeSort(nums, start, mid);
    mergeSort(nums, mid + 1, end);
    merge(nums, start, mid, end);
}

int* sortArray(int* nums, int numsSize, int* returnSize) {
    mergeSort(nums, 0, numsSize - 1);
    *returnSize = numsSize;
    return nums;
}