

def rotate_matrix(img: list) -> list:
    new_img = []
    rowCountFromInput = len(img)
    colCountFromInput = len(img[0])
    for i in range(0, colCountFromInput):
        new_col = []
        for j in range(0, rowCountFromInput):
            new_col.append(j)
        new_img.append(new_col)

    for i in range(0, colCountFromInput):
        rowNum = rowCountFromInput - 1
        for j in range(0, rowCountFromInput):
            new_img[i][j] = img[rowNum][i]
            rowNum -= 1

    return new_img


print(rotate_matrix([[1, 2, 3],[1, 2, 3],[1, 2, 3]]))
print(rotate_matrix([[1], [2], [3]]))
print(rotate_matrix([[1, 2, 3]]))

