BCAMSC Robotics Template Project
================================
This project is meant to serve as a template for new projects. To use it, clone
the project, then change the remote to a new location for the new project:

````sh
git remote set-url origin https://new-url/project.git
````

After pulling the repository, be sure to execute the `setup.sh` script in order
to use the libraries properly.

Place your code in any files you wish. The main ones to use are `vexuser.c` and
`vexuser.h`.

If you do create additional files, be sure to add them to the list in
`setup.mk`.

Debugging
=========
Follow the instructions located
[here](https://jpearman.github.io/convex/doxygen/html/debug.html) for an
extremely useful debugging system that is by default enabled in this project.

To disable debugging, edit the top-level `Makefile`. Find the line that begins
with `UDEFS =`. Add `-DDEBUG=0` to this line, so that it looks like this:

````Makefile
UDEFS = -DDEBUG=0
````

Note that you should *not* edit the similar line in the "defaults" section of
the `Makefile`.


First Time Setup
================
## Installing the Arm Toolchain
### Linux
[Linaro](http://www.linaro.org/) is a good choice for a cross-compiler
toolchain. If you are on a Debain-based system (e.g., Ubuntu, etc.), you can
install it using the following commands:

````sh
sudo add-apt-repository ppa:linaro-maintainers/toolchain
sudo apt-get install gcc-arm-none-gnueabi
````

### Windows or OS X
See the instructions on
[this page](http://jpearman.github.io/convex/doxygen/html/install_p1.html) for
installing the Yagarto ARM toolchain.

## Install CortexFlash
Install the cortex flash tool. If you are on OS X or Windows, a precompiled
binary can be found in the
[github project](https://github.com/jpearman/stm32flashCortex). If you are on
Linux, simply clone the repository, and execute `make` in the root directory
of the repository. A suitable executable will be generated for you.

More details can be found
[here](http://jpearman.github.io/convex/doxygen/html/install_p4.html).
