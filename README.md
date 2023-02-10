# demo.ray

## Demo of graphics applications built by Fexl

### Running the demos

First go into the source code directory:
```
cd src
```

In this demo, you fly through a rolling 3D landscape of random blocks:

```
fexl demo_0462.fxl
```

In these demos, you walk around a 3D landscape of random blocks:

```
fexl demo_9457.fxl
fexl demo_6611.fxl
```

The only difference is that demo_9457 builds the scene as completely static
code all in one object file, and demo_6611 uses dynamic lists of objects whose
types are defined in auxiliary object files such as plane.o, cube.o, etc.
So those demos should produce exactly the same experience, but they illustrate
different code generation techniques.

The advantage of demo_6611 going forward is that new objects could be created
at run time, and the attributes of existing objects could be changed.  That is
not possible in the static demo_9457.

### Run from any directory

All these demos are position-independent, meaning they can be run from any
directory on the file system by specifying a full path.  For example, let's
say you installed demo.ray in your `~/project/demo.ray` directory.  Then you
could do this:

```
cd ~
fexl project/demo.ray/src/demo_0462.fxl
```

### Run on Windows

I was able to run the demos on Windows by means of
[Windows Subsystem for Linux (WSL)](https://learn.microsoft.com/en-us/windows/wsl/install).  After installing WSL on the Windows machine, I could bring up
the `Ubuntu` app through the Start menu, which put me into a shell prompt,
where I cloned this `demo.ray` project and built the prequisites (see below).
Then from a Windows command prompt I ran:

```
wsl.exe ~/code/fexl/bin/fexl project/demo.ray/src/demo_0462.fxl
```

I also tried that in a `demo_0462.bat` file and it worked fine.

## Utilities

I created a "splitter" utility which helps with converting an existing block
of hand-written C code into a Fexl function which reproduces that C code.
This helped me convert the old static `demo.c` into the new demo_6611.fxl.

Here's an example of running the splitter:

```
fexl splitter.fxl cube.c
```

## Prerequisites

### Fexl

Install Fexl from https://github.com/chkoreff/Fexl .  My preference is to
build it in my own `~/code/fexl` directory and then make it available from the
command line with a shell alias in `~/.bash_aliases`:

```
alias fexl=~/code/fexl/bin/fexl
```

### Raylib

Here are some instructions on installing raylib:

https://github.com/raysan5/raylib/wiki/Working-on-GNU-Linux

Typically:
```
sudo apt install libasound2-dev mesa-common-dev libx11-dev libxrandr-dev libxi-dev xorg-dev libgl1-mesa-dev libglu1-mesa-dev

git clone https://github.com/raysan5/raylib.git raylib
cd raylib
mkdir build && cd build
cmake -DBUILD_SHARED_LIBS=ON ..
make
sudo make install

cd src
make
```
