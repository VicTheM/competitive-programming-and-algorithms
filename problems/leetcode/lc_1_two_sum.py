"""
Problem: Two Sum
Link: https://leetcode.com/problems/two-sum/
Difficulty: Easy

Problem Statement:
Given an array of integers nums and an integer target, return indices of the 
two numbers such that they add up to target.

Approach: 
Use a hash map to store each number and its index as we iterate through the array.
For each number, check if (target - current_number) exists in the hash map.

Time Complexity: O(n)
Space Complexity: O(n)
"""

def two_sum(nums, target):
    """
    Find two numbers in the array that sum to target.
    
    Args:
        nums: List of integers
        target: Target sum
        
    Returns:
        List of two indices whose values sum to target
    """
    num_to_index = {}
    
    for i, num in enumerate(nums):
        complement = target - num
        
        if complement in num_to_index:
            return [num_to_index[complement], i]
        
        num_to_index[num] = i
    
    return []  # No solution found

# Test cases
def test_two_sum():
    # Test case 1: Basic case
    nums1 = [2, 7, 11, 15]
    target1 = 9
    result1 = two_sum(nums1, target1)
    print(f"Input: nums = {nums1}, target = {target1}")
    print(f"Output: {result1}")
    print(f"Expected: [0, 1]\n")
    
    # Test case 2: Different positions
    nums2 = [3, 2, 4]
    target2 = 6
    result2 = two_sum(nums2, target2)
    print(f"Input: nums = {nums2}, target = {target2}")
    print(f"Output: {result2}")
    print(f"Expected: [1, 2]\n")
    
    # Test case 3: Same number twice
    nums3 = [3, 3]
    target3 = 6
    result3 = two_sum(nums3, target3)
    print(f"Input: nums = {nums3}, target = {target3}")
    print(f"Output: {result3}")
    print(f"Expected: [0, 1]\n")

if __name__ == "__main__":
    test_two_sum()