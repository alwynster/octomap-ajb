# - Config file for the OctoMap package
# (example from http://www.vtk.org/Wiki/CMake/Tutorials/How_to_create_a_ProjectConfig.cmake_file)
# It defines the following variables
#  OCTOVIS_INCLUDE_DIRS - include directories for OctoMap viewer
#  OCTOVIS_LIBRARY_DIRS - library directories for OctoMap viewer 
#  OCTOVIS_LIBRARIES    - libraries to link against
 
set(OCTOVIS_INCLUDE_DIRS "/home/alwynster/git/octomap/octovis/src/extern/QGLViewer" "/home/alwynster/git/octomap/octovis/include")
set(OCTOVIS_LIBRARY_DIRS "/home/alwynster/git/octomap/octovis/src/extern/QGLViewer" "/usr/local/lib")


# Set library names as absolute paths:
set(OCTOVIS_LIBRARIES
  "QGLViewer"
  "optimized;/usr/lib64/libQtOpenGL.so;debug;/usr/lib64/libQtOpenGL.so;optimized;/usr/lib64/libQtGui.so;debug;/usr/lib64/libQtGui.so;optimized;/usr/lib64/libQtXml.so;debug;/usr/lib64/libQtXml.so;optimized;/usr/lib64/libQtCore.so;debug;/usr/lib64/libQtCore.so"
  "/usr/local/lib/liboctovis.so"
)
