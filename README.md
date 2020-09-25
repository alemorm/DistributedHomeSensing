# Distributed Home Sensing

## Energy Efficient Home

## Description

Measuring the home temperature, light intensity, and power consumption of a home in order to analyze its overall energy effiency.

---

## Overview

![hardware]

---

![softwareoverview]

---

![software]

---

## Setup

### Host Code Development

The development of the host code happens on the host device. The host device is a Windows 10 desktop running [Windows Subsystem for Linux (v1)][wsl] with [Ubuntu 18.04.4 LTS][ubuntu] and [VSCode (v1.46.1)][vscode] with the [remote SSH development][sshext], [C/C++][c++], and [Python extensions][pythonext]. The Python extension uses a [`conda (v4.8.3)`][conda] [environment] (provided).

### Embedded Code Development

The development of the embedded source code happens on the host device and the compilation happens on the Raspberry Pi.  Once the source code is updated on the host device, a [VSCode compound task][vstasks] uses [`rsync`] for synchronization and [`ssh`] commands for remote compilation using [`cmake (v3.6.2)`][cmake] on the Raspberry Pi. This remote compilation strategy was chosen over an emulator such as [qemu] due to the emulation performance decrease, which could impact the build time for more complex projects.

### Getting Started

<!-- Links -->
[hardware]: img/HardwareBlockDiagram.png
[software]: img/SoftwareBlockDiagram.png
[softwareoverview]: img/SoftwareOverviewDiagram.png
[`threephasegenerator`]: src/threephasegenerator.c
[`threephaseforwarder`]: src/threephaseforwarder.c
[`udp_3phase`]: scripts/udp_3phase.py
[`liveplotter`]: scripts/liveplotter.py
[clean3phase]: img/Noise0p0Frequency20.gif
[noisy3phase]: img/Noise0p1Frequency20.gif
[vstasks]: .vscode/tasks.json
[qemu]: https://www.poftut.com/qemu-tutorial/
[cmake]: https://cmake.org/cmake/help/latest/guide/tutorial/index.html
[`ssh`]: https://www.digitalocean.com/community/tutorials/ssh-essentials-working-with-ssh-servers-clients-and-keys
[raspberrypi]: https://www.raspberrypi.org/products/raspberry-pi-3-model-b/
[`rsync`]: https://www.digitalocean.com/community/tutorials/how-to-use-rsync-to-sync-local-and-remote-directories-on-a-vps
[wsl]: https://docs.microsoft.com/en-us/windows/wsl/install-win10
[ubuntu]: https://www.microsoft.com/en-us/p/ubuntu-1804-lts/9n9tngvndl3q
[vscode]: https://code.visualstudio.com/
[sshext]: https://code.visualstudio.com/docs/remote/ssh
[c++]: https://code.visualstudio.com/docs/languages/cpp
[pythonext]: https://code.visualstudio.com/docs/python/python-tutorial
[conda]: https://docs.conda.io/en/latest/miniconda.html
[environment]: environment.yml