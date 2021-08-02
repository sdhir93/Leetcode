#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <climits>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <cstdlib>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;


/*
 * Complete the function below.
 */
 
 int binarySearch(vector<int> subsequence, int target) {
    int left = 0;
    int right = subsequence.size() - 1;
    
    while(left < right) {
        int mid = left + (right - left) / 2;
        if(subsequence[mid] == target) {
            return mid;
        }
        
        if(subsequence[mid] < target) left = mid + 1;
        else right = mid;
    }
    
    return left;
}
 
int findLIS(vector < int > s) {
    
    // Check if input is empty
    if(s.size() == 0) return 0;

    // Resultant subsequence    
    vector<int> subsequence;

    // Start with the first element of input vector
    subsequence.push_back(s[0]);
    
    // Go over each element
    for(auto i = 1; i < s.size(); i++) {
        auto num = s[i];
        
        // If current element from input vector is greater than the last element
        // from resultant subsequence, then keep it
        if(num > subsequence.back()) subsequence.push_back(num);
        
        // If current element from input vector is less than or equal to last
        // element from resultant subsequence, then perform binary search to find
        // the index of smallest element that is greater than or equal to num and
        // replace that with num 
        else {
            int index = binarySearch(subsequence, num);
            subsequence[index] = num;
        }
    }
    
    // Return the size
    return subsequence.size();
}



int main() {