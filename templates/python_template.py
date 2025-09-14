import sys
from collections import defaultdict, deque, Counter
from heapq import heappush, heappop
import bisect
import math

# Fast input
def fast_input():
    return sys.stdin.readline().strip()

# Input helpers
def get_int():
    return int(fast_input())

def get_ints():
    return list(map(int, fast_input().split()))

def get_string():
    return fast_input()

# Constants
MOD = 10**9 + 7
INF = float('inf')

def solve():
    # Your solution here
    pass

def main():
    t = 1
    # t = get_int()  # Uncomment for multiple test cases
    
    for _ in range(t):
        solve()

if __name__ == "__main__":
    main()