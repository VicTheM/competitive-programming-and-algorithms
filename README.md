# Competitive Programming and Algorithms

[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)

A comprehensive collection of solutions to world-renowned programming problems and detailed explanations of classic algorithms. This repository serves as both a learning resource and a reference for competitive programming enthusiasts and computer science students.

## 🎯 Purpose

This repository aims to:
- Provide clear, well-documented implementations of fundamental algorithms
- Offer solutions to classic competitive programming problems
- Serve as a learning resource with detailed explanations
- Bridge the gap between theoretical knowledge and practical implementation

## 📁 Repository Structure

```
competitive-programming-and-algorithms/
├── README.md                 # This comprehensive guide
├── LICENSE                   # MIT License
├── .gitignore               # Git ignore rules
├── algorithms/              # Core algorithm implementations (planned)
│   ├── graph/              # Graph algorithms
│   ├── sorting/            # Sorting algorithms
│   ├── searching/          # Searching algorithms
│   └── dynamic-programming/ # DP solutions
├── problems/               # Problem solutions (planned)
│   ├── leetcode/          # LeetCode solutions
│   ├── codeforces/        # Codeforces solutions
│   └── hackerrank/        # HackerRank solutions
└── docs/                  # Additional documentation (planned)
```

## 🚀 Getting Started

1. **Clone the repository:**
   ```bash
   git clone https://github.com/VicTheM/competitive-programming-and-algorithms.git
   cd competitive-programming-and-algorithms
   ```

2. **Navigate through the folders** to find algorithms or problems of interest
3. **Read the documentation** provided with each implementation
4. **Run the code** in your preferred environment

## 🔍 Algorithm Deep Dive: Dijkstra's Shortest Path Algorithm

### Overview

Dijkstra's algorithm is a fundamental graph algorithm that finds the shortest path between nodes in a weighted graph. Developed by Dutch computer scientist Edsger W. Dijkstra in 1956, it's one of the most important algorithms in computer science and has countless real-world applications.

### 🎯 When to Use Dijkstra's Algorithm

**Perfect for:**
- GPS navigation systems (finding shortest routes)
- Network routing protocols
- Social network analysis (finding degrees of separation)
- Game pathfinding (AI movement)
- Resource allocation problems

**Requirements:**
- Weighted graph (edges have costs/distances)
- Non-negative edge weights
- Need shortest path from source to all vertices OR to a specific target

### 🧠 How It Works

Dijkstra's algorithm uses a **greedy approach** with the following key insight:
> "The shortest path to any vertex goes through vertices that are themselves closest to the source."

#### Core Concepts:

1. **Distance Array**: Keeps track of shortest known distance to each vertex
2. **Priority Queue**: Always processes the vertex with minimum distance first
3. **Relaxation**: Updates distances when shorter paths are found

### 📋 Step-by-Step Algorithm

```
1. Initialize distances to all vertices as INFINITY
2. Set distance to source vertex as 0
3. Create a priority queue and add source vertex
4. While priority queue is not empty:
   a. Extract vertex with minimum distance
   b. For each neighbor of current vertex:
      - Calculate new distance through current vertex
      - If new distance < known distance:
        * Update distance
        * Add neighbor to priority queue
5. Return distance array
```

### 💻 Implementation

Here's a clean Python implementation:

```python
import heapq
from collections import defaultdict

def dijkstra(graph, start):
    """
    Find shortest paths from start vertex to all other vertices
    
    Args:
        graph: Dictionary where graph[u] = [(v, weight), ...]
        start: Starting vertex
    
    Returns:
        Dictionary with shortest distances from start to each vertex
    """
    # Initialize distances
    distances = {vertex: float('infinity') for vertex in graph}
    distances[start] = 0
    
    # Priority queue: (distance, vertex)
    pq = [(0, start)]
    visited = set()
    
    while pq:
        current_distance, current_vertex = heapq.heappop(pq)
        
        # Skip if we've already processed this vertex
        if current_vertex in visited:
            continue
            
        visited.add(current_vertex)
        
        # Check all neighbors
        for neighbor, weight in graph[current_vertex]:
            distance = current_distance + weight
            
            # Relaxation step
            if distance < distances[neighbor]:
                distances[neighbor] = distance
                heapq.heappush(pq, (distance, neighbor))
    
    return distances

def dijkstra_with_path(graph, start, end):
    """
    Find shortest path and distance from start to end vertex
    
    Returns:
        Tuple of (shortest_distance, shortest_path)
    """
    distances = {vertex: float('infinity') for vertex in graph}
    previous = {vertex: None for vertex in graph}
    distances[start] = 0
    
    pq = [(0, start)]
    visited = set()
    
    while pq:
        current_distance, current_vertex = heapq.heappop(pq)
        
        if current_vertex == end:
            break
            
        if current_vertex in visited:
            continue
            
        visited.add(current_vertex)
        
        for neighbor, weight in graph[current_vertex]:
            distance = current_distance + weight
            
            if distance < distances[neighbor]:
                distances[neighbor] = distance
                previous[neighbor] = current_vertex
                heapq.heappush(pq, (distance, neighbor))
    
    # Reconstruct path
    path = []
    current = end
    while current is not None:
        path.append(current)
        current = previous[current]
    path.reverse()
    
    return distances[end], path if path[0] == start else []

# Example usage
if __name__ == "__main__":
    # Create a sample graph
    graph = {
        'A': [('B', 4), ('C', 2)],
        'B': [('C', 1), ('D', 5)],
        'C': [('D', 8), ('E', 10)],
        'D': [('E', 2)],
        'E': []
    }
    
    # Find shortest distances from A
    distances = dijkstra(graph, 'A')
    print("Shortest distances from A:", distances)
    
    # Find shortest path from A to E
    distance, path = dijkstra_with_path(graph, 'A', 'E')
    print(f"Shortest path from A to E: {path} (distance: {distance})")
```

