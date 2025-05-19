N = int(input())


def comp(n):
    print("digit", flush=True)
    input()
    print("digit", flush=True)
    input()

    print("mul 9", flush=True)
    input()

    print("digit", flush=True)
    input()

    print("div 9", flush=True)
    input()

    print(f"mul {n}", flush=True)
    input()

    print("!", flush=True)
    input()


for _ in range(N):
    n = int(input())
    comp(n)
