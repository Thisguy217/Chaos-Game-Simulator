# Chaos-Game-Simulator
A simple simulator for building a Sierpinski Triangle

> [!WARNING]
> I am not a great C dev, I just like coding. The code may be broken, and I have no idea how to fix. Please feel free to give suggestions.

## Build from Source

External Dependencies:
- [ffmpeg](https://ffmpeg.org/) executable available in `PATH` environment variable. It is called after the simulation is completed and all the pictures are taken during the building. That way a video is made.
- [raylib](https://www.raylib.com/index.html) a simple game library that actually handles visualizing the game.

It is built with `GCC` and was designed using Ubuntu, I have not tested if the same system will work with Windows or MacOS.

## The Game Rules
The basic idea behind the game is that you have 3 points. A fourth point is placed at a random location in inside the 3 others, this one will be the "player." For a turn, the player randomly selects one of the 3 points to move halfway towards it. This repeats until either the user gets bored or the maximum number of iterations is complete. Each turn, the player will place a stamp for the current location and add it to the image. The result is an image known as Sierpinski's Triangle. (I think it looks best after about 300 iterations, but you can be the judge of that.)
