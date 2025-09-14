# Contributing to Competitive Programming and Algorithms

Thank you for your interest in contributing to this repository! This guide will help you understand the project structure and contribution guidelines.

## Repository Structure

```
├── algorithms/              # Algorithm implementations
│   ├── graph/              # Graph algorithms
│   ├── dynamic-programming/ # DP solutions
│   ├── greedy/             # Greedy algorithms
│   ├── string/             # String algorithms
│   ├── sorting/            # Sorting algorithms
│   ├── searching/          # Search algorithms
│   └── math/               # Mathematical algorithms
├── data-structures/        # Data structure implementations
│   ├── linear/             # Arrays, lists, stacks, queues
│   ├── trees/              # Trees and tree-based structures
│   ├── graphs/             # Graph representations
│   ├── heaps/              # Heap implementations
│   └── hash-tables/        # Hash-based structures
├── problems/               # Problem solutions by platform
│   ├── leetcode/           # LeetCode solutions
│   ├── codeforces/         # Codeforces solutions
│   ├── atcoder/            # AtCoder solutions
│   ├── hackerrank/         # HackerRank solutions
│   ├── codechef/           # CodeChef solutions
│   └── spoj/               # SPOJ solutions
└── templates/              # Code templates and boilerplate
```

## Contribution Guidelines

### Adding Algorithm Implementations

1. Place the algorithm in the appropriate subdirectory under `algorithms/`
2. Include comprehensive documentation:
   - Brief description of the algorithm
   - Time and space complexity analysis
   - When to use this algorithm
   - Example usage

### Adding Data Structure Implementations

1. Place implementations in the appropriate subdirectory under `data-structures/`
2. Include:
   - Clear interface documentation
   - Complexity analysis for all operations
   - Example usage
   - Test cases demonstrating functionality

### Adding Problem Solutions

1. Choose the appropriate platform directory under `problems/`
2. Use descriptive file names: `problem_id_brief_description.ext`
3. Include at the top of each solution:
   ```
   Problem: [Problem Title]
   Link: [URL to problem]
   Difficulty: [Easy/Medium/Hard]
   
   Approach: [Brief explanation of your approach]
   Time Complexity: O(...)
   Space Complexity: O(...)
   ```

### Code Quality Standards

- **Readability**: Write clean, well-commented code
- **Efficiency**: Focus on optimal time and space complexity
- **Testing**: Include test cases when applicable
- **Documentation**: Explain complex logic and edge cases

### File Naming Conventions

- Use lowercase with underscores: `binary_search.cpp`
- Include relevant keywords: `dijkstra_shortest_path.py`
- For problems, include platform identifier: `lc_1480_two_sum.cpp`

### Language Support

We accept solutions in:
- C++ (preferred for competitive programming)
- Python
- Java
- Other languages are welcome

### Submitting Changes

1. Fork the repository
2. Create a feature branch for your changes
3. Follow the structure and naming conventions
4. Add appropriate documentation
5. Test your implementations
6. Submit a pull request with a clear description

## Getting Started

1. Use the templates in `templates/` for consistent code structure
2. Check existing implementations for reference
3. Read the README files in each directory for specific guidelines
4. Start with simpler algorithms or problems if you're new to the repository

## Questions?

If you have questions about contributing, feel free to open an issue or reach out to the maintainers.

Happy coding! 🚀