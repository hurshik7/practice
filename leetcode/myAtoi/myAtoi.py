
def myAtoi(s: str) -> int:
    s = s.lstrip()
    is_minus = False
    is_sign_check = False
    is_number_start = False
    number = 0
    numbers = []
    for i in s:
        if i.isnumeric():
            is_number_start = True
            numbers.append(ord(i) - ord('0'))
        else:
            if is_number_start is True:
                break
            if i == "-":
                if is_sign_check:
                    break
                is_minus = True
                is_sign_check = True
            elif i == "+":
                if is_sign_check:
                    break
                is_sign_check = True
                continue
            else:
                break

    index = len(numbers) - 1
    place = 1
    while index >= 0:
        number += place * (numbers[index])
        index -= 1
        place *= 10

    if is_minus:
        number *= -1

    if number <= -(2 ** 31):
        return -(2 ** 31)
    elif number >= 2 ** 31:
        return 2 ** 31 - 1

    return number


print(myAtoi("     5"))
print(myAtoi("-234"))
print(myAtoi("42"))
print(myAtoi("    -42"))
print(myAtoi("4193 with words"))

