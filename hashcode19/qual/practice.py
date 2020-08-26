with open("d_quite_big.in", "r") as f:
    cases = f.read()
splitcases = cases.split('\n')
cap, styles = map(int, splitcases[0].split())
slices = list(map(int, splitcases[1].split()))

table = [[None for weight in range(cap + 1)] for item in range(styles + 1)]

def maxpizza():
    # Tuple will be (maxvalue, number of pizzas)
    for pizza in range(styles + 1):
        for tslice in range(cap + 1):
            if pizza == 0 or tslice == 0:
                table[pizza][tslice] = (0, [])
                continue
            if slices[pizza - 1] <= tslice:
                notorder = table[pizza - 1][tslice][0]
                order = table[pizza - 1][tslice - slices[pizza - 1]][0] + slices[pizza - 1]
                decision = max(notorder, order)
                if order == decision:
                    pizzas = table[pizza - 1][tslice - slices[pizza - 1]][1][:]
                    pizzas.append(str(pizza - 1))
                    table[pizza][tslice] = (decision, pizzas)
                    continue
            table[pizza][tslice] = table[pizza - 1][tslice]

maxpizza()
pizzas = table[styles][cap][1]
size = len(pizzas)
pizzas = ' '.join(pizzas)
with open("d_order.out", "w") as f:
    f.write(f"{size}\n{pizzas}")