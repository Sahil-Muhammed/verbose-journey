#include <bits/stdc++.h>
void swap(int* a, int* b){
	int temp = *a;
	*a = *b;
	*b = temp;
}
void merge(int begin, int mid, int end, std::vector<int>& arr){
	int i = begin, j = mid+1;
	std::vector<int> final;
	int size1 = mid - begin + 1;
	int size2 = end - mid;
	std::vector<int> left, right;
	for (i = 0; i < size1; ++i){
		left.push_back(arr[begin + i]);
	}
	for (j = 0; j < size2; ++j){
		right.push_back(arr[mid + 1 + j]);
	}
	i = 0;
	j = 0;
	while (i < size1 && j < size2){
		if (left[i] < right[j]){
			final.push_back(left[i++]);	
		}
		else{
			final.push_back(right[j++]);
		}
	}
	while (i < size1){
		final.push_back(left[i++]);
	}
	while (j < size2){
		final.push_back(right[j++]);
	}
	std::cout << "Inside merge function with " << begin << " and " << end << std::endl;
	for (i = 0; i < size1 + size2; ++i){
		arr[i + begin] = final[i];
	}
}
void divide(int begin, int end, std::vector<int>& arr){
	if (begin >= end){
		std::cout << "All good folks!" << begin << " " << end << std::endl;
		return;
	}
	int mid = (begin + end) / 2;
	divide(begin, mid, arr);
	divide(mid+1, end, arr);
	merge(begin, mid, end, arr);
}
int main(){
	int n;
	std::cin >> n;
	std::vector<int> arr;
	int num = 1;
	for (int i = 0; i < n; ++i){
		std::cin >> num;
		arr.push_back(num);
	}
	std::cout << "before recusion call" << std::endl;
	divide(0, n-1, arr);
	for (int i = 0; i < n; ++i){
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;
	int a = 5;
	printf("%d %d %d\n", a++, ++a, a);
	return 0;
}
