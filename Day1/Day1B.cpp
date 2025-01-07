
#include <fstream>
#include <map>
#include <vector>
#include <string>
#include <iostream>

using namespace std;

int main(int argc, char** argv)
{
    ifstream input ("inputB.txt");
    vector<int> leftList;
    map<int, int> rightList;
    string currString;
    while (getline(input, currString))
    {
        int firstSpace = currString.find(' ');
        int lastSpace = currString.rfind(' ');
        leftList.push_back(stoi(currString.substr(0, firstSpace)));
        rightList[stoi(currString.substr(lastSpace + 1, currString.size()))] += 1;
    }

    int total;
    for (int item : leftList)
    {
        total += item * rightList[item];
    }

    cout << total << endl;
}