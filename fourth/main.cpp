#include <iostream>
#include <fstream>
#include <string>

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


    while (getline(file, line))
    {
        if (line.empty())
            continue;
		result++;
    	cout << "result: " << result << endl;
        
    }

    cout << "result: " << result << endl;
    return 0;
}
