#include <bits/stdc++.h>
using namespace std;

string solve(vector<int> &a)
{
    fixed;
    setprecision(2);
    int n = a.size();
    long long int sum = 0;
    for (int val : a)
        sum += val;
    double mean = (double)sum / n;
    // cout << "mean: " << mean << endl;
    // mean = (double)accumulate(a.begin(), a.end(), 0) / n;
    vector<double> diff(n);
    double ss = 0.0;
    for (int i = 0; i < n; i++)
    {
        diff[i] = a[i] - mean;
        ss += pow(diff[i], 2.0);
    }
    // cout << "ss: " << ss << endl;
    double var = ss / n;
    var *= 1e2;
    var = round(var);
    var = var / 100;
    string ans = to_string(var);
    size_t p = ans.find('.');
    ans = ans.substr(0,p+3);
    return ans;
}

int main()
{
    vector<int> v = {5, 1, 4, 5, 2};
    string var_ins = solve(v);
    cout << "var: " << var_ins << endl;
}