#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'nonDivisibleSubset' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER k
 *  2. INTEGER_ARRAY s
 */

int nonDivisibleSubset(int k, vector<int> s) {
    vector<int> balanceCount(k);
    // 4 3
    // 1 7 2 4

    // 1 2 3 4 5
    // 1
    if (k == 1) {
        return 1;
    }
    int ssize = s.size();
    for (int i = 0; i < ssize; i++) {
        balanceCount[s[i] % k]++;
    }

    for (int i = 0; i < k; i++) {
        cout << balanceCount[i] << endl;
    }
    
    int max = 0;
    for (int i = 0; i < ssize; i++) {
        // 0 0 0 0
        // 0 1 2 3
        // 1 3 1 0
        int a = s[i] % k; // 1 2 3 0 1 2 3 0 1 2
        // if a % 2 == 0 => take 1 make zero continue
        int b = k - a; //    3 2 1 4 3 2 1 4 3 2
        int aValue = balanceCount[a];
        cout << "[avalu][" << aValue << "] ";
        cout << "[max][" << max << "] ";
        if ((b == a) || (b == k) ) {
            if (aValue > 0)
                max++;
            balanceCount[a] = 0;
            continue;
        }
        int bValue = balanceCount[b];
        max += aValue > bValue ? aValue : bValue;
        balanceCount[a] = 0;
        balanceCount[b] = 0;
    }
    return max;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    int n = stoi(first_multiple_input[0]);

    int k = stoi(first_multiple_input[1]);

    string s_temp_temp;
    getline(cin, s_temp_temp);

    vector<string> s_temp = split(rtrim(s_temp_temp));

    vector<int> s(n);

    for (int i = 0; i < n; i++) {
        int s_item = stoi(s_temp[i]);

        s[i] = s_item;
    }

    int result = nonDivisibleSubset(k, s);

    fout << result << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}

