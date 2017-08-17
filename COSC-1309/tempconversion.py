#Nathaniel Clayton Section 2
#Temperature Conversion 11.28.2016


done = False
while not done:
    
    mode = input("What temperature scale are you using? F or C? ")
    temp = float(input("Enter the current temperature using your scale: "))

    inFahr = (mode == 'F') or (mode == 'f')

    if inFahr:
        c = ((5/9)*(temp-32))
        print (temp, "Converted to Celsius =", format(c, ",.2f"))

    else:
        f = ((9/5)*temp) + 32
        print (temp, "Converted to Fahrenheit =", format(f, ",.2f"))

    if temp <= 32 and inFahr or temp <= 0 and inFahr == False:
        print ("It's below freezing outside, be careful on the roads.")

    ans = input("Convert another? Y/N ")
    done = ans != "y" and ans != "Y"
print ("End of Program")
