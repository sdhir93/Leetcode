/*
Problem: https://leetcode.com/problems/meeting-scheduler/

Solution:

- Sort using the custom compare i.e. start times
- Go over the slots simultaneously
    - calculate duration by min(end1, end2) - max(start2, start2)
    - if calcualted duration is greater than or equal to required duration,
      return the max(start1, start2), .. + 8
    - If calcualted duration is less than required then we need to advance the pointers
    - Advance first slot if its end time is less
    - Advance second slot if its end time is less
    - If end time are equal, advance both

*/
class Solution {
public:
    vector<int> minAvailableDuration(vector<vector<int>>& slots1, vector<vector<int>>& slots2, int duration) {

        // Init the sizes and pointers
        int m = slots1.size();
        int n = slots2.size();
        int i = 0;
        int j = 0;

        // Sort both slots using custom comparator
        sort(slots1.begin(), slots1.end(), cmp());
        sort(slots2.begin(), slots2.end(), cmp());

        // While both indices are greater than their max values
        while(i < m && j < n)
        {
            // Get the start and end times
            int start_1 = slots1[i][0];
            int start_2 = slots2[j][0];
            int end_1 = slots1[i][1];
            int end_2 = slots2[j][1];

            // Calcualte duration
            int curr_duration = min(end_1, end_2) - max(start_1, start_2);

            // If current duration is less,
            // decide whether to increment i or j or both
            if(curr_duration < duration)
            {
                // If end time of slot1 is less, advance i
                if(end_1 < end_2) i++;

                // If end time of slot2 is less, advance j
                else if(end_2 < end_1) j++;

                // If both end times are equal, advance both
                else
                {
                    i++;j++;
                }
            }

            // If current duration is greater than or equal to required duration
            else
            {
                // Return the required answer
                return {max(start_1, start_2), max(start_1, start_2) + duration};
            }
        }

        // Return empty vector
        return {};

    }

    // Custom comparator that compares start times
    struct cmp {
        bool operator()(const vector<int>& x, const vector<int>& y) {
            return x[0] < y[0];
        }
    };
};