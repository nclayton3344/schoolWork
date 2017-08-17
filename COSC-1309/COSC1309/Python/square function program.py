#C Young 12/01/14
#This program demonstrates using a function

import sys
sys.path.insert(0,'c:\Python34\Lib')

import turtle

#function definition
def draw_square(t, sz, c):  #variables in () are called PARAMETERS
 #Make turtle t draw a square of sz of color c.
 t.color(c)
 for i in range(4):
     t.forward(sz)
     t.left(90)

#here is where the main program starts
wn = turtle.Screen()        # Set up the window and its attributes
wn.bgcolor("green")
wn.title("Example for Project 2")

alex = turtle.Turtle()     # Create first turtle, alex
alex.pensize(3)
alex.speed(5)              #speed settings from 1(slowest) to 10(fastest)

sally = turtle.Turtle()    # create new turtle, sally


c = "red"
for i in range(36):
  draw_square(alex, 40, c)  # Call the function to draw the square
  alex.forward(12)
  alex.left(10)
  if c == "red":
      c = "yellow"
  else:
      c = "red"
      
sally.penup()
sally.forward(100)
sally.pendown()
for i in range(36):
  sally.forward(12)
  sally.left(10)
  draw_square(sally, 10, "black")   # Call the function to draw the square  

wn.mainloop()
