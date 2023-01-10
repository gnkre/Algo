#include <vector>
#include <algorithm>
#include <iostream>
#include <cassert>
#include <numeric>
#include <functional>
#include <cstdlib>
#define int long long
using namespace std;

int arr[2000000] = {0};
int N;

int same(int left, int right)
{
    int len = right - left + 1;
    vector<int> temp(len);
    for(int i = 0; i < len; i++)
    {
        temp[i] = arr[left + i];
    }
    std::nth_element(temp.begin(), temp.begin() + ((len - 1) / 2), temp.begin() + len);
    int ans = 0;
    for(int i = 0; i < len; i++)
    {
        ans = abs(temp[i] - temp[(len - 1) / 2]) + ans;
    }
    temp.clear();
    return ans;
}

int cost(int left, int right)
{
    int len = right - left + 1;
    if (len <= 2)
    {
        return 0;
    }
    int middle = left + ((len - 1) / 2);
    int left_good = cost(left, middle);
    int right_good = cost(middle + 1, right);
    int ans = min(left_good + same(middle + 1, right), same(left, middle) + right_good);
    return ans;
}

signed main()
{
    cin >> N;
    for(int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }
    int ans = cost(0, N - 1);
    printf("%lld", ans);
    return 0;
}