#include <iostream>
#include <algorithm>
#include <string>
#include <cstdlib>
#include <stdio.h>
using namespace std;

int num_of_audience = 0;
string height;
string weight;
string iq;
string eq;
int size_a = 0;
int size_b = 0;
int size_c = 0;
int size_d = 0;
struct Audience
{
    int a = 0;
    int b = 0;
    int c = 0;
    int d = 0;
    string name;
}typedef Audience;
Audience* grp_A;
Audience* grp_B;
Audience* grp_C;
Audience* grp_D;

bool cmp(Audience first, Audience second){
    if (first.a == second.a) 
    {
        if (first.b == second.b) 
        {
            if (first.c == second.c) 
            {
                if (first.d == second.d) 
                {
                    for (int i = 0; i < 20; i++) 
                    {
                        if (first.name[i] != second.name[i]) 
                        {
                            return first.name[i] < second.name[i];
                        }
                    }
                }
                return first.d > second.d;
            }
            return first.c > second.c;
        }
        return first.b > second.b;
    }
    return first.a > second.a;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> num_of_audience;
    grp_A = new Audience[num_of_audience];
    grp_B = new Audience[num_of_audience];
    grp_C = new Audience[num_of_audience];
    grp_D = new Audience[num_of_audience];
    cin >> height >> weight >> iq >> eq;
    int order_A[4];
    int order_B[4];
    int order_C[4];
    int order_D[4];
    for(int i = 0; i < 4; i++)
    {
        if (height[i] == 'H')
        {
            order_A[i] = 0;
        }
        else if (height[i] == 'W')
        {
            order_A[i] = 1;
        }
        else if (height[i] == 'I')
        {
            order_A[i] = 2;
        }
        else if (height[i] == 'E')
        {
            order_A[i] = 3;
        }
    }
    for(int i = 0; i < 4; i++)
    {
        if (weight[i] == 'H')
        {
            order_B[i] = 0;
        }
        else if (weight[i] == 'W')
        {
            order_B[i] = 1;
        }
        else if (weight[i] == 'I')
        {
            order_B[i] = 2;
        }
        else if (weight[i] == 'E')
        {
            order_B[i] = 3;
        }
    }
    for(int i = 0; i < 4; i++)
    {
        if (iq[i] == 'H')
        {
            order_C[i] = 0;
        }
        else if (iq[i] == 'W')
        {
            order_C[i] = 1;
        }
        else if (iq[i] == 'I')
        {
            order_C[i] = 2;
        }
        else if (iq[i] == 'E')
        {
            order_C[i] = 3;
        }
    }
    for(int i = 0; i < 4; i++)
    {
        if (eq[i] == 'H')
        {
            order_D[i] = 0;
        }
        else if (eq[i] == 'W')
        {
            order_D[i] = 1;
        }
        else if (eq[i] == 'I')
        {
            order_D[i] = 2;
        }
        else if (eq[i] == 'E')
        {
            order_D[i] = 3;
        }
    }
    for (int i = 0; i < num_of_audience; i++) 
    {
        Audience temp;
        cin >> temp.name;
        int dd[4];
        cin >> dd[0] >> dd[1] >> dd[2] >> dd[3];
        if (dd[0] >= dd[1] && dd[0] >= dd[2] && dd[0] >= dd[3]) 
        {
            temp.a = dd[order_A[0]];
            temp.b = dd[order_A[1]];
            temp.c = dd[order_A[2]];
            temp.d = dd[order_A[3]];
            grp_A[size_a] = temp;
            size_a++;
        }
        else if (dd[1] >= dd[2] && dd[1] >= dd[3]) 
        {
            temp.a = dd[order_B[0]];
            temp.b = dd[order_B[1]];
            temp.c = dd[order_B[2]];
            temp.d = dd[order_B[3]];
            grp_B[size_b] = temp;
            size_b++;
        }
        else if (dd[2] >= dd[3]) 
        {
            temp.a = dd[order_C[0]];
            temp.b = dd[order_C[1]];
            temp.c = dd[order_C[2]];
            temp.d = dd[order_C[3]];
            grp_C[size_c] = temp;
            size_c++;
        }
        else 
        {
            temp.a = dd[order_D[0]];
            temp.b = dd[order_D[1]];
            temp.c = dd[order_D[2]];
            temp.d = dd[order_D[3]];
            grp_D[size_d] = temp;
            size_d++;
        }
    }
    sort(grp_A, grp_A + size_a, cmp);
    sort(grp_B, grp_B + size_b, cmp);
    sort(grp_C, grp_C + size_c, cmp);
    sort(grp_D, grp_D + size_d, cmp);

    cout << "Group A:";
    if (size_a == 0) 
    {
        cout << " No Audience\n";
    }
    else 
    {
        cout << "\n";
        for (int i = 0; i < size_a; i++) 
        {
            cout << grp_A[i].name << '\n';
        }
    }
    cout << "Group B:";
    if (size_b == 0) 
    {
        cout << " No Audience\n";
    }
    else 
    {
        cout << "\n";
        for (int i = 0; i < size_b; i++) 
        {
            cout << grp_B[i].name << '\n';
        }
    }
    cout << "Group C:";
    if (size_c == 0) 
    {
        cout << " No Audience\n";
    }
    else 
    {
        cout << "\n";
        for (int i = 0; i < size_c; i++) 
        {
            cout << grp_C[i].name << '\n';
        }
    }
    cout << "Group D:";
    if (size_d == 0) 
    {
        cout << " No Audience\n";
    }
    else 
    {
        cout << "\n";
        for (int i = 0; i < size_d; i++) 
        {
            cout << grp_D[i].name << '\n';
        }
    }
    return 0;
}