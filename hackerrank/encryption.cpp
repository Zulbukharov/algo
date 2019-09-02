#include <bits/stdc++.h>

using namespace std;

// Complete the encryption function below.
string encryption(string s) {
    // remove all whitespaces 13
    int sSize = s.size();
    float sq = sqrt(sSize);
    int r = (int)sq;
    int c = (int)sq;
    while (r * c < sSize)
    {
        // 3                     2 
        if ((r + 1) * c > r * (c + 1))
            r++;
        else
            c++;
    }
    cout << "r - " << r << " c - " << c << endl;     
    // string encrypted = "";
    int i = 0;
    vector<vector<string>> re(r);
    for (int x = 0; x < r; x++) {
        re[x] = vector<string> (c);
        for (int y = 0; y < c && i < sSize; y++) {
            re[x][y] = s[i];
            i++;
        }
    }
    string res = "";
    for (int y = 0; y < c; y++) {
        for (int x = 0; x < r; x++) {
            res += re[x][y];
        }
        res += " ";
    }
    return (res);
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
        // isieae fdtonf fotrga anoyec cttctt tfhhhs
        //    clu hlt io
    getline(cin, s);

    string result = encryption(s);

    fout << result << "\n";

    fout.close();

    return 0;
}

