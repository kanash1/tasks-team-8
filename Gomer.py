m, n, t = map(int, input().split())
if m < n:
    x, y = (m, n)
else:
    x, y = (n, m)
delta = t % x
if y % x and delta:
    delta = t + 1
    for i in range(t // y + 1):
        z = (t - i * y) % x
        if z < delta:
            delta = z
            k = i
            if not delta:
                break
        elif z == delta:
            break
    z = (t - k * y) // x
    result = k + z
else:
    result = t // x
print(result, delta if delta else '')