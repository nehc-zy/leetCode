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

//只要考虑一个问题，要查找什么，最后left right停留的位置就是要查找的，没有就找不到
int Solution::binarySearch(std::vector<int>&nums, int target) {
	int left = 0;
	int right = nums.size() - 1;
	while (left <= right) {
		int mid = left + (right - left) >> 2;
		if (nums[mid] == target)return mid;
		else if (nums[mid] > target)right = mid - 1;
		else left = mid + 1;
	}
	return -1;
}    
//只要考虑一个问题，要找的是比target值大，但同时又比右边缘小，所以left==right时停在最边缘的target或者边缘target右边一个
std::vector<int> Solution::binarySearchEdge(std::vector<int>& nums, int target) {
	std::vector<int>res;
	int leftEdge = -1;
	int rightEdge = -1;
	int left = 0;
	int right = nums.size() - 1;
	while (left <= right) {
		//防止溢出
		//左边界
		int mid = left + ((right - left) >> 1);
		if (nums[mid] == target) {
			right = mid - 1;
			leftEdge = mid;
		}
		else if (nums[mid] < target)left = mid + 1;
		else right = mid - 1;
	}
	res.push_back(leftEdge);

	//右边界
	left = 0;
	right = nums.size() - 1;
	while (left <= right) {
		int mid = left + ((right - left) >> 1);
		if (nums[mid] == target) {
			left = mid + 1;
			rightEdge = mid;
		}
		else if (nums[mid] > target)right = mid - 1;
		else left = mid + 1;
	}
	res.push_back(rightEdge);
	return res;
}


//回溯是一种思想，dfs是实现回溯的一种载体，dfs是要遍历所有结果，所谓剪枝即通过某种逻辑提前不检索某种结果
//所有的回溯都要实现画出搜索树的图，以下为全排列的一种回溯方法
//时间复杂度我觉得是N！，实际是N*N！，存疑
void Solution::dfs(std::vector<int>& nums, int len, std::vector<bool>& used,std::vector<int>& path, std::vector<std::vector<int>>& res){
	if (path.size() == len) {
		res.push_back(path);
		return;
	}
	for (int i = 0; i < nums.size(); i++) {
		if (!used[i]) {
			path.push_back(nums[i]);
			used[i] = true;
			dfs(nums, len, used, path, res);
			path.pop_back();
			used[i] = false;
		}
	}
	return;

 }

int main() 
{
	std::vector<int> nums = {1,2,3};
	//std::vector<int> nums = { 0,0,0,0,0};
	//Solution::quickSort2(nums, 0, nums.size() - 1);
	//std::vector<int> res = Solution::binarySearchEdge(nums,8);
	//for (int i = 0; i < res.size(); i++) {
	//	std::cout << res[i] << std::endl;
	//}
	//求数组数字的全排列的回溯
	int len = nums.size();
	std::vector<bool> used(nums.size(), false);
	std::vector<int> path;
	std::vector<std::vector<int>> res;
	Solution::dfs(nums, len, used, path, res);
	system("pause");
	return 0;

}