#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int location_num;
int outpost_num;
int edge_num;

vector<pair<int, pair<int, int> > > all;
vector<pair<int, pair<int, int> > > edge_list_non;
vector<pair<int, pair<int, int> > > edge_list_outpost;
vector<int> outpost_list;
vector<int> parent;
vector<int> ranking;

int find(int index)
{
    if (index != parent[index])
    {
        parent[index] = find(parent[index]);
    }
    return parent[index];
}

bool mergeTwo(int a, int b)
{
    int index_a = find(a);
    int index_b = find(b);
    if (index_a == index_b) return false;
    //if(ranking[index_a] > ranking[index_b])
    //{
    //    swap(index_a, index_b);
    //}
    //parent[index_a] = index_b;
    //ranking[index_b] += ranking[index_a];
    parent[index_a] = parent[index_b];
    return true;
}

inline bool isThisOutpost(int index)
{
    for(int i = 0 ; i < outpost_num; i++)
    {
        if (index == outpost_list[i])
        {
            return true;
        }
    }
    return false;
}

void allToEachList()
{
    for (int i = 0; i < edge_num; i++)
    {
        if (isThisOutpost(all[i].second.first) || isThisOutpost(all[i].second.second))
        {
            edge_list_outpost.push_back(all[i]);
        }
        else
        {
            edge_list_non.push_back(all[i]);
        }
    }
    return;
}

int FirstMST()
{
    int edg = 0;
    int ans = 0;
    sort(edge_list_non.begin(), edge_list_non.end());
    for(int i = 0; i < edge_list_non.size(); i++)
    {
        if (mergeTwo(edge_list_non[i].second.first, edge_list_non[i].second.second))
        {
            ans += edge_list_non[i].first;
            edg++;
        }
    }
    if ((location_num - outpost_num) - 1 > edg)
    {
        return -1;
    }
    return ans;
}

int secondMST(int ans)
{
    int edg = 0;
    ans = 0;
    sort(edge_list_outpost.begin(), edge_list_outpost.end());
    //sort(all.begin(), all.end());
    for(int i = 0; i < edge_list_non.size(); i++)
    {
        if (mergeTwo(edge_list_non[i].second.first, edge_list_non[i].second.second))
        {
            ans += edge_list_non[i].first;
            edg++;
        }
    }
    for(int i = 0; i < edge_list_outpost.size(); i++)
    {
        if (mergeTwo(edge_list_outpost[i].second.first, edge_list_outpost[i].second.second))
        {
            ans += edge_list_outpost[i].first;
            edg++;
        }
    }
    if ((location_num - 1) > edg)
    {
        return -1;
    }
    return ans;
}

int main()
{
    while(cin >> location_num >> edge_num >> outpost_num)
    {
        all.clear();
        edge_list_non.clear();
        edge_list_outpost.clear();
        for (int i = 0; i < edge_num; i++)
        {
            int a, b, c;
            cin >> a >> b >> c;
            all.push_back({c, {a, b}});
        }
        outpost_list.clear();
        outpost_list.resize(outpost_num);
        for(int i = 0; i < outpost_num; i++)
        {
            cin >> outpost_list[i];
        }
        ranking.clear();
        ranking.resize(location_num, 1);
        parent.clear();
        parent.resize(location_num);
        for(int i = 0; i < location_num; i++)
        {
            parent[i] = i;
        }
        allToEachList();
        int ans = FirstMST();
        if (ans == -1)
        {
            cout << -1 << "\n";
            continue;
        }
        for (int i = 0; i < location_num; i++)
        {
            parent[i] = i;
        }
        ans = secondMST(ans);
        if (ans == -1)
        {
            cout << -1 << "\n";
        }
        else
        {
            cout << ans << "\n";
        }
    }
    return 0;
}