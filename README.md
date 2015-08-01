# Eurobot Bare Module Project

<!-- START doctoc generated TOC please keep comment here to allow auto update -->
<!-- DON'T EDIT THIS SECTION, INSTEAD RE-RUN doctoc TO UPDATE -->
**Table of Contents** *generated with [DocToc](http://doctoc.herokuapp.com/)*

- [About](#about)
  - [What are theses modules and for what ?](#what-are-theses-modules-and-for-what-)
  - [Who are we ?](#who-are-we-)
- [Workspace configuration](#workspace-configuration)
  - [Needed software](#needed-software)
    - [Debian Linux](#debian-linux)
    - [Archlinux](#archlinux)
    - [OS X](#os-x)
  - [Repository configuration](#repository-configuration)
- [Build and use a module](#build-and-use-a-module)
- [How to create a new module](#how-to-create-a-new-module)
- [How to update a module from the bare repository](#how-to-update-a-module-from-the-bare-repository)
- [Copyright and License](#copyright-and-license)

<!-- END doctoc generated TOC please keep comment here to allow auto update -->

## About

This is a bare module project from which all of our other module projects are forking from. This repository contains the worskpace (based on [Ladislas's Bare Arduino Project](https://github.com/ladislas/Bare-Arduino-Project)), the shared libraries (like communication between modules) and examples to create new Arduino based modules for our robot.

### What are theses modules and for what ?

Let start from the beginning!

All repositories that begin with `eurobot-*` on our account concern our participation in the *Eurobot contest*: An international amateur robotics contest open to teams of young people. Our goal is to create one or two robots with most of the parts reusable every year. This is not so easy because the rules of the contest change every year, so we have to adapt.

In order to reuse most of the parts, we separate the robot in different modules. Generally, we will have:

* a core module: an embedded Linux (like Raspberry Pi 2) which run NodeJs scripts.
* a position module: it will move the robot, calculate the position and trajectories

We will then have some other modules that will change regarding the rules of the contest. All of our modules, except the core, have the same minimal hardware:

* Atmega 328p with an Arduino bootloader
* MCP2551 and MCP2515 to allow him to communicate via Bus CAN with every other module

Each module gets the regulated alimentation of 5V and if needed the direct output of the battery (14 to 16V) which is stopped when you press the big red button of ~~science~~ emergency.

### Who are we ?

We are the *Robotik UTT* team. An association of student from the University of Technology of Troyes (UTT), a french engineering university.

## Workspace configuration

### Needed software

* `Git`: To work with this repository
* `arduino`: To have Arduino libraries and board descriptions
* `avr-gcc`: A compiler for atmel avr microcontrollers
* `binutils`: Some tools to create the final binary file
* `avr-libc`: The standard library for atmel avr microcontrollers
* `avrdude`: Tool to program atmel avr microcontrollers
* `python-serial` (with python 2 or 3): Used by Arduino-Makefile to reset before upload Arduino

#### Debian Linux

```Bash
# First add the git-core ppa
sudo add-apt-repository ppa:git-core/ppa

# Update list
sudo apt-get update && sudo apt-get upgrade

# Install everything
sudo apt-get install git arduino gcc-avr binutils avr-libc avrdude python-serial
```

Make sure everything is up and running by running `avr-gcc -v` and `avrdude -v`.


#### Archlinux

Arduino is not in the official repository, we will have to use an aur repository. If you don't have it, install yaourt by adding `archlinuxfr` as a `pacman` repository :

```Bash
sudo bash -c "echo \"

[archlinuxfr]
SigLevel = Never
Server = http://repo.archlinux.fr/\\\$arch
\" >> /etc/pacman.conf"

# Update your system and programm list and install yaourt
pacman -Syu yaourt
```

Then we can install everything with yaourt (which have the same syntax as pacman) :

```Bash
yaourt -S git arduino avrdude avr-gcc avr-binutils avr-libc python-pyserial
```

Make sure everything is up and running by running `avr-gcc -v` and `avrdude -v`.


#### OS X

Before starting, please make sure you have those installed:

*   [Arduino IDE 1.0.x or 1.6.x](http://arduino.cc/en/main/software#toc2) - Download the app from the website
*   [Homebrew](http://mxcl.github.io/homebrew/) - Follow the instructions on their website
*   [Git](http://git-scm.com/) - use `brew install git` to install the latest version


Then we can use brew to install everything except python-serial which we will install with pip (installed with python)

```Bash
brew tap osx-cross/avr
brew install avr-libc
brew install avrdude
brew install python
pip install pyserial
```

### Repository configuration

After cloning the repository and before using or working inside, you will have to configure it. 

First `cd` to your repository folder:

```Bash
# Update git that are inside our repository (arduino-makefile and nanopb)
git submodule update --init --recursive
```

You will have to create your platform-specific Makefile. Go to the source folder `src/main`. Generally, you will have only a `main` directory that contains the source code for Arduino, but sometime, you will have another folder that will contain code for a second Arduino in the module or a hardware test code for the module. You will have to create a Makefile for each src/XXXX folder.

```Bash
cd src/XXXX

# Copy `makefile-linux.mk` or `makefile-osx.mk` in the current directory as `Makefile`
cp ../makefile-linux.mk ./Makefile

# Edit the Makefile to suit your needs
nano Makefile
```

TODO : add sudo pacman -S python2-protobuf
TODO : add make -C NanoPb/generator/proto


## Build and use a module

TODO

## How to create a new module

TODO

## How to update a module from the bare repository

TODO

## Copyright and License

This project is led by the [Robotik UTT team](https://github.com/RobotikUTT/). The [Eurobot bare module project](https://github.com/RobotikUTT/eurobot-bare-module) that this project use, is based on [Bare arduino project](https://github.com/ladislas/Bare-Arduino-Project) from Ladislas de Toldi.


    The MIT License (MIT)

    Copyright (c) 2015 Robotik UTT
    Copyright (c) 2014 Ladislas de Toldi - ladislas at weareleka dot com

    Permission is hereby granted, free of charge, to any person obtaining a copy
    of this software and associated documentation files (the "Software"), to deal
    in the Software without restriction, including without limitation the rights
    to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
    copies of the Software, and to permit persons to whom the Software is
    furnished to do so, subject to the following conditions:

    The above copyright notice and this permission notice shall be included in all
    copies or substantial portions of the Software.

    THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
    IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
    FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
    AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
    LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
    OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
    SOFTWARE.
