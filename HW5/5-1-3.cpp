#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

vector<std::string> the_fucking_map;
int how_many_maps;
int how_big_the_map_is;
int the_range_of_landing;
int temp_area_data;



void floodAllOverYouCan(int x, int y)
{
    if(x < 0 || y < 0 || x >= how_big_the_map_is || y >= how_big_the_map_is || the_fucking_map[y][x] == '^')
    {
        return;
    }
    queue<pair<int, int>> the_queue;
    temp_area_data++;
    the_fucking_map[y][x] = '^';
    the_queue.push({x, y});

    while (the_queue.size() > 0)
    {
        pair<int, int> pos = the_queue.front();
        the_queue.pop();

        int x = pos.first;
        int y = pos.second;
        if(!(x + 1 < 0 || y < 0 || x + 1 >= how_big_the_map_is || y >= how_big_the_map_is) && the_fucking_map[y][x + 1] == '_')
        {
            the_fucking_map[y][x + 1] = '^';
            temp_area_data++;
            the_queue.push({x + 1, y});
        }
        if(!(x - 1 < 0 || y < 0 || x - 1 >= how_big_the_map_is || y >= how_big_the_map_is) && the_fucking_map[y][x - 1] == '_')
        {
            the_fucking_map[y][x - 1] = '^';
            temp_area_data++;
            the_queue.push({x - 1, y});
        }
        if(!(x < 0 || y + 1 < 0 || x >= how_big_the_map_is || y + 1 >= how_big_the_map_is) && the_fucking_map[y + 1][x] == '_')
        {
            the_fucking_map[y + 1][x] = '^';
            temp_area_data++;
            the_queue.push({x, y + 1});
        }
        if(!(x < 0 || y - 1 < 0 || x >= how_big_the_map_is || y - 1 >= how_big_the_map_is) && the_fucking_map[y - 1][x] == '_')
        {
            the_fucking_map[y - 1][x] = '^';
            temp_area_data++;
            the_queue.push({x, y - 1});
        }
    }
}


/*

___^__
_^__^_
_^__^_
^_____
__^___
^^^^^^


____^__
____^__
____^__
____^__
____^__
____^__
____^__



*/

int main()
{
    cin >> how_many_maps;
    for(int i = 0; i < how_many_maps; i++)
    {
        cin >> how_big_the_map_is;
        cin >> the_range_of_landing;
        if (the_range_of_landing >= (how_big_the_map_is + 1) / 2)
        {
            cout << "shit";
            break; 
        }
        the_fucking_map.resize(how_big_the_map_is);
        for(int j = 0; j < how_big_the_map_is; j++)
        {
            cin >> the_fucking_map[j];
        }
        
        //int iterator_x = (how_big_the_map_is / 2) - the_range_of_landing;
        //int iterator_y = (how_big_the_map_is / 2) - the_range_of_landing;
        int biggest = 0;
        int middle = how_big_the_map_is / 2;
        for (int j = middle - the_range_of_landing; j <= middle + the_range_of_landing; j++)
        {
            for (int k = middle - the_range_of_landing; k <= middle + the_range_of_landing; k++)
            {
                temp_area_data = 0;
                floodAllOverYouCan(j, k);
                if (temp_area_data > biggest)
                {
                    biggest = temp_area_data;
                }
            }
        }
        the_fucking_map.clear();
        temp_area_data = 0;
        cout << "===" << biggest << "\n";
        biggest = 0;
    }
    return 0;
}