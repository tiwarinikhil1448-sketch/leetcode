#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> freq;
        
        
        for (int num : arr) {
            freq[num]++;
        }
        
        unordered_set<int> seenOccurrences;
        
        
        for (const auto& pair : freq) {
            
            if (!seenOccurrences.insert(pair.second).second) {
                return false;
            }
        }
        
        return true;
    }
};
