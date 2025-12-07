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
	vector<string> map;
    while (getline(file, line))
    {
        if (line.empty())
			break;
		map.push_back(line);
    }
	long long aux = 1;
	long long numAux = -1;
	
	while(map[map.size() -1][0])
	{
		if(map[map.size() -1][0] == '*')
		{
			result += aux;
			aux = 1;

		}
		else if(map[map.size() -1][0] == '+')
		{

			result += aux;
			aux = 0;
		}
		numAux = -1;
		for (size_t i = 0; i < map.size() -1; i++)
		{
			if(map[i][0] == ' ')
			{
				map[i] = map[i].substr(1);
				continue;
			}
			if(numAux < 0)
				numAux = map[i][0] - '0';
			else
			{
				numAux = numAux *10;
				numAux += (map[i][0] - '0');
			}
    		cout <<"res "<< numAux << endl;
			map[i] = map[i].substr(1);
		}
		map[map.size() -1] =  map[map.size() -1].substr(1);
		if(map[map.size() -1][0] == '*')
			aux = aux * numAux;
		else if(map[map.size() -1][0] == '+')
			aux = aux + numAux;
	}

    cout << "result: " << result << endl;
    return 0;
}
