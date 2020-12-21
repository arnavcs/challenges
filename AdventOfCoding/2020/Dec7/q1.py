rules_file = open("rules.txt", "r")
rules = rules_file.read().split('\n')

all_bags = {}

for bag_rule in rules:
    bag_types, contained = bag_rule.split(" contain ")
    contained = contained[:-1].split(", ")
    i = 0
    while i < len(contained):
        contained[i] = contained[i].split(" ", 1)
        if contained[i][0] == '1':
            contained[i][1] += 's'
            i += 1
        elif contained[i][0] == 'no':
            del contained[i]
        else:
            i += 1
    all_bags[bag_types] = contained

valid_bag_types = ["shiny gold bags"]

stillappending = True
while stillappending:
    stillappending = False
    for bag_type in all_bags:
        for contained_bag in all_bags[bag_type]:
            if (contained_bag[1] in valid_bag_types and bag_type not in valid_bag_types):
                valid_bag_types.append(bag_type)
                stillappending = True
                break

print(len(valid_bag_types) - 1)
