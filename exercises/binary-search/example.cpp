#include "binary_search.h"

int binary_search::find(const std::vector<int>& arr, int val) {
	int low = 0;
	int high = arr.size() - 1;
	
	while (low <= high) {
		int mid = (static_cast<unsigned int>(low) + static_cast<unsigned int>(high)) >> 1;
		int key = arr[mid];

		if (key < val) {
			low = mid + 1;
		}
		else if (key > val) {
			high = mid - 1;
		}
		else {
			return mid;
		}
	}

	return -1;
}