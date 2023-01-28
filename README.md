
# SEDK (Simple Extensible Firmware Interface Development Kit)

SEDK is a library that allows you to quickly and easily write your own x64 EFI applications on Windows systems.






## Getting Stared

To get started you need:
- Windows 10/11
- Clang([Download](https://clang.llvm.org/))
- Python 3.9+([Download](https://www.python.org/downloads/))
- Visual Studio Code(Just a recommendation)
- Motivation

After you have done all the things above we can now start to write a simple Hello World application. 👍

## First Application 

First of all you should download the latest release of SEDK ([Download](https://github.com/rxbin1201/SEDK/releases/)).
After downloading the latest release, you need to unzip the file. Now open a new console in the directory and start the build.py using:
```bash
  python build.py
```
When you are asked how to name certain directories it is important to write only the name of the folder without '/' otherwise it can lead to problems in the build script
The first time you will be asked some important things, after that some new files should have created. Now open any text editor of your choice (I prefer Visual Studio Code). If not already created you can now create a new C-file in the Sources folder, for example main.c.
Here you can write all your source code in it.



Our example code to print out a 'Hello, World!' message:

```c
#include <sedk.h>

EFI_STATUS efi_entry(EFI_HANDLE ImageHandle, EFI_SYSTEM_TABLE *SystemTable) {

    Log(L"Hello, World!\n");

    return EFI_STATUS;
}
```

## Compiling 

To compile your EFI application you only have to enter the following: 

```bash
  python build.py Filename
```

Change 'Filename' to what you want the finished EFI file to be called, for example hello.efi.
That's all, you can now try your EFI file under a UEFI system.







## Authors

- [@rxbin1201](https://github.com/rxbin1201)

