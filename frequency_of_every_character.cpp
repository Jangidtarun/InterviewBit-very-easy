#include <bits/stdc++.h>
using namespace std;

vector<int> freq(string s)
{
    vector<int> ans(26, 0);
    for (auto &c : s)
        ans[c - 'a']++;
    return ans;
}

bool is_palindrom(string s)
{
    int n = s.length();
    int start = 0;
    int end = n - 1;
    while (start < end)
    {
        if (s[start] != s[end])
            return false;
        start++;
        end--;
    }
    return true;
}

int palindromic_words(string s)
{
    stringstream ss(s);
    string word;
    int ans = 0;
    while (getline(ss, word, ' '))
    {
        ans += is_palindrom(word);
    }
    return ans;
}

int max_substr(string s, int b)
{
    if (b > s.length())
        return count(s.begin(), s.end(), 'a');

    int start = 0;
    int end = b;
    int ans = count(s.begin() + start, s.begin() + end, 'a');
    start += b;
    end += b;
    while (end < s.length())
    {
        int tmp = count(s.begin() + start, s.begin() + end, 'a');
        if (tmp > ans)
            ans = tmp;
        start += b;
        end += b;
    }
    if (end > s.length())
    {
        int tmp = count(s.begin() + start, s.end(), 'a');
        if (tmp > ans)
            ans = tmp;
    }

    return ans;
}

bool isspecial(char c)
{
    string sp_ch = "@#%&!$*";
    for (auto &k : sp_ch)
        if (k == c)
            return true;
    return false;
}

bool is_valid_passw(string s)
{
    if (s.length() < 8 || s.length() > 15)
        return false;

    string digits = "0123456789";
    vector<bool> con(5, 0);
    con[1] = 1;
    for (auto &val : s)
    {
        if (isdigit(val))
            con[0] = 1;
        else if (islower(val))
            con[2] = 1;
        else if (isupper(val))
            con[3] = 1;
        else if (isspecial(val))
            con[4] = 1;
    }

    // Password should have at least one numerical digit(0-9).
    // Password length should be in between 8 to 15 characters.
    // Password should have at least one lowercase letter(a-z).
    // Password should have at least one uppercase letter(A-Z).
    // Password should have at least one special character ( @, #, %, &, !, $, *).

    auto all_con_tru = [](const vector<bool> &v)
    {
        for (const auto &val : v)
            if (val == 0)
                return false;
        return true;
    };

    return all_con_tru(con);
}

int flip_bits(int x)
{
    vector<int> v;
    int ans = 0;
    while (x > 0)
    {
        v.push_back(x % 2);
        x /= 2;
    }
    // remove the leading zero's
    // reverse(v.begin(), v.end());
    for (int i = v.size() - 1; i >= 0; i--)
    {
        if (v[i] == 0)
            v.pop_back();
        else
            break;
    }

    // flipping
    for (auto &val : v)
        val = (val + 1) % 2;

    // making integer
    for (int i = 0; i < v.size(); i++)
        ans += pow(2, i) * v[i];

    return ans;
}



int main()
{
    int x = 10;
    cout << flip_bits(x) << endl;
    return EXIT_SUCCESS;
}