For an unknown reason this plugin crashes in Gimp 2.99x and likely will still stay broke in Gimp 3. I don't know how to solve this. But it works great in 2.10

GEGL Trail and Multistroke
=========

A custom GEGL filter that does a color fill trail and multi stroke layer effects.
![image preview](color_fill_trail2.png)

![image](https://github.com/LinuxBeaver/GEGL-Color-Fill-Trail/assets/78667207/97c30b10-8e99-48d0-a327-8b7c41c11360)


Early versions of this plugin required using the behind blend mode and clip setting. However this is not the case anymore.


## OS specific location to put GEGL Filter binaries 

Windows
 C:\\Users\<YOUR NAME>\AppData\Local\gegl-0.4\plug-ins
 
 Linux 
 /home/(USERNAME)/.local/share/gegl-0.4/plug-ins
 
 Linux (Flatpak)
 /home/(USERNAME)/.var/app/org.gimp.GIMP/data/gegl-0.4/plug-ins


## Compiling and Installing

### Linux

To compile and install you will need the GEGL header files (`libgegl-dev` on
Debian based distributions or `gegl` on Arch Linux) and meson (`meson` on
most distributions).

```bash
meson setup --buildtype=release build
ninja -C build
```

If you have an older version of gegl you may need to copy to `~/.local/share/gegl-0.3/plug-ins`
instead (on Ubuntu 18.04 for example).



### Windows

The easiest way to compile this project on Windows is by using msys2.  Download
and install it from here: https://www.msys2.org/

Open a msys2 terminal with `C:\msys64\mingw64.exe`.  Run the following to
install required build dependencies:

```bash
pacman --noconfirm -S base-devel mingw-w64-x86_64-toolchain mingw-w64-x86_64-meson mingw-w64-x86_64-gegl
```

Then build the same way you would on Linux:

```bash
meson setup --buildtype=release build
ninja -C build
```

## More previews of this based Gimp Plugin

![image](https://github.com/LinuxBeaver/GEGL-Color-Fill-Trail/assets/78667207/74d60e98-19c1-419e-a81d-e269ed314842)

![image](https://github.com/LinuxBeaver/GEGL-Color-Fill-Trail/assets/78667207/334398ff-65c0-4ad5-9156-a872295365e4)

![image](https://github.com/LinuxBeaver/GEGL-Color-Fill-Trail/assets/78667207/0b3dcf59-79d3-4826-bab5-f6972547f5fd)

![image](https://github.com/LinuxBeaver/GEGL-Color-Fill-Trail/assets/78667207/5672f974-a147-4781-a307-2434ec5857dd)




