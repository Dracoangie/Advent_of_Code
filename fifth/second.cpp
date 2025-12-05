#include <bits/stdc++.h>
using namespace std;

int main() {
	ifstream file("input.txt");
	string line;
	vector<pair<long long,long long>> ranges;

	while (getline(file, line)) {
		if (line.empty()) break;
		auto dash = line.find('-');
		long long x = stoll(line.substr(0, dash));
		long long y = stoll(line.substr(dash + 1));
		ranges.push_back({x, y});
	}

	sort(ranges.begin(), ranges.end());

	long long result = 0;
	long long curL = ranges[0].first;
	long long curR = ranges[0].second;

	for (size_t i = 1; i < ranges.size(); ++i)
	{
		long long x = ranges[i].first;
		long long y = ranges[i].second;

		if (x <= curR) {
			curR = max(curR, y);
		} else {
			result += (curR - curL + 1);
			curL = x;
			curR = y;
		}
	}

	result += (curR - curL + 1);

	cout << "result: " << result << endl;
	return 0;
}
