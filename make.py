#!/usr/bin/env python
#
# make.py
#
# Maxwell Anderson 2018

import os

try:
    os.makedirs("build")
except FileExistsError as e:
    pass

os.chdir("build")

os.system("cmake ..")

os.system("make")

os.chdir("..")
