#include <iostream>
#include <vector>
#include <algorithm>
#define int long long
using namespace std;

vector<int> arr;
int N;
int L, R;
int ans = 0;

signed main()
{
    scanf("%lld", &N);
    arr.resize(N);
    scanf("%lld", &L);
    scanf("%lld", &R);
    for (int i = 0 ; i < N; i++)
    {
        scanf("%lld", &arr[i]);
    }
    std::sort(arr.begin(), arr.end());
    for (int i = 0; i < N - 1; i++)
    {
        vector<int>::iterator low, up;
        int expected_left = (L / arr[i]);
        if (L % arr[i] > 0)
        {
            expected_left++;
        }
        int expected_right = R / arr[i] ;
        low = lower_bound(arr.begin() + i + 1, arr.end(), expected_left);
        up = upper_bound(arr.begin() + i + 1, arr.end(), expected_right) - 1;
        int len = up - low + 1;
        ans += len;
    }
    printf("%lld", ans);
    return 0;
}