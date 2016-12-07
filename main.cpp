#include <iostream>
#include <vector>
#include <climits>

class solution {
  public:
    std::vector<int> majorityElement(const std::vector<int> & nums) {
        // // brute force solution
        // auto minmax = std::minmax_element(nums.begin(), nums.end());
        // std::vector<int> buckets(*minmax.second-*minmax.first+1);
        // for (auto& n : nums) {
        //     buckets[n-*minmax.first]++;
        //     if (buckets[n-*minmax.first] > nums.size()/3)
        //         return n;
        // }

        // O(n) time and O(1) space solution
        int n1, n2;
	int count1 = 0, count2 = 0;
	for (size_t i = 0; i < nums.size(); i++) {
	    if (count1 == 0 && count2 == 0) {
		n1 = nums[i];
		count1++;
	    }
	    else if (count1 == 0 && count2 != 0) {
		if (nums[i] == n2)
		{
		    count2++;
		}
		else {
		    n1 = nums[i];
		    count1++;
		}
	    }
	    else if (count1 != 0 && count2 == 0){
		if (nums[i] == n1) {
		    count1++;
		    i++;
		}
		else {
		    n2 = nums[i];
		    count2++;
		}
	    }
	    else {
		if (nums[i] == n1) {
		    count1++;
		}
		else if (nums[i] == n2) {
		    count2++;
		}
		else {
		    count1--;
		    count2--;
		}
	    }
	}

	count1 = 0;
	count2 = 0;
	for (auto n : nums) {
	    if (n == n1)
		count1++;
	    if (n == n2)
		count2++;
	}
	std::cout << "n1 = " << n1 << ", n2 = " << n2 << std::endl;
	
	std::vector<int> result;
	if (count1 > nums.size()/3)
	    result.push_back(n1);
	if (count2 > nums.size()/3)
	    result.push_back(n2);

	return result;
    }
};

int main() {
    std::vector<int> nums{1,2,3,3,2,1,1,4};

    solution soln;
    auto major = soln.majorityElement(nums);
    std::copy(major.begin(), major.end(), std::ostream_iterator<int>(std::cout, " "));
    std::cout << std::endl;
}
