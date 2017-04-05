#!/usr/bin/python
import os, sys
import multiprocessing

command = sys.argv

source_dir = '/root/workspace/CloudifyAVG/proj_PA2/src'


def searchFiles(filename):
    matches = []
    for dirpath, dirnames, files in os.walk(source_dir):
        for f in files:
            if f == filename:
                dirname = dirpath[-4:]
                file_path = dirpath + '/' + filename
	        matches.append(file_path)
    return matches


def make():
    matches = searchFiles("CMakeLists.txt")
    for match in matches:
        path = match[::-1].split('/',1)[1][::-1]
        os.chdir(path)
        cmd  = 'cmake .'
        os.system(cmd)
        cmd = 'make ' + ' -f ' + path + '/Makefile'
        print(cmd)
        os.system(cmd)


def clean():
    matches = searchFiles("make_clean.py")
    for match in matches:
        path = match[::-1].split('/',1)[1][::-1]
	os.chdir(path)
        cmd = "./make_clean.py"
	os.system(cmd)

def printHelp():
	help_message = """
Syntax:
	python compileAll.py [OPTIONS]

OPTIONS:
	--clean or -c , Clean unnecessary files and binaries

	-h, Print help"""
	print(help_message)


if command and len(command) > 1:
    if command[1] == '--clean' or command[1] == '-c':
        clean()
    elif command[1] == '-h':
        printHelp()
    else:
        print("ERROR: Use -h to help.")
else:
    make()

