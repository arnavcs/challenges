expenses_file = open("Expenses.txt", "r")

expenses_list = list(map(int, expenses_file.read().split("\n")))

for expense in expenses_list:
    if (2020-expense in expenses_list and 2020-expense != expense):
        print((2020-expense)*expense)
        break
