from fractions import Fraction, gcd

#algeo is hard
def solution(m):
    prob_vec = []
    size = len(m)
    terminals = []
    for row in range(size):
        total_events = float(sum(m[row])) # question for future dhrub: will you have to deal with float imprecision?
        if total_events != 0: # avoid 0/0 dhrub
            new_row = []
            for col in range(size):
                new_row.append(m[row][col] / total_events)
            prob_vec.append(new_row)
        else:
            prob_vec.append([0] * size)
            terminals.append(row)
    i_p = [[1.0 - prob_vec[row][col] if row == col else 0 - prob_vec[row][col] for col in range(size)] for row in range(size)]
    probs = invert_matrix(i_p, size, terminals)
    denoms = []
    nums = []
    for prob in probs:
        frac = Fraction(prob).limit_denominator()
        nums.append(frac.numerator)
        denoms.append(frac.denominator)
    lcm = denoms[0]
    for i in denoms[1:]:
        lcm *= i / gcd(lcm, i)
    nums = [nums[index] * lcm // denoms[index] for index in range(len(terminals))]
    nums.append(lcm)
    return nums


def invert_matrix(m, size, terminals):
    # yikes... np.invert where did you go...?
    identity = [[1 if row == col else 0 for col in range(size)] for row in range(size)]
    a_morph = [row[:] for row in m]
    i_morph = [rows[:] for rows in identity]
    fd = 0
    fdScaler = 1.0 / a_morph[fd][fd]
    for j in range(size):
        a_morph[fd][j] *= fdScaler
        i_morph[fd][j] *= fdScaler
    
    for i in range(size):
        if i != fd:
            crScaler = a_morph[i][fd]
            for j in range(size):
                a_morph[i][j] = a_morph[i][j] - crScaler * a_morph[fd][j]
                i_morph[i][j] = i_morph[i][j] - crScaler * i_morph[fd][j]
    
    for fd in range(1,size):
        fdScaler = 1.0 / a_morph[fd][fd]

        for j in range(size):
            a_morph[fd][j] *= fdScaler
            i_morph[fd][j] *= fdScaler
        for i in range(size):
            if i != fd:
                crScaler = a_morph[i][fd]
                for j in range(size):
                    a_morph[i][j] -= crScaler * a_morph[fd][j]
                    i_morph[i][j] -= crScaler * i_morph[fd][j]
    
    values = []
    for i, prob in enumerate(i_morph[0]):
        if i in terminals:
            values.append(prob)
    return values

# solution([[0, 1, 0, 0, 0, 1], [4, 0, 0, 3, 2, 0], [0, 0, 0,0, 0, 0], [0, 0,0, 0, 0,0], [0, 0,0, 0, 0, 0], [0, 0,0, 0, 0,0]])
# solution([[0, 2, 1, 0, 0], [0, 0, 0, 3, 4], [0, 0, 0, 0, 0], [0, 0, 0, 0,0], [0, 0, 0, 0, 0]])
# solution([[0, 1, 0, 0, 0, 1], [4, 0, 0, 3, 2, 0], [0, 0, 0, 0, 0, 0], [0, 0, 0, 0, 0, 0], [0, 0, 0, 0, 0, 0], [0, 0, 0, 0, 0, 0]])