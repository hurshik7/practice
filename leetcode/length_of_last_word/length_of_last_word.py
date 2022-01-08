
def lengthOfLastWord(s: str) -> int:
    s = s.rstrip()
    li = s.split(" ")
    ret = len(li[-1])

    return ret


print(lengthOfLastWord("Hello world   "))
print(lengthOfLastWord("    fly me    to    the moon "))
print(lengthOfLastWord("luffy is still joyboy"))

