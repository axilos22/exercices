from timeit import default_timer as timer
from datetime import timedelta


def memoized_fibonacci(rank: int, memo={}) -> int:
    if rank in memo:
        return memo.get(rank)
    if rank <= 2:
        return 1
    else:
        result = memoized_fibonacci(rank - 1, memo) + memoized_fibonacci(rank - 2, memo)
        memo[rank] = result
        return result


def fibonacci(rank: int) -> int:
    if rank <= 2:
        return 1
    else:
        return fibonacci(rank - 1) + fibonacci(rank - 2)


if __name__ == "__main__":
    n = 38
    start = timer()
    print(f"Fibonacci of {n} = {memoized_fibonacci(n)}")
    end = timer()
    print(timedelta(seconds=end - start))
