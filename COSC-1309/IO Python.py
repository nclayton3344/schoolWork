#Nathaniel Clayton 11.16.2016
#Testing Input and Output

print("Practicing Python I/O")

x = float(input ("Enter a base value: "))

y = float(input ("Enter an Exponent: "))

z = x**y
formatstr = ",.2f"
answer = format(z,formatstr)
base = format(x,formatstr)
exponent = format(y,formatstr)

print (base, "raised to the power of",exponent, "=", answer)
print ("values unformatted looks like:",x,y,z)

w = x*y
print(w)
