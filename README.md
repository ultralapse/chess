## Chess.sh
Chess Server that operates over SSH, using BubbleTea and Wish. See https://code.rocket9labs.com/tslocum/netris for an example.
The project is a work in progress. Right now the main focus is to get the core game mechanics to work.

## Status
The core mechanics of the game have not completed. Namely these features are not present.
1. En Passant
2. Castling
3. Endgame (Check, Checkmate, and Stalemate)

Like most other Chess implementations, these are fully supported:
1. Loading/Saving Games
2. Piece movement
3. Piece capturing

## Contributing
This project places a high emphasis on code quality. The C++ code has no linting errors and tries to conform with the Google C++ Style Guidelines.
Pull requests are encouraged, but not required to follow the aforementioned style.

On UNIX-like operating systems you can build the program by running `./build.sh`.
On Windows, you can run `cmake -B build -G Ninja`, then cd build, then `ninja`.
