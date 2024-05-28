# COP290_Game

## How to Compile and Run the Code

### Server
1. Compile the server:
   ```sh
   make -f makeS
   ```
2. Run the server:
   ```sh
   ./playS 51717
   ```
3. Press `Enter`.

### Client
1. Compile the client:
   ```sh
   make -f makeC
   ```
2. Run the client:
   ```sh
   ./playC localhost 51717
   ```
3. Press `Enter` to start the game.

## References Used for Codes

- [SDL Tutorials by Lazy Foo](https://lazyfoo.net/tutorials/SDL/index.php)
- [Google Images](https://www.google.co.in/imghp?hl=en&ogbl)

## Instructions for Running the Game

1. **Start the Game**: 
   - First, compile and run the server.
   - Then, compile and run the client.

2. **Gameplay**:
   - Move the character to the tasks generated at random locations.
   - Use the Yulu bike to do tasks efficiently by going to the bike stand and pressing `SPACE` to grab it.
   - Go to images generated on the map and press `t` to do the corresponding task.
   - Once a task is completed, the image will change to indicate completion.
   - Complete all 12 tasks generated randomly on the entire map.
   - The player who completes all the tasks first will be the winner.
   - Learn about various buildings by going to them and pressing `ENTER`.

Enjoy the game!