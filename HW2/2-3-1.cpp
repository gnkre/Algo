#include <vector>
#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <cassert>
#include <numeric>
#include <functional>
#include <cstdlib>
using namespace std;

struct NegDefaultInt
{
    int num = -1;
};
unordered_map<pair(int, int), NegDefaultInt> cost_of_making_GS;
unordered_map<pair(int, int), NegDefaultInt> cost_of_making_all_elements_same;
vector<int> array;
int N;

void fillNecessaryBoxes(int l, int r)
{
    if ((r - l) <= 1)
    {
        cost_of_making_GS[{l, r}] = 0;
        return;
    }
    int middle = (l + r) / 2;
    int m = (r - l) / 2;
    if (cost_of_making_GS[{l, middle}] == -1)
    {
        fillNecessaryBoxes(l, middle);
    }
    if (cost_of_making_all_elements_same[{middle + 1, r}] == -1)
    {
        vector<int> temp(r - middle);
        for(int i = 0; i < r - middle; i++)
        {
            temp[i] = array[middle + 1 + i];
        }
        std::nth_element(temp.begin(), temp.begin() + (temp.size() / 2), temp.end());
        int sum = 0;
        for(int i = 0; i < r - l; i++)
        {
            sum += abs(temp[i] - temp[temp.size() / 2]);
        }
        cost_of_making_all_elements_same[{middle + 1, r}] = sum;
    }
    if (cost_of_making_GS[{middle + 1, r}] == -1)
    {
        fillNecessaryBoxes(middle + 1, r);
    }
    if (cost_of_making_all_elements_same[{l, middle}] == -1)
    {
        vector<int> temp(middle - l + 1);
        for(int i = 0; i < middle - l + 1; i++)
        {
            temp[i] = array[l + i];
        }
        std::nth_element(temp.begin(), temp.begin() + (temp.size() / 2), temp.end());
        int sum = 0;
        for(int i = 0; i < r - l; i++)
        {
            sum += abs(temp[i] - temp[(r - middle) / 2]);
        }
        cost_of_making_all_elements_same[{l, middle}] = sum;
    }
    cost_of_making_GS[{l, r}] = min((cost_of_making_GS[{l, middle}] + cost_of_making_all_elements_same[{middle + 1, r}]), cost_of_making_all_elements_same[{l, middle}] + cost_of_making_GS[{middle + 1, r}]);
    return;
}

int main()
{
    scanf("%d", &N);
    array.resize(N);
    for(int i = 0; i < N; i++)
    {
        scanf("%d", &array[N]);
    }
    fillNecessaryBoxes();
    printf("%d", cost_of_making_GS[{0, N - 1}]);
    return 0;
}