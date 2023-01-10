#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int location_num, edge_num, rumor_num;
int first_ans, second_ans;
vector<pair<int, pair<int, int> > > edge_list;
vector<pair<int, pair<int, int> > > rumors_edge_list;
vector<pair<int, pair<int, int> > > non_edge_list;

vector<int> non_rumor_list;
vector<int> rumors_list;

vector<int> parent;

bool cmp(int a, int b)
{
    return a > b;
}

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
    if (index_a == index_b)
    {
        return false;
    }
    parent[index_a] = parent[index_b];
    return true;
}

bool isThisRumor(int index)
{
    for (int i = 0; i < rumor_num; i++)
    {
        if (index == rumors_list[i])
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
        if (isThisRumor(edge_list[i].second.first) || isThisRumor(edge_list[i].second.second))
        {
            rumors_edge_list.push_back(edge_list[i]);
        }
        else
        {
            non_edge_list.push_back(edge_list[i]);
        }
    }
    return;
}

int firstMST()
{
    int edg = 0;
    int ans = 0;
    sort(edge_list.begin(), edge_list.end());
    for (int i = edge_num - 1; i >= 0; i--)
    {
        if(mergeTwo(edge_list[i].second.first, edge_list[i].second.second))
        {
            edg++;
            ans += edge_list[i].first;
        }
    }
    if ((location_num) - 1 > edg)
    {
        return -1;
    }
    return ans;
}

int secondMST()
{
    int ans = 0;
    for (int i = 0; i < rumors_edge_list.size(); i++)
    {
        ans += rumors_edge_list[i].first;
        mergeTwo(rumors_edge_list[i].second.first, rumors_edge_list[i].second.second);
    }
    sort(non_edge_list.begin(), non_edge_list.end());
    for (int i = 0; i < non_edge_list.size(); i++)
    {
        if (mergeTwo(non_edge_list[i].second.first, non_edge_list[i].second.second))
        {
            ans += non_edge_list[i].first;
        }
    }
    return ans;
}

int main()
{
    while(cin >> location_num >> edge_num >> rumor_num)
    {
        parent.clear();
        parent.resize(location_num);
        edge_list.clear();
        rumors_edge_list.clear();
        non_edge_list.clear();
        for (int i = 0; i < edge_num; i++)
        {
            int a, b, c;
            cin >> a >> b >> c;
            edge_list.push_back({c, {a, b}});
        }
        rumors_list.clear();
        rumors_list.resize(rumor_num);
        for (int i = 0; i < rumor_num; i++)
        {
            cin >> rumors_list[i];
        }
        for (int i = 0; i < location_num; i++)
        {
            parent[i] = i;
        }
        allToEachList();
        int ans_one = firstMST();
        if (ans_one == -1)
        {
            cout << "no\n";
            continue;
        }
        for (int i = 0; i < location_num; i++)
        {
            parent[i] = i;
        }
        int ans_two = secondMST();
        cout << ans_one - ans_two << "\n";
    }
    return 0;
}