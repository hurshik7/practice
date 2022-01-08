
def plusOne(digits: list[int]) -> list[int]:
    index = len(digits) - 1
    digits[index] += 1

    while index >= 0:
        if digits[index] == 10:
            digits[index] = 0
            if index - 1 >= 0:
                digits[index - 1] += 1
            else:
                digits.insert(0, 1)
        index -= 1

    return digits


plusOne([1, 2, 3])
plusOne([4, 3, 2, 1])
plusOne([9])

