#include <bits/stdc++.h>
using namespace std;

void print_vec(vector<int> &v)
{
    for (auto val : v)
        cout << val << " ";
    cout << endl;
}

void determine_row(vector<int> &row, const vector<int> prow)
{
    for (int i = 1; i < prow.size(); i++)
        row[i] = prow[i] + prow[i - 1];
    row[0] = prow[0];
    row[row.size() - 1] = prow[prow.size() - 1];

}

vector<vector<int>> solve(int num_rows)
{
    vector<vector<int>> ans(num_rows);
    ans[0][0] = 1;
    ans[1][0] = 1;
    ans[1][1] = 1;
    for (int i = 2; i <= num_rows; i++)
    {
        vector<int> row(i);
        
        ans[i] = row;
    }
    return ans;
}

int main()
{
    int n = 3;
    vector<vector<int>> pt = solve(n);
    for (vector<int> v : pt)
    {
        for (int val : v)
            cout << val << " ";
        cout << endl;
    }
}