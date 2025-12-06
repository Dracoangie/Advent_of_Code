#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int checker(vector<string> rolls, int x, int y)
{
	int count = 0;
	for (long long i = x - 1; i <= x + 1; i++)
	{
		for (long long j = y - 1; j <= y + 1; j++)
		{
			if(i < 0 || j < 0 ||
				i >= rolls.size() || j >= rolls[x].size())
				continue;
			if(x == i && y == j)
				continue;
			if(rolls[i][j] == '@')
				count++;
		}
	}
	return (count < 4) ? 1 : 0;
}

int main(int argc, char **argv)
{
    if (argc < 2)
        return (cerr << "usage: " << argv[0] << " <file>", 1);

    ifstream file(argv[1]);
    if (!file)
        return (cerr << "wrong file", 1);

    string line;
    long long result = 0;
    long long changed = 1;
    vector<string> rolls;
    vector<string> rollsaux;


    while (getline(file, line))
    {
        if (line.empty())
            continue;
		rolls.push_back(line);
        
    }
	rollsaux = rolls;

	while(changed != 0)
	{
		changed = 0;
		rolls  = rollsaux;
		for (size_t i = 0; i < rolls.size(); i++)
		{
			for (size_t j = 0; j < rolls[i].size(); j++)
			{
				if(rolls[i][j] == '@')
				{
					if(checker(rolls, i, j)){
					result ++ ;
					changed ++;
					rollsaux[i][j] = '.';
					cout << i << ","<< j << endl;}
				}
			}
		}
	}
	
    cout << "result: " << result << endl;
    return 0;
}
