# RayTracer
Creating a raytracer in c++

## Dependencies

This project relies on two main external libraries: GLEW (OpenGL Extension Wrangler Library) and SDL2 (Simple DirectMedia Layer). Both of these libraries have been bundled in the `Dependencies` folder for ease of use. Below are details on each of the dependencies:

---

### GLEW (2.2.0)

- **Description**: 
  GLEW is a cross-platform library that helps in querying and loading OpenGL extensions. This allows for better compatibility across various platforms and systems.

- **Role in this project**: 
  Used to facilitate OpenGL function calls and manage extensions.

- **Setup**:
  - Download the required version of SDL2 (2.28.4) from the [GLEW Official Website](http://glew.sourceforge.net/).
  - Ensure that your project links to the appropriate `.lib` or `.dll` files within this directory.

---

### SDL2 (2.28.4)

- **Description**: 
  SDL2 is a cross-platform development library designed to provide low level access to audio, keyboard, mouse, joystick, and graphics hardware.

- **Role in this project**: 
  Used to handle window creation, input events, and provide a rendering context.

- **Setup**:
  - Download the required version of SDL2 (2.28.4) from the [SDL2 Official Website](https://www.libsdl.org/).
  - Make sure to link against the provided SDL2 libraries and include the header files in your project settings.
  
---
## Folder Structure
Below is the main directory structure of the project:

RayTracer/
|
|-- Dependencies/
| |-- glew-2.2.0/
| | |-- ... (GLEW files and folders)
| |
| |-- SDL2-2.28.4/
| |-- ... (SDL2 files and folders)
|
|-- RayTracer/
| |-- ... (Source files, headers, and other related contents for RayTracer)
|
|-- RayTracer.sln

---

**Note to developers**:

If you're building the project, ensure that your build tool or IDE knows where to find these dependencies. You might need to adjust your include paths, library paths, and linker settings accordingly.
