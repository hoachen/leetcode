/*
 * [3,4,5, 1, 2] 
 * [1, 1, 0, 1, 1]
 * 两个有序序列，利用有序的特性进行二分快速查找
*/

#include <iostream>
using namespace std;

// 顺序遍历查出最小元素
int OrderFindMin(int *nums, int index1, int index2) {
    int result = nums[index1];
    for (int i = index1 + 1; i < index2 ; i++) {
        if (result > nums[i])
            result = nums[i];
    }
    return result;
}

int findMin(int *nums, int length) {
    int index1 = 0;
    int index2 = length - 1;
    int indexMid = index1;
    while(nums[index1] >= nums[index2]) {
        if (index2 - index1 == 1) {
            indexMid = index2;
            break;
        }
        indexMid = (index1 + index2) / 2;
        if (nums[index1] == nums[index2] && nums[index1] == nums[indexMid]) {
            return OrderFindMin(nums, index1, index2);
        }
        if (nums[indexMid] >= nums[index1]) {
            index1 = indexMid;
        } else if (nums[indexMid] <= nums[index2]) {
            index2 = indexMid;
        }
    }
    return nums[indexMid];
}

int main(int argc, char *args[]) {
    int nums[] = {5, 4, 3, 1, 2};
    int min = findMin(nums, 5);
    cout << min << endl;
    int nums2[] = {1, 1, 0, 1, 1};
    int min2 = findMin(nums2, 5);
    cout << min2 << endl;
    return 0;
}