#include <iostream>
#include <vector>
#include <algorithm>
#define int long long
using namespace std;
vector<int> dataa;
int num_of_a = 0;
int num_of_b = 0;
int ans = 0;
signed main()
{
    int N;
    cin >> N;
    dataa.resize(N);
    for(int i = 0; i < N; i++)
    {
        int a, b, minuss;
        cin >> a >> b;
        if (a >= b)
        {
            minuss = a - b;
            num_of_b++;
            ans += b;
        }
        else
        {
            minuss = b - a;
            num_of_a++;
            ans += a;
        }
        dataa[i] = minuss;
    }
    sort(dataa.begin(), dataa.end());
    int ctr = 0;
    int change = 0;
    if (num_of_a >= num_of_b)
    {
        change = num_of_a - num_of_b;
    }
    else
    {
        change = num_of_b - num_of_a;
    }
    change = change / 2;
    for(int i = 0; i < change; i++)
    {
        ans += dataa[i];
    }
    printf("%d", ans);
    return 0;
}