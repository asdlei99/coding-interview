#include "CandidateCountingAlgo3.h"
#include <functional>
#include <algorithm>
#include <iostream>

using namespace std;

struct DataWithIndex
{
    int data;
    int index;
};

void GetCount(std::vector<int>& score, 
    const std::vector<int>& lowerBound, const std::vector<int>& upperBound, 
    std::vector<int>& count)
{
    count.resize(lowerBound.size());
    vector<int> sortedBound;
    vector<int> unsort2sortIndexLookup;
    vector<int> accumulative;

    // step 1
    sort(score.begin(), score.end());

    // step 2
    SortBound(lowerBound, upperBound, sortedBound, unsort2sortIndexLookup);

    // step 3
    AccumulateCount(score, sortedBound, accumulative);

    // step 4
    for (int i = 0, len = lowerBound.size(); i < len; ++i)
    {
        int lowIdx = unsort2sortIndexLookup[i];
        int upIdx = unsort2sortIndexLookup[i + len];
        count[i] = accumulative[upIdx] - accumulative[lowIdx];
    }
    return;
}

void SortBound(const std::vector<int>& lowerBound, const std::vector<int>& upperBound, 
    std::vector<int>& sortedBound, std::vector<int>& unsort2sortIndexLookup)
{
    vector<DataWithIndex> boundWithIndex;
    int lowerBoundSize = lowerBound.size();
    int upperBoundSize = upperBound.size();

    boundWithIndex.resize(lowerBoundSize + upperBoundSize);
    sortedBound.resize(lowerBoundSize + upperBoundSize);
    unsort2sortIndexLookup.resize(lowerBoundSize + upperBoundSize);

    for (int i = 0; i < lowerBoundSize; ++i)
    {
        boundWithIndex[i].data = lowerBound[i] - 1;
        boundWithIndex[i].index = i;
    }

    for (int i = 0; i < upperBoundSize; ++i)
    {
        boundWithIndex[i + lowerBoundSize].data = upperBound[i];
        boundWithIndex[i + lowerBoundSize].index = i + lowerBoundSize;
    }

    sort(boundWithIndex.begin(), boundWithIndex.end(),
        [](DataWithIndex a, DataWithIndex b)
    {
        return a.data < b.data;
    });

    for (int i = 0, len = boundWithIndex.size(); i < len; ++i)
    {
        sortedBound[i] = boundWithIndex[i].data;
        unsort2sortIndexLookup[boundWithIndex[i].index] = i;
    }
}

void AccumulateCount(const std::vector<int>& sortedScore, const std::vector<int>& sortedBound, std::vector<int>& accumulative)
{
    accumulative.resize(sortedBound.size());

    int scoreIndex = 0;
    for (int i = 0, len = sortedBound.size(); i < len; ++i)
    {
        if (i > 0)
        {
            accumulative[i] += accumulative[i - 1];
        }

        while (scoreIndex < sortedScore.size() && sortedScore[scoreIndex] <= sortedBound[i])
        {
            ++accumulative[i];
            ++scoreIndex;
        }
    }
}
