from tkinter import*

class Janela:
    def __init__(self, tk):
        self.c1 = Canvas(tk, height=600, width=1200)
        self.c1.pack()

        self.c1.create_rectangle((60,0),(1200,900), fill="white")

        #Finlãndia
        self.c1.create_rectangle((600,100),(1200,200), fill="blue")
        self.c1.create_rectangle((750,0),(850,300), fill="blue")
        self.c1.create_polygon((600,100),(750,100),(750,0),(850,0),(850,100),(1200,100),(1200,200),(850,200),(850,300),
        (750,300),(750,200),(600,200), fill="blue")

        #Chile
        self.c1.create_rectangle((0,300),(200,450), fill="blue")
        self.c1.create_rectangle((0,450),(600,600), fill="red")
        self.c1.create_polygon((55,360),(90,360),(100,330),(110,360),(140,360),(115,380),(125,410),(100,390),(75,410),(85,380), fill="white")
        
        # Trindade e Tobago
        self.c1.create_polygon((0,0),(450,300),(0,300),fill="red")
        self.c1.create_polygon((150,0),(600,0),(600,300),fill="red")
        self.c1.create_polygon((20,0),(130,0),(580,300),(470,300),fill="black")

        # Japão - Bônus
        self.c1.create_oval(810,390,960,510, fill='red')


root = Tk()
Janela(root)
root.geometry("1200x600")
root.mainloop()