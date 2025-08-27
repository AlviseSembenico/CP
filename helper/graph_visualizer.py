import matplotlib.pyplot as plt
import networkx as nx
import numpy as np
from matplotlib.patches import Arc, FancyArrowPatch


def create_hierarchical_layout(G):
    """Create a hierarchical layout for DAG to minimize edge crossings"""
    # Simple hierarchical layout based on longest path
    layers = {}

    # Calculate the longest path from each node
    for node in G.nodes():
        try:
            longest_path = nx.dag_longest_path_length(G, weight=None)
            layers[node] = 0
        except:
            layers[node] = 0

    # Position nodes in layers
    pos = {}
    layer_counts = {}

    for node, layer in layers.items():
        if layer not in layer_counts:
            layer_counts[layer] = 0
        layer_counts[layer] += 1

    layer_positions = {}
    for node, layer in layers.items():
        if layer not in layer_positions:
            layer_positions[layer] = 0

        x = layer_positions[layer] - (layer_counts[layer] - 1) / 2
        y = -layer  # Higher layers at top
        pos[node] = (x, y)
        layer_positions[layer] += 1

    return pos


def draw_curved_edges(G, pos):
    """Draw curved edges to minimize visual overlap"""
    for edge in G.edges():
        start_node, end_node = edge
        start_pos = pos[start_node]
        end_pos = pos[end_node]

        # Check if there's a reverse edge to curve differently
        has_reverse = G.has_edge(end_node, start_node)

        if start_node == end_node:
            # Self loop
            draw_self_loop(start_pos, start_node)
        elif has_reverse and start_node < end_node:
            # Draw curved edge (only draw once for bidirectional)
            draw_bidirectional_edges(start_pos, end_pos, start_node, end_node)
        elif not has_reverse or start_node < end_node:
            # Regular edge
            draw_single_edge(start_pos, end_pos)


def draw_self_loop(pos, node):
    """Draw a self-loop"""
    x, y = pos
    circle = plt.Circle(
        (x + 0.15, y + 0.15), 0.1, fill=False, color="gray", linewidth=2
    )
    plt.gca().add_patch(circle)
    # Add arrow
    arrow = FancyArrowPatch(
        (x + 0.25, y + 0.15),
        (x + 0.2, y + 0.1),
        arrowstyle="->",
        color="gray",
        linewidth=2,
    )
    plt.gca().add_patch(arrow)


def draw_bidirectional_edges(start_pos, end_pos, start_node, end_node):
    """Draw two curved edges for bidirectional connections"""
    # Calculate control points for curves
    mid_x = (start_pos[0] + end_pos[0]) / 2
    mid_y = (start_pos[1] + end_pos[1]) / 2

    # Perpendicular offset
    dx = end_pos[0] - start_pos[0]
    dy = end_pos[1] - start_pos[1]
    length = np.sqrt(dx**2 + dy**2)

    if length > 0:
        # Normalize and rotate 90 degrees
        offset_x = -dy / length * 0.3
        offset_y = dx / length * 0.3

        # First curve (upward)
        control1 = (mid_x + offset_x, mid_y + offset_y)
        draw_curved_arrow(start_pos, end_pos, control1, "blue")

        # Second curve (downward)
        control2 = (mid_x - offset_x, mid_y - offset_y)
        draw_curved_arrow(end_pos, start_pos, control2, "red")


def draw_single_edge(start_pos, end_pos):
    """Draw a single straight edge with arrow"""
    arrow = FancyArrowPatch(
        start_pos,
        end_pos,
        arrowstyle="->",
        color="gray",
        linewidth=2,
        shrinkA=20,
        shrinkB=20,
    )
    plt.gca().add_patch(arrow)


def draw_curved_arrow(start, end, control, color):
    """Draw a curved arrow using Bezier curve"""
    # Create curved path
    t = np.linspace(0, 1, 100)
    curve_x = (1 - t) ** 2 * start[0] + 2 * (1 - t) * t * control[0] + t**2 * end[0]
    curve_y = (1 - t) ** 2 * start[1] + 2 * (1 - t) * t * control[1] + t**2 * end[1]

    plt.plot(curve_x, curve_y, color=color, linewidth=2, alpha=0.7)

    # Add arrowhead
    arrow_start = (curve_x[-5], curve_y[-5])
    arrow_end = (curve_x[-1], curve_y[-1])
    arrow = FancyArrowPatch(
        arrow_start, arrow_end, arrowstyle="->", color=color, linewidth=2
    )
    plt.gca().add_patch(arrow)


def visualize_graph(edges):
    """Create and display a directed graph visualization with minimal edge overlap"""
    # Create directed graph
    G = nx.DiGraph()

    # Add edges
    G.add_edges_from(edges)

    # Get all nodes (in case some nodes have no edges)
    all_nodes = set()
    for a, b in edges:
        all_nodes.add(a)
        all_nodes.add(b)

    G.add_nodes_from(all_nodes)

    # Try different layouts to minimize overlap
    layouts = [
        nx.kamada_kawai_layout(G),  # Force-directed, good for minimizing crossings
        nx.spring_layout(G, k=5, iterations=100),  # More spacing
        nx.circular_layout(G),  # Circular arrangement
    ]

    # Choose the best layout (you can implement scoring here)
    pos = layouts[0]  # Kamada-Kawai is generally good for minimal crossings

    # If it's a DAG, try hierarchical layout
    if nx.is_directed_acyclic_graph(G):
        try:
            pos = nx.nx_agraph.graphviz_layout(G, prog="dot")
        except:
            # Fallback to manual hierarchical layout
            pos = create_hierarchical_layout(G)

    # Create figure
    plt.figure(figsize=(14, 10))

    # Draw nodes with larger size for better visibility
    nx.draw_networkx_nodes(G, pos, node_color="lightblue", node_size=1200, alpha=0.8)

    # Draw node labels
    nx.draw_networkx_labels(G, pos, font_size=12, font_weight="bold")

    # Draw edges with curved arrows to reduce overlap
    draw_curved_edges(G, pos)

    # Add edge labels with better positioning
    edge_labels = {(a, b): f"{a}→{b}" for a, b in edges}
    nx.draw_networkx_edge_labels(
        G,
        pos,
        edge_labels,
        font_size=8,
        bbox=dict(boxstyle="round,pad=0.1", facecolor="white", alpha=0.7),
    )

    plt.title("Directed Graph Visualization", fontsize=16, fontweight="bold")
    plt.axis("off")
    plt.tight_layout()

    # Display graph info
    print(f"\nGraph Information:")
    print(f"Nodes: {sorted(G.nodes())}")
    print(f"Edges: {list(G.edges())}")
    print(f"Number of nodes: {G.number_of_nodes()}")
    print(f"Number of edges: {G.number_of_edges()}")

    # Check for cycles
    if nx.is_directed_acyclic_graph(G):
        print("Graph is acyclic (DAG)")
        try:
            topo_sort = list(nx.topological_sort(G))
            print(f"Topological sort: {topo_sort}")
        except:
            pass
    else:
        print("Graph contains cycles")
        try:
            cycles = list(nx.simple_cycles(G))
            print(f"Found cycles: {cycles}")
        except:
            pass

    plt.show()


def read_from_file(filename):
    """Read graph from file format"""
    edges = []
    with open(filename, "r") as f:
        lines = f.readlines()
        m = int(lines[0].strip())
        for i in range(1, m + 1):
            if i < len(lines):
                a, b = map(int, lines[i].strip().split())
                edges.append((a, b))
    return edges


def main():
    edges = read_from_file("input.txt")
    visualize_graph(edges)


if __name__ == "__main__":
    main()
