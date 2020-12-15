documents_file = open("documents.txt", "r")

validCount = 0
attributes_list = ['byr', 'iyr', 'eyr', 'hgt', 'hcl', 'ecl', 'pid']

def validate(atr, val):
    if atr == 'byr':
        val = int(val)
        if (val >= 1920 and val <= 2002):
            return True
        else:
            return False
    elif atr == 'iyr':
        val = int(val)
        if (val >= 2010 and val <= 2020):
            return True
        else:
            return False
    elif atr == 'eyr':
        val = int(val)
        if (val >= 2020 and val <= 2030):
            return True
        else:
            return False
    elif atr == 'hgt':
        if (len(val)) <= 2:
            return False
        metric = val[-2:]
        val = int(val[:-2])
        if (metric == 'in'):
            if (val >= 59 and val <= 76):
                return True
            else:
                return False
        elif (metric == 'cm'):
            if (val >= 150 and val <= 193):
                return True
            else:
                return False
    elif atr == 'hcl':
        if (val[0] != '#'):
            return False
        for char in val[1:]:
            if not char in ['0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a', 'b', 'c', 'd', 'e', 'f']:
                return False
        return True
    elif atr == 'ecl':
        if not val in ['amb', 'blu', 'brn', 'gry', 'grn', 'hzl', 'oth']:
            return False
        else:
            return True
    elif atr == 'pid':
        if len(val) != 9:
            return False
        for num in val:
            if not num in ['0', '1', '2', '3', '4', '5', '6', '7', '8', '9']:
                return False
        return True

documents = documents_file.read().split("\n\n")
for i in range(len(documents)):
    person = documents[i].split()
    for j in range(len(person)):
        person[j] = person[j].split(':')

    validPerson = True
    for attr in attributes_list:
        isValid = False
        for d_attr in person:
            if d_attr[0] == attr:
                if validate(d_attr[0], d_attr[1]):
                    isValid = True
        validPerson = validPerson and isValid

    if validPerson:
        validCount += 1

print(validCount)
