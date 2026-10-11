class Solution {
private:
    // Helper function to check if a split is possible with a max sum limit (mid)
    bool isPossible(vector<int>& nums, int k, int mid) {
        int subarrayCount = 1; // Pehla subarray shuru karte hain
        int currentSum = 0;    // Current subarray ka total sum

        for (int i = 0; i < nums.size(); i++) {
            // Agar koi akela element hi 'mid' limit se bada hai, to ye split possible nahi hai
            if (nums[i] > mid) {
                return false;
            }

            // Agar current element ko jodne se sum limit (mid) ko cross karta hai
            if (currentSum + nums[i] > mid) {
                subarrayCount++;    // Naya subarray shuru karo
                currentSum = nums[i]; // Naye subarray ka pehla element set karo

                // Agar subarrays ki sankhya 'k' se zyada ho jaye, to limit galat hai
                if (subarrayCount > k) {
                    return false;
                }
            } 
            else {
                // Limit ke andar hai, to isi subarray mein element add karte raho
                currentSum += nums[i];
            }
        }
        return true; // Successfully split ho gaya
    }

public:
    int splitArray(vector<int>& nums, int k) {
        int start = 0;
        int end = 0;

        // Search Space define karna:
        // 'start' hoga array ka max element (minimum possible largest sum)
        // 'end' hoga saare elements ka total sum (agar sirf 1 hi subarray bane)
        for (int i = 0; i < nums.size(); i++) {
            start = max(start, nums[i]);
            end += nums[i];
        }

        int ans = end;

        // Binary Search Loop
        while (start <= end) {
            int mid = start + (end - start) / 2; // Temporary maximum sum limit

            // Agar 'mid' limit ke sath array ko 'k' parts mein split kar sakte hain
            if (isPossible(nums, k, mid)) {
                ans = mid;        // Ise save kar lo (ho sakta hai yehi best answer ho)
                end = mid - 1;    // Aur chota answer dhoondne ke liye left side jao (Minimize)
            } 
            else {
                start = mid + 1;  // Agar possible nahi hai, to limit ko badhao (right side jao)
            }
        }
        return ans; // Final optimized largest sum return hoga
    }
};
