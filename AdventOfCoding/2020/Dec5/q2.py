boarding_file = open("boardingPasses.txt", "r")
boarding_passes = boarding_file.read().split()

existing = []

for boarding_pass in boarding_passes:
    column = list(boarding_pass[:7])
    row = list(boarding_pass[7:])

    for c in range(len(column)):
        if column[c] == 'F':
            column[c] = '0'
        else:
            column[c] = '1'

    for c in range(len(row)):
        if row[c] == 'L':
            row[c] = '0'
        else:
            row[c] = '1'

    column = "".join(column)
    row = "".join(row)
    
    column = int(column, 2)
    row = int(row, 2)

    existing.append(8 * column + row)

existing.sort()

lowest = existing[0]

for i in range(len(existing)):
    if existing[i] != lowest:
        print(lowest)
        break
    lowest += 1
