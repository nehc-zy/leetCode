#pragma once
#include <vector>


/*******************************************************************
数据量规模和时间复杂度之间的关系
50000-O(n)
20000-O(nlogn)
1000-O(n^2)
30-O(n^4)
20-(2^n)
********************************************************************/
class Solution 
{
//长度为偶数，区间右端在中间偏左，长度为奇数，区间右端在中间,可以 数组标号<=(n-1)/2或者数组标号<(n+1)/2
//长度为偶数，区间右端在中间偏左，长度为奇数，区间右端在中间偏左，可以 数组标号<n / 2
public:
	//quickSort实现1
	static void quickSort(std::vector<int>& nums, int left, int right);
	//quickSort实现2
	static void quickSort2(std::vector<int>&nums, int left, int right);
	static void nextPermutation(std::vector<int>& nums);
	//二分查找
	static int binarySearch(std::vector<int>&nums, int target);
	//二分边缘查找
	static std::vector<int> binarySearchEdge(std::vector<int>& nums, int target);
	//回溯法
	static void dfs(std::vector<int>& nums, int len, std::vector<bool>& used, std::vector<int>& path, std::vector<std::vector<int>>& res);
	//合并区间整理
	//static void merge(std::vector<vector<int>>& nums);
};
