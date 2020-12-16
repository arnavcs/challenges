documents_file = open("documents.txt", "r")

attributes_list = ['ecl', 'iyr', 'eyr', 'hgt', 'hcl', 'ecl', 'pid', 'cid']
num_valid = 0

documents = documents_file.read().split("\n\n")
for i in range(len(documents)):
    documents[i] = documents[i].split()
    for j in range(len(documents[i])):
        documents[i][j] = documents[i][j][:3]

    if (len(documents[i]) == len(attributes_list)):
        num_valid += 1
    elif (len(documents[i]) + 1 == len(attributes_list) and not 'cid' in documents[i]):
        num_valid += 1

print(num_valid)
