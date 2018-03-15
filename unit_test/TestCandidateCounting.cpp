#include "gtest/gtest.h"
#include "CandidateCountingAlgo3.h"

using namespace std;

TEST(TestCount, TestAlgorithm3) {

    vector<int>score = { 1, 10, 5, 3, 5 };
    vector<int>lowerBounds = { 0, 11, 2, 5 };
    vector<int>upperBounds = { 5, 20, 9, 5 };
    vector<int>correctCount = { 4, 0, 3, 2 };
    vector<int>count;

    GetCount(score, lowerBounds, upperBounds, count);
    EXPECT_EQ(count, correctCount);

    score = { 5, 1, 5, 6, 2 };
    lowerBounds = { 1, 2, 3 };
    upperBounds = { 5, 5, 5 };
    correctCount = { 4, 3, 2 };

    GetCount(score, lowerBounds, upperBounds, count);
    EXPECT_EQ(count, correctCount);
}

TEST(TestSortBound, TestAlgorithm3) {

    vector<int>lowerBounds = { 0, 11, 2, 5 };
    vector<int>upperBounds = { 5, 20, 9, 5 };
    vector<int>sortedBound;
    vector<int>unsort2sortIndexLookup;

    vector<int>correctBound = { -1, 1, 4, 5, 5, 9, 10, 20 };
    vector<int>correctunsort2sortIndexLookup = {0, 6, 1, 2, 3, 7, 5, 4};

    SortBound(lowerBounds, upperBounds, sortedBound, unsort2sortIndexLookup);
    EXPECT_EQ(sortedBound, correctBound);
    EXPECT_EQ(unsort2sortIndexLookup, correctunsort2sortIndexLookup);
}

TEST(TestAccumulateCount, TestAlgorithm3) {

    vector<int>sortedScore = { 1, 3, 5, 5, 10 };
    vector<int>sortedBound = { -1, 1, 4, 5, 5, 9, 10, 20 };
    vector<int>correctAccumulative = { 0, 1, 2, 4, 4, 4, 5, 5 };
    vector<int>accumulative;

    AccumulateCount(sortedScore, sortedBound, accumulative);
    EXPECT_EQ(accumulative, correctAccumulative);
}