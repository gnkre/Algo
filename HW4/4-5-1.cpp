#include <iostream>
using namespace std;
bool price[1000000000];
int N;
int k;
long long ans = 0;
int main()
{
    scanf("%d", &N);
    for (int i = 0 ; i < N; i++)
    {
        int temp;
        scanf("%d", &temp);
        price[temp] = true;
    }
    scanf("%d", &k);
    for(long long int i = 1; i < 9223372036854775807; i++)
    {
        if (i < 1000000000)
        {
            if (price[i] == false)
            {
                ans += i;
                k--;
            }
        }
        else
        {
            ans += i;
            k--;
        }
        if (k == 0)
        {
            break;
        }
    }
    printf("%lld", ans);
    return 0;
}