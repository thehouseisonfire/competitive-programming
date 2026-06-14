n, k = map(int, input().split())
a = list(map(int, input().split()))

for _ in range(k):
    l, r = map(int, input().split())
    total = 0
    for idx in range(l - 1, r):
        if (idx - (l - 1)) % 2 == 1:  # even position in subarray → multiply by 2
            total += 2 * a[idx]
        else:  # odd position in subarray → multiply by 1
            total += a[idx]
    print(total)
