#include <bits/stdc++.h>

using namespace std;

vector<int> scores;

int returnClosestIndex(int aliceScore, int *high) {
    int low;
    int mid;
    int guess;
    int count;

    low = 0;
    count = 1;
    while (low <= *high)
    {
        mid = (low + *high) / 2;
        guess = scores[mid];
        if (guess == aliceScore)
        {
            return (mid);
        }
        else if (guess < aliceScore)
            *high = mid - 1;
        else
            low = mid + 1;
        count++;
    }
    return (mid);
}

int main()
{
    // freopen("a.in", "r", stdin);
    int scores_count;
    scanf("%d\n", &scores_count);

    for (int i = 0; i < scores_count; i++) {
        int x;
        scanf("%d ", &x);
         scores.push_back(x);
    }


    scores.erase( unique( scores.begin(), scores.end() ), scores.end() );
    int szsc;
    szsc = scores.size();
    int high = scores.size() - 1;


    int alice_count;
    scanf("%d\n", &alice_count);
    vector<int> aliceRanks(alice_count);
    for (int i = 0; i < alice_count; i++) {
        int currentAlice;
        scanf("%d ", &currentAlice);
        if (currentAlice > scores[0]) {
            aliceRanks[i] = 1;
        } else if (currentAlice < scores[szsc - 1]) {
            aliceRanks[i] = szsc + 1;
        } else {
            int closestIndex = returnClosestIndex(currentAlice, &high);
            int closestValue = scores[closestIndex];
            if (currentAlice >= closestValue) {
                aliceRanks[i] = closestIndex + 1;
            }
            else if (currentAlice < closestValue) {
                aliceRanks[i] = closestIndex + 2;
            }
        }
    }
    for (int i = 0; i < aliceRanks.size(); i++) {
        printf("%d", aliceRanks[i]);
        if (i != aliceRanks.size() - 1) {
            printf("\n");
        }
    }

    return 0;
}

