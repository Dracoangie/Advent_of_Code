#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <list>

using namespace std;

int main(int argc, char **argv)
{
    if (argc < 2)
        return (cerr << "usage: " << argv[0] << " <file>", 1);

    ifstream file(argv[1]);
    if (!file)
        return (cerr << "wrong file", 1);

    string line;
    long long result = 0;
	list<vector<long long>> ranges;


    while (getline(file, line))
    {
		long long x,y = 0;
        if (line.empty())
			break;
		x = stoll(line);
		y = stoll(line.substr(line.find('-') + 1));
		ranges.push_back({x,y});
    }
	
	while (getline(file, line))
    {
		if (line.empty())
			continue;
		for (auto &&i : ranges)
		{
			cout << i[0] << "," << i[1] << endl;
			if(stoll(line) > i[0] && stoll(line) < i[1]){
				result++;
				break;}
		}
    	cout << result << endl;
    }

    cout << "result: " << result << endl;
    return 0;
}
