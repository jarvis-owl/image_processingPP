# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.6

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/pi/github/image_processingPP

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/pi/github/image_processingPP/build

# Include any dependencies generated for this target.
include CMakeFiles/simpleCV.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/simpleCV.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/simpleCV.dir/flags.make

CMakeFiles/simpleCV.dir/simpleCV.cpp.o: CMakeFiles/simpleCV.dir/flags.make
CMakeFiles/simpleCV.dir/simpleCV.cpp.o: ../simpleCV.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/pi/github/image_processingPP/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/simpleCV.dir/simpleCV.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/simpleCV.dir/simpleCV.cpp.o -c /home/pi/github/image_processingPP/simpleCV.cpp

CMakeFiles/simpleCV.dir/simpleCV.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/simpleCV.dir/simpleCV.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/pi/github/image_processingPP/simpleCV.cpp > CMakeFiles/simpleCV.dir/simpleCV.cpp.i

CMakeFiles/simpleCV.dir/simpleCV.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/simpleCV.dir/simpleCV.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/pi/github/image_processingPP/simpleCV.cpp -o CMakeFiles/simpleCV.dir/simpleCV.cpp.s

CMakeFiles/simpleCV.dir/simpleCV.cpp.o.requires:

.PHONY : CMakeFiles/simpleCV.dir/simpleCV.cpp.o.requires

CMakeFiles/simpleCV.dir/simpleCV.cpp.o.provides: CMakeFiles/simpleCV.dir/simpleCV.cpp.o.requires
	$(MAKE) -f CMakeFiles/simpleCV.dir/build.make CMakeFiles/simpleCV.dir/simpleCV.cpp.o.provides.build
.PHONY : CMakeFiles/simpleCV.dir/simpleCV.cpp.o.provides

CMakeFiles/simpleCV.dir/simpleCV.cpp.o.provides.build: CMakeFiles/simpleCV.dir/simpleCV.cpp.o


# Object files for target simpleCV
simpleCV_OBJECTS = \
"CMakeFiles/simpleCV.dir/simpleCV.cpp.o"

# External object files for target simpleCV
simpleCV_EXTERNAL_OBJECTS =

simpleCV: CMakeFiles/simpleCV.dir/simpleCV.cpp.o
simpleCV: CMakeFiles/simpleCV.dir/build.make
simpleCV: /opt/vc/lib/libmmal_core.so
simpleCV: /opt/vc/lib/libmmal_util.so
simpleCV: /opt/vc/lib/libmmal.so
simpleCV: /usr/local/lib/libopencv_videostab.so.3.0.0
simpleCV: /usr/local/lib/libopencv_superres.so.3.0.0
simpleCV: /usr/local/lib/libopencv_stitching.so.3.0.0
simpleCV: /usr/local/lib/libopencv_shape.so.3.0.0
simpleCV: /usr/local/lib/libopencv_photo.so.3.0.0
simpleCV: /usr/local/lib/libopencv_objdetect.so.3.0.0
simpleCV: /usr/local/lib/libopencv_hal.a
simpleCV: /usr/local/lib/libopencv_calib3d.so.3.0.0
simpleCV: /usr/local/lib/libopencv_features2d.so.3.0.0
simpleCV: /usr/local/lib/libopencv_ml.so.3.0.0
simpleCV: /usr/local/lib/libopencv_highgui.so.3.0.0
simpleCV: /usr/local/lib/libopencv_videoio.so.3.0.0
simpleCV: /usr/local/lib/libopencv_imgcodecs.so.3.0.0
simpleCV: /usr/local/lib/libopencv_flann.so.3.0.0
simpleCV: /usr/local/lib/libopencv_video.so.3.0.0
simpleCV: /usr/local/lib/libopencv_imgproc.so.3.0.0
simpleCV: /usr/local/lib/libopencv_core.so.3.0.0
simpleCV: /usr/local/lib/libopencv_hal.a
simpleCV: CMakeFiles/simpleCV.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/pi/github/image_processingPP/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable simpleCV"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/simpleCV.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/simpleCV.dir/build: simpleCV

.PHONY : CMakeFiles/simpleCV.dir/build

CMakeFiles/simpleCV.dir/requires: CMakeFiles/simpleCV.dir/simpleCV.cpp.o.requires

.PHONY : CMakeFiles/simpleCV.dir/requires

CMakeFiles/simpleCV.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/simpleCV.dir/cmake_clean.cmake
.PHONY : CMakeFiles/simpleCV.dir/clean

CMakeFiles/simpleCV.dir/depend:
	cd /home/pi/github/image_processingPP/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/pi/github/image_processingPP /home/pi/github/image_processingPP /home/pi/github/image_processingPP/build /home/pi/github/image_processingPP/build /home/pi/github/image_processingPP/build/CMakeFiles/simpleCV.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/simpleCV.dir/depend

