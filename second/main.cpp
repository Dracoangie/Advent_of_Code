#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

bool isInvalidID(long long i) {
    string s = to_string(i);

    for (int i = 1; i <= s.size() / 2; ++i)
	{
        if (s.size() % i != 0)
			continue;
        bool result = true;
        for (int pos = i; pos < s.size(); pos += i)
		{
            if (s.compare(pos, i, s.substr(0, i)) != 0)
			{
                result = false;
                break;
            }
        }
        if (result)
            return true;
    }
    return false;
}

int main(int argc, char** argv)
{
    string input(argv[1]);

    vector<pair<long long, long long>> ranges;
    string token;
    stringstream ss(input);

    while (getline(ss, token, ',')) {
        if (token.empty()) continue;
        size_t dash = token.find('-');
        if (dash == string::npos) continue;

        long long a = stoll(token.substr(0, dash));
        long long b = stoll(token.substr(dash + 1));
        ranges.push_back({a, b});
    }

    long long result = 0;

    for (auto &p : ranges) {
        long long a = p.first;
        long long b = p.second;

        for (long long i = a; i <= b; i++) {
            if (isInvalidID(i)) {
                cout << i << endl;
                result += i;
            }
        }
    }

    cout << "result: " << result << endl;
    return 0;
}