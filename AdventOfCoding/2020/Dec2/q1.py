passwords_file = open("Passwords.txt", "r")
all_lines = passwords_file.read().split("\n")

valid_counter = 0

for line in all_lines:
    bound, letter, password = line.split(" ")
    letter = letter[0]
    min_bound, max_bound = map(int, bound.split("-"))
    character_counter = 0

    for character in password:
        if (character == letter):
            character_counter += 1

    if (character_counter >= min_bound and character_counter <= max_bound):
        valid_counter += 1

print(valid_counter)
