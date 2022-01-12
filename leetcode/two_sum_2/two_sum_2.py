
def twoSum(numbers: list[int], target: int) -> list[int]:
    ret = []
    for i in range(0, len(numbers)):
        for j in range(i + 1, len(numbers)):
            if numbers[i] + numbers[j] == target:
                ret.append(i + 1)
                ret.append(j + 1)
                return ret
            else:
                if numbers[i] == numbers[j]:
                    break

    return ret


print(twoSum([2, 7, 11, 15], 9))
print(twoSum([2, 3, 4], 6))
print(twoSum([-1, 0], -1))
