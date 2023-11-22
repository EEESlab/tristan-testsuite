# TRISTAN Testsuite

## Getting started

These instructions were developed using a fresh Ubuntu 22.04 64-Bit.

First of all, you will need:
* PULP-SDK (https://github.com/EEESlab/pulp-sdk.git) containing the runtime to run applications on PULP devices and GVSoC, an event-based simulator specifically developed for quick runapplications 100% functional and 90% timing accurately resectively.
* Compiler tools to compile the applications. These are:
    * GCC (https://github.com/EEESlab/corev-gcc.git)
    * Binutils and GDB (https://github.com/EEESlab/corev-binutils-gdb.git)

We recap here the passes to install both tools on your machine.

## Downloading PULP-SDK

We would point to the actual repository documentation for further information.

The following packages needed to be installed:

~~~shell
sudo apt-get install -y build-essential git libftdi-dev libftdi1 doxygen python3-pip libsdl2-dev curl cmake libusb-1.0-0-dev scons gtkwave libsndfile1-dev rsync autoconf automake texinfo libtool pkg-config libsdl2-ttf-dev
~~~

The SDK also requires the `argcomplete`, `pyelftools` and `prettytable` Python package. You can install them for the local user with:

~~~shell
pip install --user argcomplete pyelftools prettytable
~~~

Omit `--user` to install at system level instead, which will probably require admin rights.

To install the SDK do:

~~~shell
git clone https://github.com/EEESlab/pulp-sdk.git
~~~

Then, switch to the `tristan-dev` branch with:

~~~shell
cd pulp-sdk
git fetch origin tristan-dev
git checkout tristan-dev
~~~

and update the submodules

~~~shell
git submodule update --init --recursive
~~~

## Setting up GVSoC

The following packages needed to be installed:

~~~shell
sudo apt-get install -y build-essential git doxygen python3-pip libsdl2-dev curl cmake gtkwave libsndfile1-dev rsync autoconf automake texinfo libtool pkg-config libsdl2-ttf-dev
~~~

Additional Python packages are needed and can be installed with the following commands from root folder:

~~~shell
pip3 install -r tools/gvsoc/core/requirements.txt
pip3 install -r tools/gvsoc/gapy/requirements.txt
~~~

## Downloading PULP compiler

You can download the GCC tools by doing the following:

~~~shell
git clone https://github.com/EEESlab/corev-gcc.git
git clone https://github.com/EEESlab/corev-binutils-gdb.git
~~~

Then, switch to the `tristan-dev` branches with:

~~~shell
cd corev-gcc
git fetch origin tristan-dev
git checkout tristan-dev
~~~

and

~~~shell
cd corev-binutils-gdb
git fetch origin tristan-dev
git checkout tristan-dev
~~~

## Installing PULP Compiler

To install them you need more GNU packages. Install them with:

~~~shell
git clone https://github.com/riscv/riscv-newlib.git
~~~

Then, you can easily install all of them safely using our script by doing:

~~~shell
cd corev-gcc
source build-corev-gcc-tools.sh --all
~~~

Once all the tools are correctly installed, define the path in which there is toolchain bin folder. The installation script defines by default `./toolchain_install`. The absolute path is storeid in the environment variable `INSTALL_PREFIX` and can be used in the same environment by doing:

~~~shell
export PULP_RISCV_GCC_TOOLCHAIN=$INSTALL_PREFIX
~~~

## Installing PULP-SDK

Source the file corresponding to the desired configuration:

~~~shell
cd pulp-sdk
source configs/pulp-open.sh
~~~

Compile GVSoC with this command:

~~~shell
make build TARGETS=pulp-open
~~~

## Running tests on GVSoC

Then, go to a test, for example `./hello`, and execute:

~~~shell
make clean all run
~~~
