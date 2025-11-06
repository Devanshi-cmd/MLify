/lib : External Libraries like SDL2, so users dont have to install them in order to use our library

# HOW TO RUN:
* To run SDL program: run command `make run`
* To run OpenGL program-> compiler flags:` -lGL -lGLEW -lglfw -lm `

# Install Dependencies
### OpenGL
* Mac: run ` /bin/bash -c "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/HEAD/install.sh)" ` then
 `brew install glfw `
* Linux (depending on your Distro): Ubuntu/Debain: `sudo apt-get install libglfw3-dev libgl1-mesa-dev` Arch: `sudo pacman -S glfw-x11`