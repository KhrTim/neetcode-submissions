class Solution:
    def isValidSudoku(self, board: List[List[str]]) -> bool:
        existing = set()
        for i in range(len(board)):
            for j in range(len(board[i])):
                el = board[i][j]
                if el != '.': 
                    if (el, i) not in existing and (j, el) not in existing and (el, i//3, j//3) not in existing:
                        existing.add((el, i))
                        existing.add((j, el))
                        existing.add((el, i//3, j//3))
                    else:
                        return False
        return True