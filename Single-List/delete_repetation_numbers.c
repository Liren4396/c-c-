// 前一个是找到重复的后，直接把数组从重复的位置之后左移一个
// 后一个是用类似快慢指针的方法，如果两个数不相等，直接把那个快指针的值赋值给慢指针之后的一个地址

// O(n^2)
int removeDuplicates(int* nums, int numsSize){
    int curr = 0;
    int next = 1;
    while (next < numsSize) {
        if (nums[curr] == nums[next]) {
            for (int i = next; i < numsSize; i++) {
                nums[i - 1] = nums[i];
            }
            numsSize--;
        } else {
            curr++;
            next++;
        }
    }
    return numsSize;
}

// O(n)
// 
int removeDuplicates(int* nums, int numsSize){
    int curr = 0;
    int next = 1;
    while (next < numsSize) {
        if (nums[curr] != nums[next]) {
            nums[++curr] = nums[next];
        }
        next++;
    }
    return curr + 1;
}
