#include <iostream>
#include <algorithm>
#include <vector>

bool compare(int a, int b)
{
    return a > b;
}

int main()
{
    long long int num_of_item = 0;
    std::cin >> num_of_item;
    std::vector<long long int> prices;
    for (int i = 0; i < num_of_item; i++)
    {
        int temp;
        std::cin >> temp;
        if (temp > num_of_item)
        {
            temp = num_of_item;
        }
        prices.push_back(temp);
    }
    std::sort(prices.begin(), prices.end());
    long long int ans = 1;
    for (long long int i = 0; i < num_of_item; i++)
    {
        if ((prices[i] - i) < 0)
        {
            ans = 0;
            break;
        }
        else
        {
            ans = (ans * ((prices[i] - i))) % (1000000000 + 7);
        }
        //ans *= prices[i] - i;
    }
    //ans = ans % (1000000000 + 7);
    std::cout << ans; 
    return 0;
}