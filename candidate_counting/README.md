# Candidate counting problem
## Description
Given an unsorted array of candidates' scores, and an array of lower bounds and upper bounds, count how many candidates we should accept for each pair of bounds.

### Input
scores an array of n integers, 0<n<10^5
lower_bounds and upper_bounds, two arrays of m integers each, 0<m<10^5

### Output
An array counts of m integers, such that for each 0<=i<m, counts[i] is equal to the number of elements of scores that are in [lower_bounds[i], upper_bounds[i]] (inclusive)

### Example
* Input: scores = [1, 10, 5, 3, 5]
* lower_bounds = [0, 11, 2, 5]
* upper_bounds = [5, 20, 9, 5]
* Desired output: counts = [4, 0, 3, 2]

## Solution
### Algorithm 1
brute force compare...

**Time conplexity: O(nm)**

  
### Algorithm 2
1. 
    sort the scores
    ex:  [1, 3, 5, 5, 10]
  
2. 
    ```sh
    foreach pair of (lower_bound, upper_bound)
        binary search the index in sorted scores.
        count = @upper_bound - @lower_bound
    ```
    where @x denote the index of x in sorted scores.
    
    PS: There are some noisy conditions need to add one.
    For example,
    - count of [2, 9] = @upper_bound - @lower_bound = 4 - 1 = 3
    - count of [2, 5] = @upper_bound - @lower_bound + 1 = 3 - 1 + 1= 3
    - count of [3, 5] = @upper_bound - @lower_bound + 1 = 3 - 1 + 1 = 3
    - count of [4, 5] = @upper_bound - @lower_bound = 3 - 1  = 2
    - count of [5, 5] = @upper_bound - @lower_bound + 1 = 3 - 2 + 1 = 2

**Average Time conplexity: O(nlogn + mlogn)**

**Worst Time conplexity: O(nm)**

**Space complexity: O(1)**

  
### Algorithm 3
1. sort the scores
ex:  [1, 3, 5, 5, 10]
  
2. sort the (lower_bound - 1) + upper_bound and record the unsort index to sort index
ex: 
- lower_bounds = [0, 11, 2, 5], upper_bounds = [5, 20, 9, 5]
- concate [-1, 10, 1, 4, 5, 20, 9, 5]
- Obtain sort_bound [-1, 1, 4, 5, 5, 9, 10, 20]
- Obtain index = [0, 6, 1, 2, 3, 7, 5, 4]
    
3. count how many scores <= sort_bound
ex: accumulative = [0, 1, 2, 4, 4, 4, 5, 5]
  
4. counts of (lower_bound, upper_bound) = accumulative[@upper_bound] - accumulative[@(lower_bound - 1)], where @x denote the index of x in sort_bound
PS: index is obtained from step 2
ex: count of [2, 9] = accumulative[@9] - accumulative[@1] = accumulative[5] - accumulative[1] = 3
    count of [5, 5] = accumulative[@5] - accumulative[@4] = accumulative[3] - accumulative[2] = 2

**Time conplexity: O(nlogn + mlogm)**

**Space complexity: O(m)**
    
### Algorithm 4
PS: Inspired by integral image
If range of score is small (ex: 0~255), we can use this algorithm

1. Compute the occurance array (score -> occurance) with size max(score) + 1
ex: scores = [1, 10, 5, 3, 5]
		occurrance = [0, 1, 0, 1, 0, 2, 0, 0, 0, 0, 1]

2. Compute integral image I from occurrance
ex: [0, 1, 1, 2, 2, 4, 4, 4, 4, 4, 5]
  
3. Count of (lower_bound, upper_bound) = I[upper_bound] - I[lower_bound] + 1

**Time complexity: O(n + r), where r is maximum of score**

**Space complexity: O( r), where r is maximum of score**
