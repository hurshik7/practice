def solution(S):
    if len(S) == 1:
        return 0

    max_length = 0
    curr_length = 0
    block_count = 0
    curr_char = 'x'
    for c in S:
        if c == curr_char:
            curr_length += 1
        else:
            if max_length <= curr_length:
                max_length = curr_length
            block_count += 1
            curr_char = c
            curr_length = 1

    if max_length <= curr_length:
        max_length = curr_length

    return block_count * max_length - len(S)

print(solution("abbbbbbb"))
print(solution("a"))
print(solution("abababababababababababababababab"))
