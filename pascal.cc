#include <bits/stdc++.h>
using namespace std;

void print_vec(vector<int> &v)
{
    for (auto val : v)
        cout << val << " ";
    cout << endl;
}

vector<vector<int>> solve(int num_rows)
{
    vector<vector<int>> ans(num_rows);
    if (num_rows == 0)
        return ans;
    ans[0] = vector<int>(1);
    ans[1] = vector<int>(2);
    ans[0][0] = 1;
    ans[1][0] = 1;
    ans[1][1] = 1;
    for (int i = 2; i < num_rows; i++)
    {
        ans[i] = vector<int>(i + 1);
        ans[i][0] = 1;
        ans[i][i] = 1;
        for (int j = 1; j < i; j++)
            ans[i][j] = ans[i - 1][j] + ans[i - 1][j - 1];
    }
    return ans;
}

int main()
{
    int n = 0;
    vector<vector<int>> pt = solve(n);
    for (vector<int> v : pt)
    {
        for (int val : v)
            cout << val << " ";
        cout << endl;
    }
}