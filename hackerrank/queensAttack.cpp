#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the queensAttack function below.
int queensAttack(int n, int k, int r_q, int c_q, vector<vector<int>> obstacles) {
    vector<int> value(8);

    // r_q == y, c_q == x
    value[0] = n - r_q;
    value[1] = n - max(r_q, c_q);
    value[2] = n - c_q;
    value[3] = min(n - c_q, r_q - 1);
    value[4] = r_q - 1;
    value[5] = min(c_q, r_q) - 1;
    value[6] = c_q - 1;
    value[7] = min(n - r_q, c_q - 1);
    
    int obsSize = obstacles.size();
    for (int i = 0; i < obsSize; i++) {
        // 0 - y, 1 - x
        // r_q == y, c_q == x
        int x = obstacles[i][1];
        int y = obstacles[i][0];
        if (y == r_q || x == c_q || 
            abs(r_q - y) == abs(c_q - x))
            {
                int diff = 0;
                if (x == c_q && y > r_q) {
                    diff = abs(y - r_q) - 1;
                    value[0] = value[0] > diff ?  diff : value[0];
                } else if (x > c_q && y > r_q) {
                    diff = abs(x - c_q) - 1;
                    value[1] = value[1] > diff ?  diff : value[1]; 
                } else if (x > c_q && y == r_q) {
                    diff = abs(x - c_q) - 1;
                    value[2] = value[2] > diff ?  diff : value[2];
                } else if (x > c_q && y < r_q) {
                    diff = abs(c_q - x) - 1;
                    value[3] = value[3] > diff ?  diff : value[3]; 
                } else if (x == c_q && y < r_q) {
                    diff = abs(r_q - y) - 1;
                    value[4] = value[4] > diff ?  diff : value[4];
                } else if (x < c_q && y < r_q) {
                    diff = abs(c_q - x) - 1;;
                    value[5] = value[5] > diff ?  diff : value[5];
                } else if (x < c_q && y == r_q) {
                    diff = abs(c_q - x - 1);
                    value[6] = value[6] > diff ?  diff : value[6];
                } else if (x < c_q && y > r_q) {
                    diff = abs(c_q - x) - 1;
                    value[7] = value[7] > diff ?  diff : value[7];
                }
            }
    }

    int all = 0;
    for (int i = 0; i < 8; i++) {
        all += value[i];
    }

    return all;

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string nk_temp;
    getline(cin, nk_temp);

    vector<string> nk = split_string(nk_temp);

    int n = stoi(nk[0]);

    int k = stoi(nk[1]);

    string r_qC_q_temp;
    getline(cin, r_qC_q_temp);

    vector<string> r_qC_q = split_string(r_qC_q_temp);

    int r_q = stoi(r_qC_q[0]);

    int c_q = stoi(r_qC_q[1]);

    vector<vector<int>> obstacles(k);
    for (int i = 0; i < k; i++) {
        obstacles[i].resize(2);

        for (int j = 0; j < 2; j++) {
            cin >> obstacles[i][j];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    int result = queensAttack(n, k, r_q, c_q, obstacles);

    fout << result << "\n";

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}

