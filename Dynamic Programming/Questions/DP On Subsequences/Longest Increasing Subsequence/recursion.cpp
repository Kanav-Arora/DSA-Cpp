#include <iostream>
#include <vector>
using namespace std;

class Solution
{
private:
    int solver(vector<int> &nums, int i, int prev)
    {
        if (i < 0)
            return 0;
        int dont = solver(nums, i - 1, prev);
        int pick = 0;
        if (prev == -1 || nums[i] < nums[prev])
            pick = 1 + solver(nums, i - 1, i);
        return max(pick, dont);
    }

public:
    int lengthOfLIS(vector<int> &nums)
    {
        int n = nums.size();
        return solver(nums, n - 1, -1);
    }
};

int main()
{

    return 0;
}