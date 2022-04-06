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
		//���С�ڵ����ܱ�֤lowָ���λ����low==high����С�ڻ��ߵ��ڻ�׼��ֵ
		//����֮ǰ�н�����high�𽥼��٣�����low��������Сֵ������high�ҵ�һ��Сֵ��low���ң�����high��ָ��Сֵ
		//����֮ǰû������highֱ�ӵ�low��lowָ���ֵ���ڻ�׼ֵ
		//������Ϊ�˷�ֹ��׼ֵ������ȥ
		while (low < high && nums[low] <= temp)low++;
		//�����ж�lowС��high
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

//ֻҪ����һ�����⣬Ҫ����ʲô�����left rightͣ����λ�þ���Ҫ���ҵģ�û�о��Ҳ���
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
//ֻҪ����һ�����⣬Ҫ�ҵ��Ǳ�targetֵ�󣬵�ͬʱ�ֱ��ұ�ԵС������left==rightʱͣ�����Ե��target���߱�Եtarget�ұ�һ��
std::vector<int> Solution::binarySearchEdge(std::vector<int>& nums, int target) {
	std::vector<int>res;
	int leftEdge = -1;
	int rightEdge = -1;
	int left = 0;
	int right = nums.size() - 1;
	while (left <= right) {
		//��ֹ���
		//��߽�
		int mid = left + ((right - left) >> 1);
		if (nums[mid] == target) {
			right = mid - 1;
			leftEdge = mid;
		}
		else if (nums[mid] < target)left = mid + 1;
		else right = mid - 1;
	}
	res.push_back(leftEdge);

	//�ұ߽�
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


//������һ��˼�룬dfs��ʵ�ֻ��ݵ�һ�����壬dfs��Ҫ�������н������ν��֦��ͨ��ĳ���߼���ǰ������ĳ�ֽ��
//���еĻ��ݶ�Ҫʵ�ֻ�����������ͼ������Ϊȫ���е�һ�ֻ��ݷ���
//ʱ�临�Ӷ��Ҿ�����N����ʵ����N*N��������
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
	//���������ֵ�ȫ���еĻ���
	int len = nums.size();
	std::vector<bool> used(nums.size(), false);
	std::vector<int> path;
	std::vector<std::vector<int>> res;
	Solution::dfs(nums, len, used, path, res);
	system("pause");
	return 0;

}