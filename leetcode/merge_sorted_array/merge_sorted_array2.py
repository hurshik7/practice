
def merge(nums1: list[int], m: int, nums2: list[int], n: int) -> None:
    p1 = m - 1
    p2 = n - 1
    p3 = len(nums1) - 1

    while p1 >= 0 and p2 >= 0:
        if nums2[p2] > nums1[p1]:
            nums1[p3] = nums2[p2]
            p2 -= 1
        else:
            nums1[p3] = nums1[p1]
            p1 -= 1
        p3 -= 1

    for i in range(0, p2 + 1):
        nums1[i] = nums2[i]


nums1 = [1, 2, 3, 0, 0, 0]
m = 3
nums2 = [2, 5, 6]
n = 3

merge(nums1, m, nums2, n)
print(nums1)
