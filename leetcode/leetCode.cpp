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
		while (low < high && nums[low] < temp)low++;
		nums[high] = nums[low];
	}
	nums[low] = temp;
	quickSort(nums, left, low - 1);
	quickSort(nums, low + 1, right);
	return;
}

void Solution::quickSort2(std::vector<int>& nums, int left, int right) {
	if (left >= right)return;
	int temp = nums[left];
	int low = left;
	int high = right;
	while (low < high) {
		while (low < high && nums[high] >= temp)high--;
		//这个小于等于能保证low指向的位置在low==high都是小于或者等于基准的值
		//假设之前有交换，high逐渐减少，碰到low，所以是小值，或者high找到一个小值，low向右，碰到high，指向小值
		//假设之前没交换，high直接到low，low指向的值等于基准值
		//等于是为了防止基准值到后面去
		while (low < high && nums[low] <= temp)low++;
		//不用判断low小于high
		std::swap(nums[low], nums[high]);
		
	}
	std::swap(nums[left], nums[low]);
	quickSort2(nums, left, low - 1);
	quickSort2(nums, low + 1, right);
	return;
}


void Solution::nextPermutation(std::vector<int>& nums) {
	for (int i = nums.size() - 1; i >= 0; i--) {
		for (int j = i - 1; j >= 0; j--) {
			if (nums[i] > nums[j]) {
				std::swap(nums[i], nums[j]);
				std::reverse(nums.begin() + i, nums.end());
				return;
			}
		}
	}
	std::reverse(nums.begin(), nums.end());
	return;
}

int main() 
{
	std::vector<int> nums = {2,3,1};
	//std::vector<int> nums = { 0,0,0,0,0};
	//Solution::quickSort2(nums, 0, nums.size() - 1);
	Solution::nextPermutation(nums);
	for (int i = 0; i < nums.size(); i++) {
		std::cout << nums[i] << std::endl;
	}
	system("pause");
	return 0;

}