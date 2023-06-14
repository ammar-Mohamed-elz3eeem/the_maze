# The Maze

- [Introduction](#Introduction)
- [Installation](#Installation)
- [Usage](#Usage)
- [Author](#Author)
- [License](#License)

### Introduction

![The Maze](https://github.com/ammar-Mohamed-elz3eeem/The-Maze/blob/main/The-maze-ammar-massoud-banner.png)

This project is a 3D Game called (The Maze) the project was built with C prgramming language with the help of SDL Library for the sake of GUI
here is a full detailed article about the maze project and what challenges we had while developing the game [The Maze on LinkedIn](https://www.linkedin.com/pulse/first-3d-experience-maze-project-ammar-massoud)

### Installation
to install the game you need to clone this repo into your device

```
git clone https://github.com/ammar-Mohamed-elz3eeem/The-Maze
```

to be able to install the game on your device you must have gcc compiler with library SDL installed into it
once the game is cloned you can install it using gcc command this way
```
gcc source/*.c -O2 -g -Wall -Werror -Wextra -pedantic -Isource/headers -lSDL2 -lSDL2_image -lm -o maze `sdl2-config --cflags --libs`
```

if you are on linux system you can use make command with the MakeFile in the project folder this way
```
make -f MakeFile
```

### Usage

to be able to use the game once installed you need to run file named maze on the command line
```
./maze
```

### Author 
[Ammar Massoud](ammarmohamedthez@gmail.com)

### License
This project is licensed under MIT
