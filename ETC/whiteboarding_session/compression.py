
def ComppressString(s: str) -> str:
    if s == "":
        return ""

    count = 0
    temp_char = s[0]
    compressed = ""
    for c in s:
        if c == temp_char:
            count += 1
        else:
            compressed += (temp_char + str(count))
            count = 1
            temp_char = c

    if count != 0:
        compressed += (temp_char) + str(count)

    return compressed


print(ComppressString("aabcccccaaa"))
print(ComppressString("abc"))
