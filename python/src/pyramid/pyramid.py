from sys import argv

def draw_pyramid(height: int, symbol: str='*') -> None:
    for line in range(1, height+1):
        for col in range(0, line):
            print(symbol + " ", end="")
        print("")

if __name__ == "__main__":
    try:
        height = int(argv[1])
    except (ValueError, IndexError):
        height = 5
    draw_pyramid(height)
