RsaToolbox
==========

`RsaToolbox` is a library written in C++ with Qt 5 for control of Rohde & Schwarz general test equipment.

Requirements
------------
RsaToolbox should work with any version of Qt 5. That said, it has only been used and tested with the open source (LGPL & GPL) distribution of Qt 5.2.1 compiled for Windows using Visual C++ 2010 x86 and DirectX. This is to support installation on older instruments still running Windows XP Embedded Service Pack 2 (Qt 5.2.1 has been extensively tested on this instrument platform).

As Windows XP instruments dwindle, development and test will move to a newer version of Qt 5.

The Visual C++ 2010 installer download has been buried on the web (Microsoft wants us all to migrate). Here is a link that is working as of 11/2016:
[Microsoft Visual Studio 2010 Express Edition](https://www.microsoft.com/en-us/download/details.aspx?id=23691)

Qt 5.2.1 can be installed using the Qt online installer found here:
[Qt Open-source Online Installer for Windows](https://www.qt.io/download-open-source/)


Build and Install
-----------------

The following steps assume that Visual C++ 2010 Express is installed, as well as Qt 5.2.1 (see links above).

First copy the repo to your system.  
With git:

`git clone git@github.com:Terrabits/RsaToolbox.git`

Then open the project. The main project file is in the root directly of the project.

`rsatoolbox.pro`

When you first open the project, Qt Creator will ask you choose the build package and location that you want to use. Use the following settings:

