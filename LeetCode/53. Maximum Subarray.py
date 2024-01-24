    def maxSubArray(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        temp = nums[0];
        i = 1;
        while i< (len(nums)):
            if(nums[i]<nums[i]+nums[i-1]):
                nums[i] = nums[i]+nums[i-1]
            if(temp<nums[i]):
                temp = nums[i];
            i = i + 1;
        return temp;
