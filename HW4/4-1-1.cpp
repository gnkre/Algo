#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int num_of_card = 0;
string dataa[5000];
bool cmp(string a, string b)
{
    string temp1 = a.append(b);
    
    string temp2 = b.append(a);
    for(int i = 0; i < temp1.size(); i++)
    {
        if (temp1[i] > temp2[i])
        {
            return true;
        }
        else if (temp1[i] < temp2[i])
        {
            return false;
        }
    }
    return false;
    //return a > b;
}

int main()
{
    cin >> num_of_card;
    for (int i = 0; i < num_of_card; i++)
    {
        cin >> dataa[i];
    }
    sort(&dataa[0], &dataa[num_of_card], cmp);
    if (dataa[0][0] == '0')
    {
        printf("0");
        return 0;
    }
    for(int i = 0; i < num_of_card; i++)
    {
        cout << dataa[i];
    }
    return 0;
}