while 1:
    text = input()
    if text=='.':break
    n = len(text)

    f = [0] * (n + 1)

    text = "#" + text


    f[0] = -1 
    for i in range(1, n + 1):
        j = f[i - 1]

        while j >= 0 and text[j + 1] != text[i]:
            j = f[j]

        f[i] = j + 1

    if n % (n - f[n]):
        print(1)
    else:
        print(n//(n-f[n]))