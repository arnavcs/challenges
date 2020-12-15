hill_text = open("hill.txt", "r")

hill = hill_text.read().split("\n")

count = 0

for row in range(len(hill) - 1):
    if (hill[row][(3 * row) % len(hill[0])] == '#'):
        count += 1

print(count)
