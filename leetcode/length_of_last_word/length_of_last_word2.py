
def lengthOfLastWord(s: str) -> int:
    index = len(s) - 1
    while s[index] == " ":
        index -= 1

    ret = 0
    while index >= 0 and s[index] != " ":
        ret += 1
        index -= 1

    return ret



print(lengthOfLastWord("Hello World"))
print(lengthOfLastWord("Hello World  "))
print(lengthOfLastWord("   fly me to the moon  "))
print(lengthOfLastWord("luffy is still joyboy"))
