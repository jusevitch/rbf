import sys
sys.path.append('/home/dasc/james/easylaunch')

import easylaunch as ezl

# print("Garbage \n\n\n")

nrovers = 2
F = 1
nbad = 1
ngood = 1
rover_numbers_list = [2,3]

radius = 6
umax = 50
pi = 3.14159265358979323
ds = 0.7
Rs = 0.9
Rc = 1.2
el = 1.0

launch = ezl.launchFile()

launch.arg = {
    "nrovers": str(nrovers),
    "F": str(F),
    "nbad": str(nbad),
    "ngood": str(ngood),
    "rover_numbers_list": str(rover_numbers_list),
    "radius": str(radius),
    "umax": str(umax),
    "pi": str(pi),
    "ds": str(ds),
    "Rs": str(Rs),
    "Rc": str(Rc),
    "el": str(el)
}


launch.node = []

barrier = ezl.node(name="barrier_node", output="screen", pkg="rbf", type="barrier", launch_prefix="xterm -e gdb -ex run --args")
barrier.defparam = [
    "nrovers",
    "F",
    "nbad",
    "ngood",
    "rover_numbers_list",
    "radius",
    "umax",
    "pi",
    "ds",
    "Rs",
    "Rc",
    "el"
]

launch.node.append(barrier)

launch.write(filename="./2rovers_rbf.launch")