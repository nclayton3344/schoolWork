import sys                               ###Put these in every program that draws
sys.path.insert(0,'c:\Python34\Lib')     ###

import turtle                            ###

wn = turtle.Screen()                     ###
wn.bgcolor("lightblue")
wn.title("Turtle Fun")

tex = turtle.Turtle()
tex.color("white")
tex.shape("turtle")
tex.pensize(3)

        

for i in range(4):
    tex.forward(200)
    tex.left(90)

wn.mainloop()                            ###
