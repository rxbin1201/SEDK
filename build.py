import json
import sys
import os
import subprocess
import pathlib
import platform

configFile = pathlib.Path("config.json")

srcdir = "Sources/"
hdrdir = "Headers/"
cc = "clang"
lld = "lld-link"
defaultcflags = "-target x86_64-pc-win32-coff -fno-stack-protector -fshort-wchar -mno-red-zone"
defaultldflags = "-subsystem:efi_application -nodefaultlib -dll -entry:efi_entry"

def isInstalled(name):
    try:
        subprocess.call([name, "--version"])
        return 0
    except FileNotFoundError:
        return 404

def checkConfig():
    if(configFile.is_file()):
        return 30
    else:
        return 0

def createNewConfig():

    print("""
 ######  ######## ########  ##    ## 
##    ## ##       ##     ## ##   ##  
##       ##       ##     ## ##  ##   
 ######  ######   ##     ## #####    
      ## ##       ##     ## ##  ##   
##    ## ##       ##     ## ##   ##  
 ######  ######## ########  ##    ## 
    """)

    print("[LOG] Configuration")
    
    value1 = input("[LOG] How should the source folder be named (Default: 'Sources')? ")
    value2 = input("[LOG] How should the include folder be named (Default: 'Headers')? ")

    if value1 != "":
        srcdir = value1 + "/"
    else:
        srcdir = "Sources/"
    
    if value2 != "":
        hdrdir = value2 + "/"
    else:
        hdrdir = "Headers/"

    if value1 == "SEDK":
        print("[LOG] This folder is already in use!")
    if value2 == "SEDK":
        print("[LOG] This folder is already in use!")

    os.system("if not exist " + srcdir + " mkdir " + srcdir[:-1])
    os.system("if not exist " + hdrdir + " mkdir " + hdrdir[:-1])

    configTemplate = {
        "cc" : cc,
        "lld" : lld,
        "cflags" : defaultcflags,
        "ldflags" : defaultldflags,
        "source" : srcdir,
        "header" : hdrdir
    }

    json_object = json.dumps(configTemplate, indent=5)

    with open("config.json", "w") as outfile:
        outfile.write(json_object)

    print("[LOG] Created folders.")
    print("[LOG] Configuration saved.")

#print(sys.argv)
#print(isInstalled("clang"))
#print(isInstalled("lld-link"))

if len(sys.argv) == 1:
    print("[LOG] Checking config...")
    if checkConfig() == 0:
        print("[LOG] No configuration found!\n[LOG] Lets create one...")
        createNewConfig()
    else:
        print("[LOG] Configuation already exists!\n[LOG] Use 'python build.py <Filename>' to create a EFI application.")


elif len(sys.argv) == 2:
    print("[LOG] Trying to build your EFI application...")
    print("[LOG] Filename: " + sys.argv[1])
    print("[LOG] Machine: " + platform.machine())

    try:
        with open('config.json', 'r') as config:
            objectFiles = ""
            jsonObject = json.load(config)
            print("[LOG] Compiler: " + jsonObject["cc"])
            print("[LOG] Linker: " + jsonObject["lld"])
            print("[LOG] Compiling...")
            for name in os.listdir(jsonObject["source"]):
                if name.endswith('.c'):
                    outputFile = name.rsplit('.', 1)
                    os.system("if not exist Build/ mkdir Build")
                    os.system(jsonObject["cc"] + " " + jsonObject["cflags"] + " -I SEDK/ -I " + jsonObject["header"] + " -c " + jsonObject["source"] + name + " -o Build/" + outputFile[0] + ".o")
                    objectFiles = objectFiles + " Build/" + outputFile[0] + ".o"
            print("[LOG] Linking...")
            os.system("if not exist Output/ mkdir Output")
            os.system(jsonObject["lld"] + " " + jsonObject["ldflags"] + objectFiles + " -out:Output/" + sys.argv[1])
            os.system("if exist Build/ rmdir /s /Q Build")
            print("[LOG] Done! You can find your EFI application at 'Output/'")
    except IOError:
        print("[LOG] Config not found!")
        
        

else:
    print("Error!")
