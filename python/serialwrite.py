import serial
import time
from tkinter import *   


ser = serial.Serial('/dev/ttyACM0', timeout=1)   

def mode1():
	ser.write(b'1')

def mode2():
	ser.write(b'2')

top = Tk()  
top.geometry("500x300")  


b1 = Button(top, command = mode1, text = "MODE 1",activeforeground = "red",activebackground = "pink",pady=10,height = 5, width = 15)  
b2 = Button(top, command = mode2, text = "MODE 2",activeforeground = "red",activebackground = "pink",pady=10,height = 5, width = 15)  

b2.place(relx=0.7, rely=0.465, anchor=CENTER)
b1.place(relx=0.3, rely=0.465, anchor=CENTER)

top.mainloop()  

