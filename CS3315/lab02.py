#!/usr/bin/env python3

from datetime import datetime

'''
    FILE:  lab02.py

    PURPOSE:  To demonstrate parsing of delimiter separated
              lines of text as a prelude to some sysadmin
              reporting task

    NOTE:  This script must be run directly on thor to
           get intended results

    AUTHOR: Nathaniel Clayton, Professor Haiduk

    DATE: 03/27/2019
'''

# pre-declare list variables
lines = []
tokens = []
members = []

currentDT = datetime.now()
date_time = currentDT.strftime("%m/%d/%Y, %H:%M:%S")
# provide formatted date/time heading, etc.

# print header
print ("")
print (date_time.center(80, ' '))
print ("by Nathaniel Clayton\n".center(80, ' '))

filePath = "/etc/group"

fileVar = open(filePath, "r")
lines = fileVar.readlines()
fileVar.close()

for line in lines:
    # print("%s" % line) # for debugging
    line = line.rstrip()
    tokens = line.split(":")
    first = tokens[0]
    # Student complete here
    
    # if addtn'l members is not empty, print  
    if tokens[3] != "":
        print(" {}:".format(first))
        tokens = tokens[3].split(",")
        index=1
        # loop through members and pretty print them
        for token in tokens:
            print("{:>15s}".format(token), end='')
            # if 5th in the row and more than 5 members, print new line
            if index % 5 == 0 and len(tokens) > 5:
                print("")
            # end if
            index += 1
        # end for
        print("\n\n")
    # end if
# end for
