#include <stdio.h>
int cost_of_level[26000] = { 0 };
int min_shit[26000] = { 0 };
int num_of_levels = 0;

int min(int a, int b)
{
    if (a < b)
    {
        return a;
    }
    return b;
}

void fillThatMinShit(int index_of_level)
{
    if (index_of_level == 0 || index_of_level == 1)
    {
        min_shit[index_of_level] = cost_of_level[index_of_level];
        fillThatMinShit(index_of_level + 1);
    }
    min_shit[index_of_level] = min(min_shit[index_of_level - 1], min_shit[index_of_level - 2]) + cost_of_level[index_of_level];
    if (index_of_level > num_of_levels + 1)
    {
        return;
    }
    fillThatMinShit(index_of_level + 1);
    return;
}

signed main()
{
    scanf("%d", &num_of_levels);
    for(int i = 0; i < num_of_levels; i++)
    {
        scanf("%d", &cost_of_level[i]);
    }
    fillThatMinShit(0);
    //int ans = min(min_shit[num_of_levels], min_shit[num_of_levels + 1]);
    printf("%d", min_shit[num_of_levels]);
    return 0;
}