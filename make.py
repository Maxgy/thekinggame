#!/usr/bin/env python
#
# make.py
#
# Maxwell Anderson 2018

import os
import platform

detect_os = platform.system()
if detect_os == "Linux":
    if os.path.isfile("/usr/bin/clang") and os.path.isfile("/usr/bin/clang++"):
        os.environ["CC"] = "/usr/bin/clang"
        os.environ["CXX"] = "/usr/bin/clang++"
elif detect_os == "Windows":
    pass

try:
    os.makedirs("build")
except FileExistsError as e:
    pass

os.chdir("build")

os.system("cmake ..")

os.system("make")

os.rename("compile_commands.json", "../compile_commands.json")

os.chdir("..")
