from collections import Counter


def solution(S, L):
    # write your code in Python 3.6
    max_num_of_char = 0
    for string in L:
        num_of_char = 101
        counter = dict(Counter(S))
        counter_needed = dict(Counter(string))
        for key, value in counter_needed.items():
            curr_num_of_str = 101
            if counter.get(key) is not None:
                curr_num_of_str = counter[key] // value
            else:
                curr_num_of_str = 0

            if curr_num_of_str <= num_of_char:
                num_of_char = curr_num_of_str

        if max_num_of_char <= num_of_char:
            max_num_of_char = num_of_char

    return max_num_of_char


print(solution("BBBBBBBBBB", ["BBBB", "A", "BB", "B", "BBB", "C"]))
AA = "A"*100
print(solution(AA, [AA, "A", "AA", "AAA"]))
print(solution("CATSCA", ["CAT", "CA"]))
print(solution("CATSCA", ["CBA", "BDE"]))
print(solution("AAAAABBCCCCC", ["ABC", "AB", "CCCCC", "DDDDD", "AC"]))
print(solution("AAAAABBCCCCC", ["DDDDD", "F", "AAAAABBCCCCC"]))
