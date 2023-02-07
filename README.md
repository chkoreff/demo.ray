demo.ray - Demo of graphics applications built by Fexl
======================================================

Running demos
-------------

First go into the source code directory:
```
cd src
```

To run the hardcoded demo.c:
```
./demo
```

To run a demo built by Fexl:
```
fexl demo_9457.fxl
```

Prerequisites
-------------

# Fexl

Install Fexl from https://github.com/chkoreff/Fexl .  My preference is to
build it in my own ~/code/fexl directory and then make it available from the
command line with a shell alias in ~/.bash_aliases:

	alias fexl=~/code/fexl/bin/fexl

# Raylib

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
