#include <iostream>
#include <vector>
using namespace std;

int time_num, student_num, class_capacity, comb_num;
int mat_size;
int src_index;
int end_index;
vector<vector<int> > adj_mat;
vector<vector<int> > adj_mat_new;
vector<vector<int> > R_adj_mat_new;
vector<int> time_list;
vector<bool> can_visit;
vector<int> can_visit_new;

bool DFS(bool visited[2005], int parent[2005], int src, int sink, int mat_size)
{
    //if (src >= student_num && src < student_num + time_num)
    //{
    //    //i = end_index;
    //    printf("%d %d\n", src, sink);
    //}
    if (src == sink)
    {
        return true;
    }
    visited[src] = true;
    int i = 0;
    if (src == src_index)
    {
        i = 0;
    }
    else if (src >= 0 && src < student_num)
    {
        for (int i = 0; i < can_visit_new.size(); i++)
        {
            if (R_adj_mat_new[src][can_visit_new[i]] > 0 && visited[can_visit_new[i]] == false)
            {
                parent[can_visit_new[i]] = src;
                if (DFS(visited, parent, can_visit_new[i], sink, mat_size))
                {
                    return true;
                }
                
            }
        }
        return false;
    }
    else if (src >= student_num && src < student_num + time_num)
    {
        i = end_index;
        //printf("%d %d\n", src, end_index);
    }
    
    while(i < mat_size)//for (int i = 0 ;i < mat_size; i++)
    {
        if (R_adj_mat_new[src][i] > 0 && visited[i] == false && can_visit[i])
        {
            parent[i] = src;
            if (DFS(visited, parent, i, sink, mat_size))
            {
                return true;
            }
        }
        i++;
    }
    return false;
}

int maskMatrixThenFlow(int list_count, int src, int sink, int mat_size)
{
    //adj_mat_new = adj_mat;
    R_adj_mat_new = adj_mat;

    int max_flow = 0;
    int parent[2005] = { 0 };
    bool visited[2005] = { 0 };
    while (DFS(visited, parent, src, sink, mat_size))
    {
        for (int i  = 0; i < mat_size; i++)
        {
            visited[i] = false;
        }
        int curr_flow = INT32_MAX;
        for(int v = sink; v != src; v = parent[v])
        {
			int u = parent[v];
            if (curr_flow > R_adj_mat_new[u][v])
            {
                curr_flow = R_adj_mat_new[u][v];
            }
		}
        for(int v = sink; v != src; v = parent[v])
        {
			int u = parent[v];
            R_adj_mat_new[u][v] -= curr_flow;
			R_adj_mat_new[v][u] += curr_flow;
		}
        max_flow += curr_flow;
    }
    int ans = student_num - max_flow;
    return ans;
}



int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    while (cin >> time_num >> student_num >> class_capacity >> comb_num)
    {
        int assign_idx = 0;
        src_index = time_num + student_num + 4;
        end_index = src_index + 2;
        mat_size = time_num + student_num + 100;
        //adj_mat.clear();
        adj_mat.resize(mat_size, vector<int>(mat_size, 0));
        can_visit.resize(mat_size, false);
        can_visit[src_index] = true;
        can_visit[end_index] = true;
        for (int i = 0; i < mat_size; i++)
        {
            for (int j = 0; j < mat_size; j++)
            {
                adj_mat[i][j] = 0;
            }
        }
        for (int i = 0; i < student_num; i++)
        {
            adj_mat[src_index][i] = 1;
            can_visit[i] = true;
        }
        for (int i = 0; i < student_num; i++)
        {
            int std_idx;
            cin >> std_idx;
            int std_time_num;
            cin >> std_time_num;
            for (int j = 0; j < std_time_num; j++)
            {
                int time_idx;
                cin >> time_idx;
                adj_mat[std_idx][student_num + time_idx] = 1;
            }
        }
        for (int i = 0; i < time_num; i++)
        {
            adj_mat[student_num + i][end_index] = class_capacity;
        }
        int ans = INT32_MAX;
        for (int i = 0; i < comb_num; i++)
        {
            can_visit_new.clear();
            int time_ct;
            cin >> time_ct;
            //time_list.resize(time_ct);
            //for (int i = student_num; i < student_num + time_num; i++)
            //{
            //    can_visit[i] = false;
            //}
            for (int i = 0; i < time_ct; i++)
            {
                int idx_time;
                cin >> idx_time;
                can_visit_new.push_back(idx_time + student_num);
                //can_visit[student_num + idx_time] = true;
            }
            int new_ans = maskMatrixThenFlow(time_ct, src_index, end_index, mat_size);
            cout << new_ans << "\n";
        }
    }
    return 0;
}