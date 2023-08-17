
#!/usr/bin/bash
# A bash script to compile and run a C program with gcc

# Define the source file and the executable file names
SRC="../LinkedLists/testLinkedList.c"
OBJ="../LinkedLists/Debug/obj/testLinkedList.o"
EXE="../LinkedLists/Debug/bin/testLinkedList.exe"
DLLPATH="../LinkedLists/Debug/bin"
DLLNAME="lib_LinkedLists"

# Compile program with Included DLL
export PATH="C:\Users\HP\OneDrive\Documents\PersonalDevelopment\Advanced-C-Programming-Course\DataStructures\LinkedLists\Debug\bin":$PATH
gcc -I $DLLPATH -c $SRC -o $OBJ
gcc -o $EXE $OBJ -L $DLLPATH  -l $DLLNAME

if [ $? -ne 0 ]; then
  echo "Compilation failed"
  exit 1
fi
echo "Compilation complete!"
