
/*
Problem: https://leetcode.com/problems/find-k-closest-elements/

Find K Closest Elements

Solution:

f(i) = abs(arr[i] - x ) vs i where i is index

Graph looks like this

^
|
| *        *
|  |*_____*|
|    *   *
|      *
|   
--------------------------->

1. Perform binary search to make left as the starting of begenning of the result array
2. if (x - arr[mid] > arr[mid + k] - x) left = mid + 1
3. else right = mid
4. Once we get left then , return elements left + k

SC: O(1)
TC: O(log (n -k) + k)
n-> no. of elements
k-> window size

*/
class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {

        // Init left and right
        int left = 0;
        int right = arr.size() - k;

        // Binary search
        while(left < right)
        {
            // get mid
            int mid = left + (right - left) / 2;

            // Compare the elements at extreme of window
            if( x - arr[mid] > arr[mid + k] - x) left = mid + 1;
            else right = mid;
        }

        vector<int> result;

        // return elements from left to left + k
        for(int i = left; i < left + k; i++) result.push_back(arr[i]);

        return result;
    }
};