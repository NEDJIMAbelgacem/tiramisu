expr = input()
open = 0
for i in expr:
    if i == '(': open += 1
    elif i == ')': open -= 1
    if open < 0:
        break
if open == 0:
    print("Balanced")
else:
    print("Not balanced")