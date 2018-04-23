#!/usr/bin/env python

import os, sys

try: 
    os.makedirs("build")
except FileExistsError as e:
    pass

os.chdir("build")

detect_os = sys.platform;
if detect_os == "linux":
    flags = "-std=c++17 -g -O3 -Wall -Wextra"

    os.chdir("../src")
    src_files = [f for f in os.listdir() if os.path.isfile(f)]
    os.chdir("../build")

    for f in src_files:
        if os.path.isfile("../src/" + f):
            # create object files in build for all source files
            os.system("g++ -c " + flags + " ../src/" + f);
        else:
            print("File " + f + " does not exist.")
 
    obj_files = [f for f in os.listdir() if os.path.isfile(f)]
    compile_cmd = "g++ " + flags + " -o ../thekinggame.exe "
    for o in obj_files:
        compile_cmd += o + " "
    os.system(compile_cmd);
else:
    print("Unsupported OS.")

os.chdir("..")
