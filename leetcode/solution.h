#pragma once
#include <vector>


/*******************************************************************
��������ģ��ʱ�临�Ӷ�֮��Ĺ�ϵ
50000-O(n)
20000-O(nlogn)
1000-O(n^2)
30-O(n^4)
20-(2^n)
********************************************************************/
class Solution 
{
//����Ϊż���������Ҷ����м�ƫ�󣬳���Ϊ�����������Ҷ����м�,���� ������<=(n-1)/2����������<(n+1)/2
//����Ϊż���������Ҷ����м�ƫ�󣬳���Ϊ�����������Ҷ����м�ƫ�󣬿��� ������<n / 2
public:
	//quickSortʵ��1
	static void quickSort(std::vector<int>& nums, int left, int right);
	//quickSortʵ��2
	static void quickSort2(std::vector<int>&nums, int left, int right);
	static void nextPermutation(std::vector<int>& nums);
	//���ֲ���
	static int binarySearch(std::vector<int>&nums, int target);
	//���ֱ�Ե����
	static std::vector<int> binarySearchEdge(std::vector<int>& nums, int target);
	//���ݷ�
	static void dfs(std::vector<int>& nums, int len, std::vector<bool>& used, std::vector<int>& path, std::vector<std::vector<int>>& res);
	//�ϲ���������
	//static void merge(std::vector<vector<int>>& nums);
};
