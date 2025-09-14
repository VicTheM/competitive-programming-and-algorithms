"""
Stack Implementation using Dynamic Array

A Last-In-First-Out (LIFO) data structure implementation.

Operations:
- push(item): Add item to top - O(1) amortized
- pop(): Remove and return top item - O(1)
- peek()/top(): Return top item without removing - O(1)
- is_empty(): Check if stack is empty - O(1)
- size(): Get number of elements - O(1)

Use Cases:
- Function call management
- Expression evaluation
- Undo operations
- DFS traversal
- Balanced parentheses checking
"""

class Stack:
    def __init__(self):
        """Initialize an empty stack."""
        self._items = []
    
    def push(self, item):
        """
        Add an item to the top of the stack.
        
        Args:
            item: The item to add
        """
        self._items.append(item)
    
    def pop(self):
        """
        Remove and return the top item from the stack.
        
        Returns:
            The top item from the stack
            
        Raises:
            IndexError: If the stack is empty
        """
        if self.is_empty():
            raise IndexError("pop from empty stack")
        return self._items.pop()
    
    def peek(self):
        """
        Return the top item without removing it.
        
        Returns:
            The top item from the stack
            
        Raises:
            IndexError: If the stack is empty
        """
        if self.is_empty():
            raise IndexError("peek from empty stack")
        return self._items[-1]
    
    def is_empty(self):
        """
        Check if the stack is empty.
        
        Returns:
            True if stack is empty, False otherwise
        """
        return len(self._items) == 0
    
    def size(self):
        """
        Get the number of items in the stack.
        
        Returns:
            Number of items in the stack
        """
        return len(self._items)
    
    def __str__(self):
        """String representation of the stack."""
        return f"Stack({self._items})"

# Example usage and test cases
def test_stack():
    print("Testing Stack Implementation:")
    print("=" * 30)
    
    # Create a new stack
    stack = Stack()
    print(f"Created empty stack: {stack}")
    print(f"Is empty: {stack.is_empty()}")
    print(f"Size: {stack.size()}\n")
    
    # Push elements
    print("Pushing elements: 1, 2, 3")
    for i in [1, 2, 3]:
        stack.push(i)
        print(f"Pushed {i}, stack: {stack}")
    print()
    
    # Peek at top element
    print(f"Peek: {stack.peek()}")
    print(f"Stack after peek: {stack}\n")
    
    # Pop elements
    print("Popping elements:")
    while not stack.is_empty():
        popped = stack.pop()
        print(f"Popped: {popped}, remaining: {stack}")
    print()
    
    # Test error handling
    print("Testing error handling:")
    try:
        stack.pop()
    except IndexError as e:
        print(f"Expected error: {e}")
    
    try:
        stack.peek()
    except IndexError as e:
        print(f"Expected error: {e}")

if __name__ == "__main__":
    test_stack()