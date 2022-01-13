
## if want to speed up -> binary search!
def is_unique(s: str) -> bool:
    for i in range(0, len(s)):
        for j in range(i + 1, len(s)):
            if not str([j]).isalpha():
                continue
            if s[i] == s[j]:
                return False

    return True


print(is_unique("Hide"))
print(is_unique(Hello world))
