#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> arr;
int N = 0;
int ans = 0;
int T = 0;

void check(int level, int cur, int idx)
{
    if (level == 4 && cur == T)
    {
        ans++;
        return;
    }
    else if (level == 4)
    {
        return;
    }
    for(int i = idx; i < N; i++)
    {
        if (i > idx && arr[i] == arr[i - 1])
        {
            continue;
        }
        check(level + 1, cur + arr[i], i + 1);
    }
}

int main()
{
    cin >> N;
    cin >> T;
    arr.resize(N);
    //int* arr = new int[N];
    for(auto& i: arr)
    {
        cin >> i;
    }
    sort(arr.begin(), arr.end());
    check(0, 0, 0);
    if (ans > 0)
    {
        cout << ans;
    }
    else
    {
        printf("FeiDooDoo_Zuo_Wei_Men");
    }
    return 0;
}