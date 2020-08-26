def solution(x, y):
    # Your code here
    first_in_row = int(0.5*(y**2) - 0.5*y + 1)
    
    triangular_sum = (x-1)*(2*y+x) // 2
    
    return str(first_in_row + triangular_sum)

print(solution(1,5))