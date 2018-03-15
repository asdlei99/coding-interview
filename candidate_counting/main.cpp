#include <iostream>
#include <cstdlib>
#include "CandidateCountingAlgo3.h"

using namespace std;

int main()
{
    vector<int>score = { 1, 10, 5, 3, 5 };
    vector<int>lowerBounds = { 0, 11, 2, 5 };
    vector<int>upperBounds = { 5, 20, 9, 5 };
    vector<int>count;

    GetCount(score, lowerBounds, upperBounds, count);

    for (int i = 0, len = count.size(); i < len; ++i)
    {
        cout << count[i] << " ";
    }
    cout << endl;
}