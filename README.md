<!-- START doctoc generated TOC please keep comment here to allow auto update -->
<!-- DON'T EDIT THIS SECTION, INSTEAD RE-RUN doctoc TO UPDATE -->
**Table of Contents**  *generated with [DocToc](https://github.com/thlorenz/doctoc)*

- [Eurobot Bare Module Project](#eurobot-bare-module-project)
  - [About](#about)
    - [Motivations](#motivations)
    - [Who are we ?](#who-are-we-)
  - [Workspace configuration](#workspace-configuration)
    - [Dependencies](#dependencies)
      - [Debian](#debian)
      - [Archlinux](#archlinux)
        - [Install yaourt](#install-yaourt)
      - [Install dependencies](#install-dependencies)
      - [OS X](#os-x)
    - [Repository configuration](#repository-configuration)
  - [Build and use a module](#build-and-use-a-module)
  - [How to create a new module](#how-to-create-a-new-module)
  - [How to update a module from the bare repository](#how-to-update-a-module-from-the-bare-repository)
  - [Copyright and License](#copyright-and-license)

<!-- END doctoc generated TOC please keep comment here to allow auto update -->

# Eurobot Bare Module Project

## About

This is a bare module project from which all of our other module projects are forking from. This repository contains an example structure (based on [Ladislas's Bare Arduino Project](https://github.com/ladislas/Bare-Arduino-Project)) and the common librairies (like mcp_can).


### Motivations

All repositories beginning with `eurobot-*` are part of the Robotik UTT participation for the [eurobot](http://www.eurobot.org/) contest.

In order to reuse some parts every year, the robot code is splitted between independent modules.  

Each module has the following minimal hardware:
* Atmega 328p with an Arduino bootloader
* MCP2551 and MCP2515 to provide a CAN Bus interface

### Who are we ?

We are the *Robotik UTT* team. A student club of Robotics, from the University of Technology of Troyes (France).


## Workspace configuration

### Dependencies

* `arduino`: Provide arduino librairies
* `avr-gcc`: Compiler for atmel avr microcontrollers
* `avr-libc`: The standard library for atmel avr microcontrollers
* `avrdude`: Programmer for atmel avr microcontrollers
* `binutils`: Binary tools
* `python-serial` (with python 2 or 3): Reset arduino before programming it

#### Debian

```Bash
# First add the git-core ppa
sudo add-apt-repository ppa:git-core/ppa

# Update list
sudo apt-get update && sudo apt-get upgrade

# Install dependencies
sudo apt-get install git arduino gcc-avr binutils avr-libc avrdude python-serial
```
Check that everything is up: `avr-gcc -v && avrdude -v`.


#### Archlinux

Arduino is not in the official repository, but in community-driven repositories (AUR).

##### Install yaourt

```Bash
sudo bash -c "echo \"

[archlinuxfr]
SigLevel = Never
Server = http://repo.archlinux.fr/\\\$arch
\" >> /etc/pacman.conf"

# Update your system and programm list and install yaourt
pacman -Syu yaourt
```

#### Install dependencies

```Bash
yaourt -S git arduino avrdude avr-gcc avr-binutils avr-libc python-pyserial
```

Check that everything is up: `avr-gcc -v && avrdude -v`.


#### OS X

*   [Arduino IDE 1.0.x or 1.6.x](http://arduino.cc/en/main/software#toc2) - Download the app from the website
*   [Homebrew](http://mxcl.github.io/homebrew/) - Follow the instructions on their website


```Bash
brew tap osx-cross/avr
brew install avr-libc
brew install avrdude
brew install python
pip install pyserial
```

Check that everything is up: `avr-gcc -v && avrdude -v`.


### Repository configuration

First `cd` to your repository folder:

```Bash
# Update git submodules
git submodule update --init --recursive
```

You will have to create your platform-specific Makefile. Examples are given in the `src` folder.
Each `src/XXXX` contains the source code for an Arduino: make sure that each of these folders contains it's own Makefile.

```Bash
cd src/XXXX

# Copy `makefile-linux.mk` or `makefile-osx.mk` in the current directory as `Makefile`
cp ../makefile-linux.mk ./Makefile

# Edit the Makefile to suit your needs
nano Makefile
```

## Build and use a module

TODO

## How to create a new module

TODO

## How to update a module from the bare repository

TODO

## Copyright and License

This project is led by the [Robotik UTT team](https://github.com/RobotikUTT/). Thanks to [Bare arduino project](https://github.com/ladislas/Bare-Arduino-Project) from Ladislas de Toldi for the structure.

See the LICENSE.md file