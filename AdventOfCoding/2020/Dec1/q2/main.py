expenses_file = open("Expenses.txt", "r")
expenses_list = list(map(int, expenses_file.read().split("\n")))

expenses_count = [0 for i in range(2020 + 1)]

for expense in expenses_list:
    expenses_count[expense] += 1

print(expenses_count)

running_sum = 0

def eval (rep = 1):
    global running_sum
    retVal = False
    
    for i in range(2020 + 1):
        if (expenses_count[i] > 0):
            running_sum += i
            expenses_count[i] -= 1

            if (rep != 3):
                if (eval(rep + 1)):
                    print(i, rep)
                    retVal = True
            elif (running_sum == 2020):
                print(i, rep)
                retVal = True
                
            running_sum -= i
            expenses_count[i] += 1
    
    return retVal

eval()
