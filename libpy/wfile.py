from sys import argv

def main() -> int:
    if len(argv) < 2:
        print("Missing Parameters")
        return 1

    msg = argv[1]
    with open("me", "a") as f:
        f.write(msg)
        f.write('\n')

    return 0

if __name__ == "__main__":
    main()
