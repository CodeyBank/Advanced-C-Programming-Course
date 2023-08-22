
#!/usr/bin/bash
# A bash script to compile and run a C program with gcc

# Define the source file and the executable file names
SRC="./DataStructures/Stacks/src/testStacks.c"
OBJ="./DataStructures/Stacks/Debug/obj/testStacks.o"
EXE="./DataStructures/Stacks/Debug/bin/testStacks.exe"
DLLPATH="./DataStructures/Stacks/Debug/bin/"
DLLNAME="lib_Stacks"

# Compile program with Included DLL
export PATH="C:\Users\HP\OneDrive\Documents\PersonalDevelopment\Advanced-C-Programming-Course\DataStructures\Stacks\Debug\bin":$PATH
gcc -I $DLLPATH -c $SRC -o $OBJ
gcc -o $EXE $OBJ -L $DLLPATH  -l $DLLNAME -municode

if [ $? -ne 0 ]; then
  echo "Compilation failed"
  exit 1
fi
echo "Compilation complete!"

