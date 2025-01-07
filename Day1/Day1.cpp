#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;


int main(int argc, char** argv)
{
    ifstream inputFile("input.txt");

    string currLine;
    vector<int> leftLine;
    vector<int> rightLine;
    int total = 0;
    while (getline(inputFile, currLine))
    {
        int firstSpace = currLine.find(' ');
        int lastSpace = currLine.rfind(' ');
        leftLine.push_back(stoi(currLine.substr(0, firstSpace)));
        rightLine.push_back(stoi(currLine.substr(lastSpace + 1, currLine.size())));
    }
    sort(leftLine.begin(), leftLine.end());
    sort(rightLine.begin(), rightLine.end());

    for (int i = 0; i < leftLine.size(); i ++)
    {
        total += abs(leftLine[i] - rightLine[i]);
    }
    cout << total << endl;
}   