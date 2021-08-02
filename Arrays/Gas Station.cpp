/*
 Idea is to start with the first position and keep track of total magic for the
 entire trip and curr magic for current starting position
 
 If curr magic drops below 0 then choose a new starting position which is increment index by 1
 and reset curr magic to 0 
 
 ------
 Time and Space complexity analysis as function of n where n is
 number of elements in magic/dist vector
 
 Space complexity: O(1) - no extra space required
 Time complexity: O(n) - one pass over the magic/dist vector

*/
int optimalPoint(vector<int> magic, vector<int> dist) {
    int total_magic = 0;
    int curr_magic = 0;
    int starting_position = 0;
    for(auto i = 0; i < magic.size(); i++) {
        total_magic += magic[i] - dist[i];
        curr_magic += magic[i] - dist[i];
        if(curr_magic < 0) {
            starting_position = i + 1;
            curr_magic = 0;
        }
    }
    
    return total_magic >= 0 ? starting_position : -1;
}
int main()