### 🔢 Complexity Analysis

**Time Complexity:** O((V + E) log V)
- V = number of vertices
- E = number of edges
- log V factor comes from priority queue operations

**Space Complexity:** O(V)
- For storing distances, previous vertices, and priority queue

**Why this complexity?**
- Each vertex is extracted from priority queue once: O(V log V)
- Each edge is relaxed at most once: O(E log V)
- Total: O((V + E) log V)

### 🎨 Visual Example

Let's trace through a simple example:

```
Graph:
    A ----4---- B
    |           |
    2           1
    |           |
    C ----8---- D
         \     /
          10  2
           \ /
            E

Step-by-step execution from vertex A:

Initial: distances = {A: 0, B: ∞, C: ∞, D: ∞, E: ∞}

Step 1: Process A (distance = 0)
- Update B: 0 + 4 = 4
- Update C: 0 + 2 = 2
- distances = {A: 0, B: 4, C: 2, D: ∞, E: ∞}

Step 2: Process C (distance = 2)
- Update D: 2 + 8 = 10
- Update E: 2 + 10 = 12
- distances = {A: 0, B: 4, C: 2, D: 10, E: 12}

Step 3: Process B (distance = 4)
- Update D: 4 + 1 = 5 (better than 10!)
- distances = {A: 0, B: 4, C: 2, D: 5, E: 12}

Step 4: Process D (distance = 5)
- Update E: 5 + 2 = 7 (better than 12!)
- distances = {A: 0, B: 4, C: 2, D: 5, E: 7}

Final shortest distances: {A: 0, B: 4, C: 2, D: 5, E: 7}
Shortest path A → E: A → C → B → D → E (total distance: 7)
```

### ⚡ Optimizations and Variations

1. **Early Termination**: Stop when target vertex is reached
2. **Bidirectional Dijkstra**: Search from both start and end
3. **A* Algorithm**: Use heuristics for faster pathfinding
4. **All-Pairs Shortest Path**: Use Floyd-Warshall for dense graphs

### 🚨 Common Pitfalls

1. **Negative Weights**: Dijkstra doesn't work with negative edge weights (use Bellman-Ford instead)
2. **Forgetting to Check Visited**: Can lead to infinite loops
3. **Wrong Priority Queue**: Using max-heap instead of min-heap
4. **Not Handling Disconnected Graphs**: Some vertices may remain unreachable

### 🌟 Real-World Applications

1. **GPS Navigation**: Google Maps, Waze
2. **Network Protocols**: OSPF routing
3. **Social Networks**: Friend suggestions, influence propagation
4. **Game Development**: NPC pathfinding, tactical AI
5. **Logistics**: Supply chain optimization
6. **Robotics**: Motion planning

## 🤝 Contributing

Contributions are welcome! Please feel free to submit a Pull Request. For major changes, please open an issue first to discuss what you would like to change.

### Guidelines:
1. **Code Quality**: Write clean, documented code
2. **Testing**: Include test cases for your implementations
3. **Documentation**: Explain your algorithm/solution clearly
4. **Performance**: Consider time and space complexity

## 📚 Additional Resources

### Books:
- "Introduction to Algorithms" by Cormen, Leiserson, Rivest, and Stein
- "Algorithm Design" by Kleinberg and Tardos
- "Competitive Programming" by Steven Halim

### Online Platforms:
- [LeetCode](https://leetcode.com/)
- [Codeforces](https://codeforces.com/)
- [HackerRank](https://www.hackerrank.com/)
- [AtCoder](https://atcoder.jp/)

### Visualization Tools:
- [VisuAlgo](https://visualgo.net/)
- [Algorithm Visualizer](https://algorithm-visualizer.org/)

## 📄 License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

---

**Happy Coding! 🚀**

*This repository represents personal findings and understanding. While every effort is made to ensure accuracy, please verify implementations for critical applications.*
