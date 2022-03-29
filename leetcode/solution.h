#pragma once
#include <vector>
class Solution 
{
public:
	//quickSort实现1
	static void quickSort(std::vector<int>& nums, int left, int right);
	//quickSort实现2
	static void quickSort2(std::vector<int>&nums, int left, int right);
	static void nextPermutation(std::vector<int>& nums);
};
