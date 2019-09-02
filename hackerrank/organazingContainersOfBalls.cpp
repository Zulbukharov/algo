#include <bits/stdc++.h>

using namespace std;


//  Make a table of box totals (capacity of each box)
// 2) Make a table of ball totals (total quantity of each ball type)
// 3) Sort both tables
// 4) If they are identical print Possible, otherwise print Impossible
// Complete the organizingContainers function below.
string organizingContainers(vector<vector<int>> container) {
    int containerSize = container.size();
    vector<int> boxTotals(containerSize);
    vector<int> ballsTotals(containerSize);
    for (int x = 0; x < containerSize; x++) {
        for (int y = 0; y < containerSize; y++) {
            boxTotals[x] += container[x][y];
            ballsTotals[y] += container[x][y];
        }
    }
    sort(boxTotals.begin(), boxTotals.end());
    sort(ballsTotals.begin(), ballsTotals.end());
    for (int i = 0; i < containerSize; i++) {
        if (ballsTotals[i] != boxTotals[i]) {
            return "Impossible";
        }
    }
    return "Possible";
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int q_itr = 0; q_itr < q; q_itr++) {
        int n;
        cin >> n;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        vector<vector<int>> container(n);
        for (int i = 0; i < n; i++) {
            container[i].resize(n);

            for (int j = 0; j < n; j++) {
                cin >> container[i][j];
            }

            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        string result = organizingContainers(container);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}

