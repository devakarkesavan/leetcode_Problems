class Solution:
    def medianOfUniquenessArray(self, nums: List[int]) -> int:        
        n = len(nums)
        lo, hi = 0, n
        while lo < hi: 
            mid = lo + hi >> 1
            val = ii = 0 
            freq = defaultdict(int)
            for i, x in enumerate(nums): 
                freq[x] += 1
                while len(freq) > mid: 
                    freq[nums[ii]] -= 1
                    if freq[nums[ii]] == 0: freq.pop(nums[ii])
                    ii += 1
                val += i-ii+1
            if val < (n*(n+1)//2+1)//2: lo = mid + 1
            else: hi = mid 
        return lo