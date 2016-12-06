#include <iostream>
#include <vector>
#include <algorithm>

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
        
    }
};

int main() {
    
}
