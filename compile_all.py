#!/usr/bin/env python

import os, sys

try: 
    os.makedirs("build")
except FileExistsError as e:
    pass

os.chdir("build")

detect_os = sys.platform;
if detect_os == "linux":
    os.chdir("../src")
    src_files = [f for f in os.listdir() if os.path.isfile(f)]
    os.chdir("../build")
 
    for f in src_files:
        if os.path.isfile("../src/" + f):
            # create object files in build for all source files
            os.system("g++ -c -std=c++17 -g -O3 -Wall ../src/" + f);
        else:
            print("File " + f + " does not exist.")

    obj_files = [f for f in os.listdir() if os.path.isfile(f)]
    compile_cmd = "g++ -std=c++17 -g -O3 -Wall -o ../exe "
    for o in obj_files:
        compile_cmd += o + " "
    os.system(compile_cmd);
else:
    print("Unsupported OS.")

os.chdir("..")
