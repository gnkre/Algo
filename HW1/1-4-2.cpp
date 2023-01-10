#include <iostream>
#include <queue>
using namespace std;

int main()
{
    priority_queue<int> pq;
    queue<int> q;
    int queries = 0;
    std::cin >> queries;
    int front = 0;
    int back = 0;
    for(int i = 0; i < queries; i++)
    {
        int command = 0;
        cin >> command;
        if (command == 1)
        {
            int temp_num = 0;
            cin >> temp_num;
            q.push(temp_num);
        }
        else if (command == 2)
        {
            while(!q.empty())
            {
                pq.push(q.front());
                q.pop();
            }
        }
        else if (command == 3)
        {
            if (!pq.empty())
            {
                cout << pq.top() << endl;
                pq.pop();
            }
            else if (!q.empty())
            {
                cout << q.front() << endl;
                q.pop();
            }
            else
            {
                cout << "Oh Oh" << endl;
            }
        }
    }
    return 0;
}

