def ind(a):
    return ord(a) - ord("A")


def comp(s):
    counter = [0] * 30
    for c in s:
        counter[ord(c) - ord("A")] += 1
    res = ""
    res += "T" * counter[ind("T")]
    res += "N" * counter[ind("N")]
    res += "F" * counter[ind("F")]
    for i in range(ord("A"), ord("Z") + 1):
        le = chr(i)
        if le in {"T", "N", "F"}:
            continue
        res += le * counter[ind(le)]
    return res


def main():

    tests = int(input())

    for _ in range(tests):
        s = input()
        print(comp(s))


main()
