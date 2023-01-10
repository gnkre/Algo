#include <iostream>
#include <algorithm>
using namespace std;
int dp[2][20005] = { 0 };
int arr[20005] = { 0 };
int sorted_arr[20005] = { 0 };
int sorted_sub_shit[20005] = { 0 };
int len_of_arr = 0;
int len_of_sorted_arr = 0;
int len_of_pre_sorted_arr = 0;

int main()
{
    scanf("%d", &len_of_arr);
    for (int i = 0; i < len_of_arr; i++)
    {
        int temp_shit;
        scanf("%d", &temp_shit);
        arr[i] = temp_shit;
        sorted_arr[i] = temp_shit;
    }
    std::sort(&sorted_arr[0], &sorted_arr[len_of_arr]);
    int pre_shit = -87;
    for (int i = 0; i < len_of_arr; i++)
    {
        if (sorted_arr[i] != pre_shit)
        {
            sorted_sub_shit[len_of_pre_sorted_arr] = sorted_arr[i];
            len_of_pre_sorted_arr++;
        }
        pre_shit = sorted_arr[i];
    }
    for (int i = 0 ; i < len_of_arr; i++)
    {
        dp[0][i] = 0;
    }
    dp[1][0] = 0;
    for (int i = 1; i <= len_of_pre_sorted_arr; i++)
    {
        dp[(i % 2)][0] = 0;
        for (int j = 1; j <= len_of_arr; j++)
        {
            if (arr[j - 1] == sorted_sub_shit[i - 1])
            {
                dp[(i % 2)][j] = dp[((i - 1) % 2)][j - 1] + 1;
            }
            else
            {
                dp[(i % 2)][j] = max(dp[((i - 1) % 2)][j],dp[(i % 2)][j - 1]);
            }
        }
    }
    int ans = max(dp[0][len_of_arr], dp[1][len_of_arr]);
    printf("%d", ans);
    return 0;
}