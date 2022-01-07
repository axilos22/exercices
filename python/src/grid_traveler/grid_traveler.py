from timeit import default_timer as timer
from datetime import timedelta


def memoized_grid_traveler(row: int, col: int, memo={}) -> int:
    key = str(row) + "," + str(col)
    if key in memo:
        return memo[key]
    if row == 1 and col == 1:
        return 1
    if row == 0 or col == 0:
        return 0
    memo[key] = memoized_grid_traveler(row - 1, col, memo) + memoized_grid_traveler(row, col - 1, memo)
    return memo[key]


def grid_traveler(row: int, col: int) -> int:
    if row == 1 and col == 1:
        return 1
    if row == 0 or col == 0:
        return 0
    return grid_traveler(row - 1, col) + grid_traveler(row, col - 1)


if __name__ == "__main__":
    # grid_traveler = 02.33s exe
    # memoized_grid_traveler = 0.00030s exe
    m, n = 13, 13
    start = timer()
    print(f"Grid Traveler of {m} x {n} = {memoized_grid_traveler(m, n)}")
    end = timer()
    print(timedelta(seconds=end - start))
