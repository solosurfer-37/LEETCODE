void merge(int* nums, int low, int mid, int high) {
    int i = low;
    int j = mid + 1;
    int k = 0;
    int size = high - low + 1;
    int* arr = (int*)malloc(size * sizeof(int));

    while (i <= mid && j <= high) {
        if (nums[i] <= nums[j]) {
            arr[k++] = nums[i++];
        } else {
            arr[k++] = nums[j++];
        }
    }

    while (i <= mid) {
        arr[k++] = nums[i++];
    }

    while (j <= high) {
        arr[k++] = nums[j++];
    }

    for (int idx = 0; idx < size; idx++) {
        nums[low + idx] = arr[idx];
    }

    free(arr);
}

void sort(int* nums, int low, int high) {
    if (low >= high) return;
    int mid = low + (high - low) / 2;
    sort(nums, low, mid);
    sort(nums, mid + 1, high);
    merge(nums, low, mid, high);
}

int* sortArray(int* nums, int numsSize, int* returnSize) {
    *returnSize = numsSize;
    sort(nums, 0, numsSize - 1);
    return nums;
}