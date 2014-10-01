from tkinter import *
from tkinter import ttk
from vectors import *

def add_vector(name, position, elem_var):
    """
    Adds the fields for a vector in row = postion and binds the variable to elem_var (list
    of our vector components).
    """
    try:
        ttk.Entry(mainframe, width=7, textvariable=elem_var[0]).grid(column=2, row=position, sticky=(W, E))
        ttk.Label(mainframe, text="i").grid(column=3, row=position, sticky=W)

        ttk.Entry(mainframe, width=7, textvariable=elem_var[1]).grid(column=4, row=position, sticky=(W, E))
        ttk.Label(mainframe, text="j").grid(column=5, row=position, sticky=W)

        ttk.Entry(mainframe, width=7, textvariable=elem_var[2]).grid(column=6, row=position, sticky=(W, E))

        ttk.Label(mainframe, text="k").grid(column=7, row=position, sticky=W)
    except ValueError:
        pass

def execute_all(*args):
    """
    Does all our calculations and stores them in the the result variables.
    """
    try:
        vec1 = vector(v1i.get(), v1j.get(), v1k.get())
        vec2 = vector(v2i.get(), v2j.get(), v2k.get())
        result_sum.set(vec1 + vec2)
        result_cross.set(cross(vec1, vec2))
        result_dot.set(dot((vec1, vec2)))
        result_uxf.set(force_along_a_line(vec1, vec2))
    except ValueError:
        pass

##def display_change(*args):
##    try:
##        if operation.get() == "General 2 Vector Calculations":
##            add_vector("Vector 1", 2, v1)
##            add_vector("Vector 2", 3, v2)
##
##        elif operation.get() == "3 Vector Calculations":
##            add_vector("u", 2, v1)
##            add_vector("r", 3, v2)
##            add_vector("f", 4, v3)
##        elif operation.get() == "1 Vector Manipulations":
##            add_vector("Vector 1", 2, v1)
##
##        for child in mainframe.winfo_children():
##            child.grid_configure(padx=5, pady=5)
##    except ValueError:
##        pass

# the title and base gui

root = Tk()
root.title("Vectors")

# Our lovely components

v1i = StringVar()
v1j = StringVar()
v1k = StringVar()
v1 = (v1i, v1j, v1k)

v2i = StringVar()
v2j = StringVar()
v2k = StringVar()
v2 = (v2i, v2j, v2k)

v3i = StringVar()
v3j = StringVar()
v3k = StringVar()
v3 = (v3i, v3j, v3k)

# the results (not all are supported yet)

result_sum = StringVar()
result_cross = StringVar()
result_dot = StringVar()
result_triple = StringVar()
result_uxf = StringVar()

# start the creation of the main frame

mainframe = ttk.Frame(root, padding="10 10 40 40")
mainframe.grid(column=0, row=0, sticky=(N, W, E, S))
mainframe.columnconfigure(0, weight=1)
mainframe.rowconfigure(0, weight=1)

##options = ttk.Combobox(mainframe, width=26, textvariable=operation)
##options.bind('<<ComboboxSelected>>', display_change)
##options['values'] = ("1 Vector Manipulations", 'General 2 Vector Calculations', '3 Vector Calculations')
##options.grid(column=1, row=1, sticky=W)

# Add the vector fields

v1_label = ttk.Label(mainframe, text="Vector 1").grid(column=1, row=2, sticky=W)
v2_label = ttk.Label(mainframe, text="Vector 2").grid(column=1, row=3, sticky=W)
#v3_label = ttk.Label(mainframe, text="Vector 3").grid(column=1, row=4, sticky=W)

add_vector("Vector 1", 2, v1)
add_vector("Vector 2", 3, v2)
#add_vector("Vector 3", 4, v3)



# The labels for the results

ttk.Label(mainframe, text="Vector Sum").grid(column=1, row=5, sticky=W)
ttk.Label(mainframe, textvariable=result_sum).grid(column=2, row=5, sticky=(W, E))

ttk.Label(mainframe, text="Vector Product").grid(column=1, row=6, sticky=W)
ttk.Label(mainframe, textvariable=result_cross).grid(column=2, row=6, sticky=(W, E))

ttk.Label(mainframe, text="Scalar Product").grid(column=1, row=7, sticky=W)
ttk.Label(mainframe, textvariable=result_dot).grid(column=2, row=7, sticky=(W, E))

ttk.Label(mainframe, text="V2 along V1").grid(column=1, row=8, sticky=W)
ttk.Label(mainframe, textvariable=result_uxf).grid(column=2, row=8, sticky=(W, E))

# The button, a loop for adding space around the widgets

ttk.Button(mainframe, text="Calculate", command=execute_all).grid(column=1, row=10, sticky=W)

for child in mainframe.winfo_children():
    child.grid_configure(padx=5, pady=5)

# The Enter/Return key now triggers our execute_all function

root.bind('<Return>', execute_all)

# Starts the gui

root.mainloop()