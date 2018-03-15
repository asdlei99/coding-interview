#include <vector>

void GetCount(std::vector<int>& score, 
    const std::vector<int>& lowerBound, const std::vector<int>& upperBound,
    std::vector<int>& count);

// sort the (lower_bound - 1) + upper_bound and record the unsorted index to sorted index
void SortBound(const std::vector<int>& lowerBound, const std::vector<int>& upperBound, 
    std::vector<int>& sortedBound, std::vector<int>& unsort2sortIndexLookup);

void AccumulateCount(const std::vector<int>& sortedScore, const std::vector<int>& sortedBound, 
    std::vector<int>& accumulative);
