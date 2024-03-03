# mule_app
mule remake for pimoroni picosystem

Building instructions in WSL Ubuntu terminal:

1. First get a copy of the code for the picosystem, following instructions here:
https://learn.pimoroni.com/article/getting-started-with-picosystem-and-c++

2. Put this code in .../picosystem/examples/mule, making the directory mule.
3. Edit .../picosystem/CMakeLists.txt adding the line:
   add_subdirectory(mule)
4. Go to the directory .../picosystem/build, making the directory if needed
   ```
   cmake ..
   make
'''
You can use Visual Studio code to edit the code or other editor.  Eg.
```
> cd .../picosystem/examples/mule
> code .
'''
