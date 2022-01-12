

def binarySearch(arr: list[int], target: int, start: int, end: int) -> int:
    while start <= end:
        mid = (start + end) // 2
        if arr[mid] == target:
            return mid
        elif arr[mid] < target:
            start = mid + 1
        else:
            end = mid - 1

    return -1


def twoSum(numbers: list[int], target: int) -> list[int]:
    for i in range(len(numbers)):
        new_target = target - numbers[i]
        new_target_index = binarySearch(numbers, new_target, i + 1, len(numbers) - 1)
        if new_target_index != -1:
            return [i + 1, new_target_index + 1]

    return [0, 0]


print(twoSum([2, 7, 11, 15], 9))
print(twoSum([2, 3, 4], 6))
print(twoSum([-1, 0], -1))

