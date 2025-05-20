def diameter(g):
    # get diameter of the graph
    def dfs(node, visited, dist):
        visited.add(node)
        max_dist = dist
        farthest_node = node
        for neighbor in g[node]:
            if neighbor not in visited:
                new_dist, new_node = dfs(neighbor, visited, dist + 1)
                if new_dist > max_dist:
                    max_dist = new_dist
                    farthest_node = new_node
        return max_dist, farthest_node

    visited = set()
    _, farthest_node = dfs(1, visited, 0)
    visited.clear()
    max_dist, _ = dfs(farthest_node, visited, 0)
    return max_dist
