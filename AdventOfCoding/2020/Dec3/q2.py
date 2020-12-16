hill_text = open("hill.txt", "r")

hill = hill_text.read().split("\n")

def getTrees (right, down):
    count = 0
    for row in range(0, len(hill), down):
        if (len(hill[row]) > 0 and hill[row][(right * row // down) % len(hill[0])] == '#'):
            count += 1
    return count

print(getTrees(1, 1) * getTrees(3, 1) * getTrees(5, 1) * getTrees(7, 1) * getTrees(1, 2))
