rules_file = open("rules.txt", "r")
rules = rules_file.read().split('\n')

all_bags = {}

for bag_rule in rules:
    bag_types, contained = bag_rule.split(" contain ")
    contained = contained[:-1].split(", ")
    i = 0
    while i < len(contained):
        contained[i] = contained[i].split(" ", 1)
        if contained[i][0] == 'no':
            del contained[i]
        elif contained[i][0] == '1':
            contained[i][0] = int(contained[i][0])
            contained[i][1] += 's'
            i += 1
        else:
            contained[i][0] = int(contained[i][0])
            i += 1
    all_bags[bag_types] = contained

def numBags (bag_name):
    ret = 1
    
    for child_bag in all_bags[bag_name]:
        ret += child_bag[0] * numBags(child_bag[1])
        
    return ret

print(numBags("shiny gold bags") - 1)