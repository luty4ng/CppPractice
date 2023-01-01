#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

vector<string> globalVec;
void ReadFileToVec(const string &fileName, vector<string> &vec)
{
    ifstream ifs(fileName);
    if (ifs)
    {
        string buf;
        while (ifs >> buf)
            vec.push_back(buf);
    }
}

int main()
{
    const string path = "IO_FStream_Text.txt";
    ReadFileToVec(path, globalVec);
    for (auto i = globalVec.begin(); i != globalVec.end(); i++)
    {
        cout << *i << ' ';
    }
}