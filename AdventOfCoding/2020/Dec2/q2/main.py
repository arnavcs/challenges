passwords_file = open("Passwords.txt", "r")
all_lines = passwords_file.read().split("\n")

valid_counter = 0

for line in all_lines:
    print(line)
    
    indicies, letter, password = line.split(" ")
    letter = letter[0]
    indicies = list(map(int, indicies.split("-")))

    c1 = (password[indicies[0] - 1] == letter)
    c2 = (password[indicies[1] - 1] == letter)

    if (not (c1 == c2)):
        print(True)
        valid_counter += 1

print(valid_counter)
