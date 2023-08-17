
#!/usr/bin/bash
# A bash script to compile and compile a dynamic shared library with gcc

# Define the source file and the DLL file names
echo "Compilation started ..."
SRC="../LinkedLists/linkedlist.c"
DLL="../LinkedLists/Debug/bin/lib_LinkedLists.dll"

# Compile the source file with gcc and check for errors
gcc -g -fPIC $SRC -shared -o $DLL
if [ $? -ne 0 ]; then
  echo "Compilation failed"
  exit 1
fi
echo "Program output: $?"
