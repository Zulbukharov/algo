#include <bits/stdc++.h>

using namespace std;

map<int, string> clockMap = {
	{0, "o' clock"},
	{1, "one"},
	{2, "two"},
	{3, "three"},
	{4, "four"},
	{5, "five"},
	{6, "six"},
	{7, "seven"},
	{8, "eight"},
	{9, "nine"},
	{10, "ten"},
	{11, "eleven"},
	{12, "twelve"},
	{13, "thirteen"},
	{14, "fourteen"},
	{15, "quarter"},
	{16, "sixteen"},
	{17, "seventeen"},
	{18, "eighteen"},
	{19, "nineteen"},
	{20, "twenty"},
	{30, "thirty"},
	{40, "fourty"},
	{50, "fifty"},
};

// Complete the timeInWords function below.
string timeInWords(int h, int m) {
	string res = "";
	if (m == 0) {
	// o clock
		res = clockMap[h] + " o' clock";
	} else if (1 <= m && 30 >= m) {
		if (m == 15 || m == 30) {
            if (m == 15)
                res += "quarter";
            else
                res += "half";
		}
        else if (m > 20 && m < 30) {
            res += clockMap[m - (m % 20)] + " " + clockMap[m % 20] + " minutes";
        }
		else
			res += clockMap[m] + " minutes";
	res += " past " + clockMap[h];
	} else if (m > 30) {
	// to
        if (m == 45)
            res += "quarter";
        else {
            m = 60 - m;
            if (m > 20 && m < 30)
                res += clockMap[m - (m % 20)] + " " + clockMap[m % 20] + " minutes";
            else
                res += clockMap[m] + " minutes";
        }
        res += " to " + clockMap[h + 1];

	}
	return res;
}

int main()
{
	//ofstream fout(getenv("OUTPUT_PATH"));

	//freopen("a.in", "r", stdin);
	int h;
	cin >> h;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	int m;
	cin >> m;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	string result = timeInWords(h, m);

	cout << result << "\n";
	//cout.close();
	return 0;
}
