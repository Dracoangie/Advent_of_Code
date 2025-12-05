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

        int to_pick = 12;
        int start = 0;

        long long value = 0;
        while (to_pick > 0)
        {
            char bestDigit = '0';
            int bestPos = start;

            for (int i = start; i <= line.length() - to_pick; ++i)
            {
                if (line[i] > bestDigit)
                {
                    bestDigit = line[i];
                    bestPos = i;
                }
            }
            value = value * 10 + (bestDigit - '0');
            start = bestPos + 1;
            --to_pick;
        }

        result += value;
        cout << value << endl;
    }

    cout << "result: " << result << endl;
    return 0;
}
