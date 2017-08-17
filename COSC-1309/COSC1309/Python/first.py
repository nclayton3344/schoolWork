#This is my first Python program
#C Young 4/13/2017

print("Hello, Python world!")

print('C Young is programming!')

formatstr = ",.2"

x = float(input("Enter a value for the base:"))

y = float(input("Enter a value for the exponent:"))

z = x**y
answer = format(z,formatstr)

print(x, "raised to the", y, "power =", answer)



