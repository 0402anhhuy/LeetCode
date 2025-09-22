#include <bits/stdc++.h>
using namespace std;

int minElement(vector<int> &nums)
{
    int ans = 1001;
    for (int num : nums)
    {
        int sum = 0;
        while (num != 0)
        {
            sum += (num % 10);
            num /= 10;
        }
        if (ans > sum)
            ans = sum;
    }
    return ans;
}

int main()
{
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    int result = minElement(nums);
    cout << result;
    return 0;
}