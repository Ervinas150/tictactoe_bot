# -*- MakeFile -*-

tictactoe: main/main.o ai/ai.o game/game.o utils/utils.o
	gcc main/main.o ai/ai.o game/game.o utils/utils.o -o tictactoe

main.o: main/main.c
	gcc -c main/main.c

ai.o: ai/ai.c ai/ai.h
	gcc -c ai/ai.c

game.o: game/game.c game/game.h
	gcc -c game/game.c

utils.o: utils/utils.c. utils/utils.h
	gcc -c utils/utils.c

clean:
	rm *.o tictactoe