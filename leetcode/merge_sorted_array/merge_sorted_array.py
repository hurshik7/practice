
def merge(nums1: list[int], m: int, nums2: list[int], n: int) -> None:
    index2 = 0
    for i in range(0, len(nums1)):
        if nums1[i] == 0:
            if index2 <= n:
                nums1[i] = nums2[index2]
                index2 += 1

    nums1.sort()


nums1 = [1, 2, 3, 0, 0, 0]
nums2 = [2, 5, 6]
merge(nums1, 3, nums2, 3)
print(nums1)

