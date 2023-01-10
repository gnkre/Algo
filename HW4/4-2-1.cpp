#include <iostream>
int num_of_level;
int dataa[25005];
int dp[25005];
int return_min(int a, int b)
{
    if (a > b)
        return b;
    else
        return a;
}
int do_shit()
{
    for(int i = 1; i < num_of_level; i++)
    {
        dp[i] = INT32_MAX;
    }
    for(int i = 0; i < num_of_level; i++)
    {
        for(int j = 0; j <= dataa[i]; j++)
        {
            dp[i + j] = return_min(dp[i + j], dp[i] + 1);
        }
    }
    return dp[num_of_level - 1];
}

int main()
{
    scanf("%d", &num_of_level);
    for(int i = 0; i < num_of_level; i++)
    {
        scanf("%d", &dataa[i]);
    }
    int ans = do_shit();
    printf("%d", ans);
}