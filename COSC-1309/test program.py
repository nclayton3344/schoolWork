#Nathaniel Clayton
#Investment Calculator Project 11.28.2016
P = input("How much is your initial investment? ")
P = float(str(P).replace(",","").replace("$",""))
s = input("What percentage is your annual nominal interest rate? ")
s = float(str(s).replace("%", ""))
n = float(input("How many times per year is the interest compounded? "))
r = (s/100)
t = int(input("How many years will it be gaining interest? "))
nt = float(n*t)
amount = (P*(1 + r/n)**nt)
free = (amount - P)

if t > 10:
    print ("How much money you will have after investment: $", format(amount, ',.2f'))

    print ("Long term investments are important for retirement planning.")
else:
    print ("How much money you will have after investment: $", format(amount, ',.2f'))
    
