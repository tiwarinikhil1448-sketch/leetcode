#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> ans;
        int n = nums.size();
        
        // Ek naya array banaya 'ginti' naam ka jiska size n+1 hai aur sabme shuru mein 0 bhara hai
        vector<int> ginti(n + 1, 0);
        
        // Sirf ek loop chalega pure array par
        for (int i = 0; i < n; i++) {
            int current_number = nums[i];
            
            // Agar is number ki ginti pehle se 1 hai, matlab yeh dusri baar aaya hai (Duplicate!)
            if (ginti[current_number] == 1) {
                ans.push_back(current_number);
            } else {
                // Agar pehli baar aaya hai, toh iski ginti 1 kar do
                ginti[current_number] = 1;
            }
        }
        
        return ans;
    }
};