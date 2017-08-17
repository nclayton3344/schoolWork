import sys                               ###Put these in every program that draws
sys.path.insert(0,'c:\Python34\Lib')     ###

import turtle                            ###

wn = turtle.Screen()                     ###
wn.bgcolor("black")
wn.title("Turtle Fun")

tex = turtle.Turtle()
tex.color("green")
tex.shape("turtle")
tex.pensize(4)

        

for i in range(50):
    tex.forward(20)
    tex.left(90)
    tex.penup()
    tex.forward(20)
    tex.pendown()
    

wn.mainloop()                            ###
