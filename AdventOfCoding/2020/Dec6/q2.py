counts_file = open("Counts.txt", "r")
counts = counts_file.read().split("\n\n")

total = 0

for group in counts:
    split_count = group.split()

    valid_chars = [chr(i) for i in range(ord('a'), ord('z') + 1)]
    counter = 0
    for passenger in split_count:
        chars = 0
        while chars < len(valid_chars):
            if (valid_chars[chars] not in passenger):
                del valid_chars[chars]
            else:
                chars += 1
    
    counter = len(valid_chars)
    total += counter

print(total)
