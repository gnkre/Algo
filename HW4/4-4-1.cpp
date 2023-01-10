#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<pair<int, int>> dt;
int N;
bool cmp(pair<int, int> a, pair<int, int> b)
{
    if (a.second == b.second)
    {
        return a.first < b.first;
    }
    return a.second < b.second;
}
int main()
{
    cin >> N;
    int trash = 0;
    //dt.resize(N);
    for(int i = 0; i < N; i++)
    {
        int a, b;
        cin >> a;
        cin >> b;
        if (b > a)
        {
            dt.push_back(pair(a, b));
        }
    }
    sort(dt.begin(), dt.end(), cmp);
    int cursor = 0;
    int cur_end = 0;
    for (int i = 0; i < N; i++)
    {
        if (dt[i].second == dt[i + 1].second)
        {
            continue;
        }
        else
        {
            if (cur_end <= dt[i].first)
            {
                cout << dt[i].first << " " << dt[i].second << "\n";
                cur_end = dt[i].second;
            }
        }
    }
    return 0;
}