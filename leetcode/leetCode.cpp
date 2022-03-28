#include "solution.h"
#include <iostream>

void Solution::quickSort(std::vector<int>& nums, int left, int right) {
	if (left >= right)return;
	int low = left;
	int high = right;
	int temp = nums[low];
	while (low < high) {
		while (low < high && nums[high] >= temp)high--;
		nums[low] = nums[high];
		if (low < high)low++;
		while (low < high && nums[low] < temp)low++;
		nums[high] = nums[low];
		if (low < high)high--;
	}
	nums[low] = temp;
	quickSort(nums, left, low - 1);
	quickSort(nums, low + 1, right);
	return;
}


int main() 
{
	//std::vector<int> nums = { -1,0,1,2,-1,-4 };
	std::vector<int> nums = { 0,0,0,0,0};
	Solution::quickSort(nums, 0, nums.size() - 1);
	for (int i = 0; i < nums.size() - 1; i++) {
		std::cout << nums[i] << std::endl;
	}
	return 0;

}