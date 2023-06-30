GEGL Trail and Multistroke
=========

A custom GEGL filter that does a color fill trail and multi stroke layer effects.
PLEASE CHANGE THE CLIPPING MODE FROM ADJUST TO CLIP FOR THIS FILTER TO WORK PROPER!

![image preview](color_fill_trail2.png)

![image](https://github.com/LinuxBeaver/GEGL-Color-Fill-Trail/assets/78667207/97c30b10-8e99-48d0-a327-8b7c41c11360)



## OS specific location to put GEGL Filter binaries 

Windows
 C:\\Users\<YOUR NAME>\AppData\Local\gegl-0.4\plug-ins
 
 Linux 
 /home/(USERNAME)/.local/share/gegl-0.4/plug-ins
 
 Linux (Flatpak)
 /home/(USERNAME)/.var/app/org.gimp.GIMP/data/gegl-0.4/plug-ins

 ### Linux

To compile and install you will need the GEGL header files (`libgegl-dev` on
Debian based distributions or `gegl` on Arch Linux) and meson (`meson` on
most distributions).

```bash
meson setup --buildtype=release build
ninja -C build


## OS specific location to put GEGL Filter binaries 

Windows
 C:\\Users\<YOUR NAME>\AppData\Local\gegl-0.4\plug-ins
 
 Linux 
 /home/(USERNAME)/.local/share/gegl-0.4/plug-ins
 
 Linux (Flatpak)
 /home/(USERNAME)/.var/app/org.gimp.GIMP/data/gegl-0.4/plug-ins

