# videoConverter
convert video to sequential images using OpenCV.
mini opencv program.
**This one is a modification of OpenCV 2.4 demo, start_video**
### Usage
```bash
$ mkdir build
$ cd build
$ cmake ..
$ make
$ mkdir image
$ ./videoConverter path/to/video
```
### Para Setting
* stride, sequence name for images, path to images could be modified in .cpp
### Note
* no detection for whether the folder for sequential images exists, manually create it. 
