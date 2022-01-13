
def permutation(s1: str, s2:str) -> bool:
    characters_s1 = []
    for j in s1:
        characters_s1.append(j)

    for i in s2:
        if i in characters_s1:
            characters_s1.remove(i)

    if len(characters_s1) != 0:
        return False
    return True


print(permutation("abc", "cab"))

