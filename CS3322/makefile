# Makefile to support building and executing
# the lab1.cbl program
#

SHELL = /bin/bash

lab1: lab1.cbl
	cobc -x lab1.cbl

run: lab1
	./lab1

clean:
	rm -f lab1
