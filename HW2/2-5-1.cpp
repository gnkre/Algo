#include <iostream>
#include <vector>
#include <algorithm>
#define int long long
using namespace std;

int A, B, n, k;
vector<int> where_is_the_building;

int get_that_min_shit(int left, int right, int region_left, int building_left)
{
    if (building_left == 0)
    {
        return A;
    }
    else if (right == left)
    {
        return B * 1 * building_left;
    }
    int middle_index = ((right - left) / 2) + left;
    int left_buildings_left = 0;
    int right_buildings_left = 0;
    //for(int i = 0; i < k; i++)
    //{
    //    if (where_is_the_building[i] >= left && where_is_the_building[i] <= middle_index)
    //    {
    //        left_buildings_left++;
    //    }
    //    if (where_is_the_building[i] >= (middle_index + 1) && where_is_the_building[i] <= right)
    //    {
    //        right_buildings_left++;
    //    }
    //}
    vector<int>::iterator up;
    vector<int>::iterator down;

    down = lower_bound(where_is_the_building.begin(), where_is_the_building.end(), left);
    up = upper_bound(where_is_the_building.begin(), where_is_the_building.end(), middle_index) - 1;
    left_buildings_left = up - down + 1;

    down = lower_bound(where_is_the_building.begin(), where_is_the_building.end(), middle_index + 1);
    up = upper_bound(where_is_the_building.begin(), where_is_the_building.end(), right) - 1;
    right_buildings_left = up - down + 1;

    int left_min_cost = get_that_min_shit(left, middle_index, middle_index - left + 1, left_buildings_left);
    int right_min_cost = get_that_min_shit(middle_index + 1, right, right - (middle_index + 1) + 1, right_buildings_left);
    int ans = min(B * region_left * building_left, (right_min_cost + left_min_cost));
    return ans;
}

signed main()
{
    scanf("%lld", &n);
    scanf("%lld", &k);
    scanf("%lld", &A);
    scanf("%lld", &B);
    where_is_the_building.resize(k);
    for(int i = 0 ; i < k; i++)
    {
        scanf("%d", &where_is_the_building[i]);
        where_is_the_building[i]--;
    }
    sort(where_is_the_building.begin(), where_is_the_building.end());
    int ans = get_that_min_shit(0, n - 1, n, k);
    printf("%lld", ans);
    return 0;
}