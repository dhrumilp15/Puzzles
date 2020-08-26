def solution(src, dest):
    #colour code here
    real_start = (src // 8, src % 8)
    real_dest = (dest // 8, dest % 8)
    return bfs(real_start, real_dest)

visited = []
memo_moves = {} # remember to add moves here drum

def gen_neighbours(start):
    delta_col = [2, 1, -1, -2, -2, -1, 1, 2] 
    delta_row = [1, 2, 2, 1, -1, -2, -2, -1]
    row = start[0]
    col = start[1]
    this_moves = []
    for m_i in range(8):
        if row + delta_row[m_i] >= 0 and col + delta_col[m_i] >= 0 and row + delta_row[m_i] < 8 and col + delta_col[m_i] < 8:
            this_moves.append((row+delta_row[m_i],col+delta_col[m_i]))
    memo_moves[start] = this_moves
    return this_moves
    
    
def bfs(start, target):
    global visited
    if start == target:
        return 0
    if (abs(target[0] - start[0]) == 2 and target[1] == start[1]) or (abs(target[1] - start[1]) == 2 and start[0] == target[0]):
        return 2
    queue = []
    visited.append(start)
    queue.append(start)
    moves = 0
    while queue:
        init_size = len(queue)
        # print(f"len(queue): {len(queue)}")
        for item in range(init_size, 0,-1):
            # print("Executed")
            current = queue.pop(0)
            if current in memo_moves:
                possible = memo_moves[current]
            else:
                possible = gen_neighbours(current)
            # queue_size = len(queue)
            for i in possible:
                if i == target:
                    moves += 1
                    # print("FOUND")
                    return moves
                if not i in visited:
                    queue.append(i)
                    visited.append(i)
        moves += 1
        # print("FINISHED A LEVEL")
    return -1
        
        
# print(solution(0,1))
# visited.clear()
# print(solution(19,36))
# visited.clear()
# print(solution(0,2))
# visited.clear()
# print(solution(0,32))
# visited.clear()
# print(solution(45,28))
# visited.clear()
# print(solution(34,36))
# visited.clear()
# print(solution(0,62))
# visited.clear()
# print(solution(,18))
visited.clear()