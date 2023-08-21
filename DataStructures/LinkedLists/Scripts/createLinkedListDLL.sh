
#!/usr/bin/bash
# A bash script to compile and compile a dynamic shared library with gcc

# Define the source file and the DLL file names
echo "Compilation started ..."
SRC="./DataStructures/LinkedLists/src/linkedlist.c"
DLL="./DataStructures/LinkedLists/Debug/bin/lib_LinkedLists.dll"

# Compile the source file with gcc and check for errors
gcc -g -fPIC $SRC -shared -o $DLL
if [ $? -ne 0 ]; then
  echo "Compilation failed"
  exit 1
fi
echo "Compilation complete"
