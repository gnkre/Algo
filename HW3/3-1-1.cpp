#include <iostream>
int how_many_popularity[2000005] = { 0 };
int post_order_map[2000005] = { 0 };
int in_order_map[2000005] = { 0 };
int post_order[2000005] = { 0 };
int in_order[2000005] = { 0 };
int N;

// 1 index

struct Node
{
    int left;
    int right;
}typedef Node;

Node relation_ship[2000005];
int findThatTreeShit(int in_left_cur, int in_right_cur, int& post_cur)
{
    int root_index_of_real = post_order[post_cur];
    int root_index_of_inorder_arr = in_order_map[root_index_of_real];
    if (in_left_cur > in_right_cur)
    {
        return 0;
    }
    post_cur--;
    //in_order[root_index_of_inorder_arr] = 0;
    if (in_left_cur == in_right_cur)
    {
        return root_index_of_real;
    }
    
    relation_ship[root_index_of_real].right = findThatTreeShit(root_index_of_inorder_arr + 1, in_right_cur, post_cur);
    relation_ship[root_index_of_real].left = findThatTreeShit(in_left_cur, root_index_of_inorder_arr - 1, post_cur);
    return root_index_of_real;
}

int main()
{
    scanf("%d", &N);
    for (int i = 0; i <= N; i++)
    {
        relation_ship[i].left = 0;
        relation_ship[i].right = 0;
    }
    for(int i = 1; i <= N; i++)
    {
        scanf("%d", &how_many_popularity[i]);
    }
    for(int i = 1; i <= N; i++)
    {
        int temp_shit;
        scanf("%d", &temp_shit);
        in_order[i] = temp_shit;
        in_order_map[temp_shit] = i;
    }
    for(int i = 1; i <= N; i++)
    {
        int temp_shit;
        scanf("%d", &temp_shit);
        post_order[i] = temp_shit;
        post_order_map[temp_shit] = i;
    }

    int post_cur = N;
    findThatTreeShit(1, N, post_cur);
    int ans = 0;
    for(int i = 1; i <= N; i++)
    {
        if (how_many_popularity[i] < how_many_popularity[relation_ship[i].left])
        {
            ans++;
        }
        if (how_many_popularity[i] < how_many_popularity[relation_ship[i].right])
        {
            ans++;
        }
    }
    printf("%d", ans);
    return 0;
}
