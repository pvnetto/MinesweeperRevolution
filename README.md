# Minesweeper Revolution

[Game executable](https://www.dropbox.com/s/riu3ovolehx8m8h/MinesweeperRevolution_build.zip?dl=0)

This project was made with C++ using the [Visual Studio Community 2017](https://visualstudio.microsoft.com/pt-br/vs/older-downloads/) IDE and [SFML](https://www.sfml-dev.org/index.php) for graphics and input handling.

## Screenshots

![Main Menu](/Screenshots/msrevo_main_menu.png)

![In-Game](/Screenshots/msrevo_ingame.png)

![Game Over](/Screenshots/msrevo_gameover.png)

## Running the project

### Dependencies
- gcc
- [Visual Studio 2017](https://visualstudio.microsoft.com/pt-br/vs/older-downloads/)

### Steps

To run the project, you should simply:

- Install Visual Studio
- Clone the project
- Open the solution on Visual Studio.

I used VS 2017, so that's what I would recommend to avoid compatibility problems.


## Contributing

If you're reading this and want to contribute to this project, here goes a little overview about the architecture I'm using. Basically the game has a **Context Manager**, which contains and executes a single **Context** with multiple **Entities**.

### Entity
An entity is a game object that can handle input, get drawn to the screen and contains game logic. 

### Context
Contexts are like scenes in Unity3D. They handle initialization, drawing and inputs for game entities.

### ContextManager
A ContextManager's sole purpose is to execute the current context, and switch the context when requested by an entity. 

## Directory structure
The project itself doesn't have an organized directory structure, but that's because Visual Studio uses a featured called filters to organize the solution in directories without having to deal with the OS folder structure. One of the biggest advantages of this approach is that we can move files deliberately between filters without having to refactor includes.

    .
    ├── Assets          # Textures, fonts, audio etc
    │   └── Fonts
    │   └── Textures
    │
    └── Source          # All source code for the project is in this folder
       └── UI           # UI related components, like canvases, buttons etc
       └── Context      # Classes for game contexts
       └── Entities     # Base/abstract classes for game entities
       └── Game         # Classes for game entities
       └── Utils        # Helper files


## Pending changes
- class Grid<T>: Template class for Grids. This is a necessary change to decouple Grid logic from the game Board.
- class AssetManager: Singleton class to load assets or return a reference when it's already loaded.
- Smart pointers: Replace dumb pointers for [smart pointers](https://www.learncpp.com/cpp-tutorial/15-5-stdunique_ptr/).
