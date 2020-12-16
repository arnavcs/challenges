counts_file = open("Counts.txt", "r")
counts = counts_file.read().split("\n\n")

total = 0

for count in counts:
    bit_mask = 0
    counter = 0
    for char in count:
        if (char != "\n" and not bit_mask & (1 << (ord(char) - ord('a')))):
            bit_mask |= 1 << (ord(char) - ord('a'))
            counter += 1
    total += counter

print(total)
