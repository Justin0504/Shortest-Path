# Shortest Path Finder

A C++ implementation for finding shortest paths in directed graphs with support for negative edge weights. This program efficiently processes graph data and responds to multiple source-destination queries.

## Components

### main.cpp (Test Harness)
- Provides the testing framework for evaluating the implementation
- Handles input parsing and output formatting
- Calls the required methods from the shortestP2P implementation


### shortestP2P.cpp (Core Implementation)
Contains the main algorithm implementation with two required methods:

#### 1. readGraph()
- Reads and stores graph information from standard input
- Processes node count, edge count, and all directed edges with weights
- Performs graph initialization and data structure setup
- Handles input validation and error checking

#### 2. distance()
- Computes shortest path for each source-destination query
- Returns the shortest path length as specified output
- Handles special cases:
  - Returns 0 for same source and destination nodes
  - Returns "INF" when no path exists
  - Returns negative values for valid negative-weight paths

## Features
- Supports directed graphs with negative edge weights
- Detects invalid graphs containing negative-weight cycles
- Provides efficient query response for multiple source-destination pairs
- Implements robust error handling and memory management
