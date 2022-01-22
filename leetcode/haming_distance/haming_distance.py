
def hammingDistance(self, x: int, y: int) -> int:
    result = xor(x, y)
    count = 0
    while result > 0:
        if result % 2 == 1:
            count += 1
            result = result // 2

    return count

