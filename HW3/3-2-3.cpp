#include <iostream>
int num_of_customer = 0;
int coin_data[30] = { 0 };
long long int price[100005] = { 0 };
int num_of_coin_kind = 0;
int ans_shit[100005] = { 0 };
int ans_[100005]= { 0 };
inline int minn(int a, int b)
{
    if (a > b)
        return b;
    else
        return a;

}
void make_the_dp_shit()
{
    for(int i = 1; i < 100005; i++)
    {
        ans_shit[i] = 99999999;
    }
    ans_shit[0] = 0;
    for(int i = 1; i < 100005; i++)
    {
        for(int j = 0; j < num_of_coin_kind; j++)
        {
            if (i >= coin_data[j])
            {
                ans_shit[i] = minn(ans_shit[i - coin_data[j]] + 1, ans_shit[i]);
            }
        }
    }
    return;
}

int main()
{
    scanf("%d", &num_of_coin_kind);
    for (int i = 0; i < num_of_coin_kind; i++)
    {
        scanf("%d", &coin_data[i]);
    }
    make_the_dp_shit();
    scanf("%d", &num_of_customer);
    for (int i = 0; i < num_of_customer; i++)
    {
        long long int pricee = 0;
        scanf("%lld", &pricee);
        long long int temp_shit = 0;
        int ans = 0;
        for(int j = 0; j < num_of_coin_kind; j++)
        {
            long long int temp_n = 0;
            scanf("%d", &temp_n);
            temp_shit = temp_shit + (temp_n * coin_data[j]);
        }
        ans = ans_shit[temp_shit - pricee];
        printf("%d\n", ans);
    }
    //for(int i = 0; i < num_of_customer; i++)
    //{
    //    printf("%d\n", ans_[i]);
    //}
    return 0;
}