import numpy as np


class HexagonalMatrix:
    def __init__(self, base, mid, height):
        self.base = base
        self.mid = mid
        self.height = height
        self.matrix = np.zeros((height, mid), dtype=int)
        self.initialize_matrix()
        self.set_values()

    def initialize_matrix(self):
        for i in range(self.mid - self.base):
            diff = self.mid - self.base - i
            self.matrix[i, -diff:] = -1
            self.matrix[-i - 1, -diff:] = -1

    def set_values(self):
        self.matrix[-4, 3] = 19
        self.matrix[10, 7] = 38
        self.matrix[-7, 15] = 11
        # self.matrix[1, 5] = 7
        # self.matrix[7, 7] = 8
        self.matrix[-1, 5] = 6
        # self.matrix[-6, 2] = 6
        # self.matrix[-9, 9] = 6
        # self.matrix[9, 4] = 6
        # self.matrix[5, 12] = 6
        # self.matrix[8, 10] = 4
        # self.matrix[9, 14] = 3
        # self.matrix[3, 9] = 3
        # self.matrix[6, 0] = 1

    def get_right_diag(self, i, j, top=None):
        t = self.matrix.shape[1]
        k = t - 1 - i - j
        temp_matrix = np.fliplr(self.matrix)
        slanted_diag = temp_matrix.diagonal(k)[::-1]

        d = min(0, j - 10)
        right_diag = self.matrix[: min(i - 1, 10), 10 + d]
        diag = np.concatenate((slanted_diag, right_diag))

        if top is None:
            return diag
        if top:
            return diag[j + 1 :]

        return diag[:j]

    def get_left_diag(self, i, j, top=None):
        diag = self.matrix[:, j]
        if top is None:
            return diag
        if top:
            return diag[:i]
        return diag[i + 1 :]

    def get_all_diag(self, i, j):
        return [
            self.get_right_diag(i, j, True),
            self.get_right_diag(i, j, False),
            self.get_left_diag(i, j, True),
            self.get_left_diag(i, j, False),
        ]

    def set_values_on_diag(self, i, j, values, diag_direction="right", top=False):
        for index, value in enumerate(values, start=1):
            if diag_direction == "right":
                if top:
                    self.matrix[i - index, j + index] = value
                else:
                    self.matrix[i + index, j - index] = value
            if diag_direction == "left":
                if top:
                    self.matrix[i - index, j] = value
                else:
                    self.matrix[i + index, j] = value
            if diag_direction == "row":
                if top:
                    self.matrix[i, j + index] = value
                else:
                    self.matrix[i, j - index] = value

    def get_free_size(self, diag):
        res = 0
        for d in diag:
            if d != 0:
                return res
            res += 1
        return res

    def get_diag_and_row_segments(self, i, j):
        # Get the row segments
        row_before = self.matrix[i, :j]  # Row segment before the point (excluding j)
        row_after = self.matrix[i, j + 1 :]  # Row segment after the point (excluding j)

        # Get the diagonals and split them based on the position (i, j)
        right_diag_top = self.get_right_diag(i, j, top=True)
        right_diag_bottom = self.get_right_diag(i, j, top=False)
        left_diag_top = self.get_left_diag(i, j, top=True)
        left_diag_bottom = self.get_left_diag(i, j, top=False)

        return {
            "row_after": row_after,
            "row_before": row_before,
            "right_diag_top": right_diag_top,
            "right_diag_bottom": right_diag_bottom,
            "left_diag_top": left_diag_top,
            "left_diag_bottom": left_diag_bottom,
        }

    def process_matrix(self):
        def find_combinations(current_combo, current_sum, index, m, limits):
            # Base case: if we have filled all 6 slots
            if index == 6:
                if current_sum == m:
                    return [current_combo]
                return []

            # Recursive case: try all values for current index from 0 to limits[index]
            res = []
            for i in range(min(limits[index], m - current_sum) + 1):
                res += find_combinations(
                    current_combo + [i], current_sum + i, index + 1, m, limits
                )
            return res

        def generate_combinations(m, limits):
            return find_combinations([], 0, 0, m, limits)

        def assign(matrix, indexes, _i):
            if _i >= len(indexes):
                # combination found
                return [matrix]
            i, j = indexes[_i]
            value = self.matrix[i, j]
            diags = list(self.get_diag_and_row_segments(i, j).values())
            m_sizes = [self.get_free_size(d) for d in diags]
            diag_directions = ["row", "row", "right", "right", "left", "left"]

            combinations = generate_combinations(value, m_sizes)
            if not combinations:
                # no combinations found
                return []

            res = []
            for combination in combinations:
                matrix_ = matrix.copy()
                self.matrix = matrix_
                top = True
                for diag, diag_value, direction in zip(
                    diags, combination, diag_directions
                ):
                    if diag_value != 0:
                        self.set_values_on_diag(
                            i,
                            j,
                            [value] * diag_value,
                            diag_direction=direction,
                            top=top,
                        )
                    top = not top
                # assert (self.matrix == value).sum() == value + 1
                # next step recursive backtracking
                res += assign(matrix_, indexes, _i + 1)

            return res

        ind = np.unravel_index(np.argsort(self.matrix, axis=None), self.matrix.shape)
        n_zero_ind = [(i, j) for i, j in zip(*ind) if self.matrix[i, j] > 0]
        return assign(self.matrix.copy(), n_zero_ind, 0)


# Example Usage
hex_matrix = HexagonalMatrix(base=10, mid=19, height=19)
print("Initial Matrix:\n", hex_matrix.matrix)

matrices = hex_matrix.process_matrix()

# Define the file path
file_path = "matrices_output.txt"

# Open the file in write mode to overwrite if it exists
with open(file_path, "w") as file:
    for i, matrix in enumerate(matrices[:5]):
        file.write(f"Matrix {i+1}:\n")
        np.savetxt(
            file, matrix, fmt="%0.8f"
        )  # Save the matrix to the file with 8 decimal precision
        file.write("\n")  # Add a newlin
