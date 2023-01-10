#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;

int lines;
vector<string> name_list;
vector<vector<int> > adj_list;
int idx = 0;
void Yoo()
{
    for (int i = 1; i <= idx; i++)
    {
        for (int j = 1; j <= idx; j++)
        {
            for (int k = 1; k <= idx; k++)
            {
                int temp = adj_list[j][i] + adj_list[i][k];
                if (temp < adj_list[j][k])
                {
                    adj_list[j][k] = temp;
                    adj_list[k][j] = temp;
                }
            }
        }
    }
    return;
}

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    while (cin >> lines)
    {
        adj_list.clear();
        adj_list.resize(505, vector<int>(505, 888888));
        name_list.clear();
        map<string, int> person;
        idx = 0;
        for (int i = 0; i < lines; i++)
        {
            string name_a, name_b;
            cin >> name_a >> name_b;
            if (person[name_a] == 0)
            {
                idx++;
                name_list.push_back(name_a);
                person[name_a] = idx;
            }
            if (person[name_b] == 0)
            {
                idx++;
                name_list.push_back(name_b);
                person[name_b] = idx;
            }
            int index_a, index_b;
            index_a = person[name_a];
            index_b = person[name_b];
            adj_list[index_a][index_b] = 1;
            adj_list[index_b][index_a] = 1;
        }
        Yoo();
        int ans = 0;
        bool end = 0;
        for (int i = 1; i <= idx; i++)
        {
            if (end) break;
            for (int j = 1; j <= idx; j++)
            {
                if (i != j && adj_list[i][j] == 888888)
                {
                    ans = -1;
                    end = 1;
                    continue;
                }
                if (i != j && adj_list[i][j] != 888888 && ans != -1)
                {
                    ans = max(ans, adj_list[i][j]);
                }
            }
        }
        cout << ans << "\n";
        person.clear();
    }
    return 0;
}
