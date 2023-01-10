#include <stdio.h>

//int revenue_data[20100] = { 0 };
//int prefix_sum_positive[20100] = { 0 };
//int prefix_sum_negative[20100] = { 0 };
int num_of_months = 0;

inline int exchangeShit(int a)
{
    return (-1 * a);
}

signed main()
{
    int P_max = -1000000;
    int P_min = 1000000;
    int P_last_shit = 0;
    int P_sum = 0;

    int N_max = -1000000;
    int N_min = 1000000;
    int N_last_shit = 0;
    int N_sum = 0;

    scanf("%d", &num_of_months);
    for (int i = 0; i < num_of_months; i++)
    {
        //scanf("%d", &revenue_data[i]);
        if (P_max < (P_sum))
        {
            P_max = P_sum;
        }
        if (P_min > (P_sum))
        {
            P_min = P_sum;
        }

        if (N_max < (N_sum))
        {
            N_max = N_sum;
        }
        if (N_min > (N_sum))
        {
            N_min = N_sum;
        }
        int temp;
        scanf("%d", &temp);
        P_sum = temp + P_sum;
        N_sum = exchangeShit(temp) + N_sum;
    }
    if (P_max < (P_sum))
    {
        P_max = P_sum;
    }
    if (P_min > (P_sum))
    {
        P_min = P_sum;
    }
    if (N_max < (N_sum))
    {
        N_max = N_sum;
    }
    if (N_min > (N_sum))
    {
        N_min = N_sum;
    }
    int P_ans = P_max - P_min;
    int N_ans = N_max - N_min;
    int ans;
    if (P_ans > N_ans)
    {
        ans = P_ans;
    }
    else
    {
        ans = N_ans;
    }
    printf("%d", ans);
    // make prefix pos
    return 0;
}