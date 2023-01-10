#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include <queue>

using namespace std;

vector<list<pair<int, int> > > adj_list;
vector<int> radioactive;
vector<int> shelter_list;
int location_num, road_num, shelter_num;



int Dijikstra(int source, vector<int> &destination_list)
{
    vector<bool> visited(location_num, false);
    vector<int> distance(location_num, INT32_MAX);

    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
    pq.push({radioactive[source], source});
    distance[source] = radioactive[source];
    
    while(pq.empty() == false)
    {
        int vrt = pq.top().second;
        pq.pop();
        if (visited[vrt])
        {
            continue;
        }
        for (auto i : adj_list[vrt])
        {
            int vertex = i.second;
            int wt = i.first;

            if (wt + radioactive[vertex] + distance[vrt] < distance[vertex])
            {
                distance[vertex] = wt + radioactive[vertex] + distance[vrt];
                pq.push({distance[vertex], vertex});
            }
        }
        visited[vrt] = true;
    }
    int ans = INT32_MAX;
    int no_count = 0;
    for (int i = 0; i < shelter_num; i++)
    {
        if (visited[shelter_list[i]] == false)
        {
            no_count++;
        }
        if (distance[shelter_list[i]] < ans)
        {
            ans = distance[shelter_list[i]];
        }
    }
    if (no_count == shelter_num)
    {
        return -1;
    }
    return ans;
}


int main()
{
    while(cin >> location_num >> road_num >> shelter_num)
    {
        radioactive.resize(location_num);
        adj_list.resize(location_num);
        shelter_list.resize(shelter_num);
        for (int i = 0; i < location_num; i++)
        {
            int idx;
            cin >> idx;
            radioactive[i] = idx;
        }
        for (int i = 0; i < road_num; i++)
        {
            int a, b, weight;
            cin >> a >> b >> weight;
            adj_list[a].push_back({weight, b});
            adj_list[b].push_back({weight, a});
        }
        for (int i = 0; i < shelter_num; i++)
        {
            int idx;
            cin >> idx;
            shelter_list[i] = idx; 
        }
        int source;
        cin >> source;
        int ans = Dijikstra(source, shelter_list);
        cout << ans << "\n";
        radioactive.clear();
        adj_list.clear();
        shelter_list.clear();
    }
    return 0;
}

