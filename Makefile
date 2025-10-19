all: TikTakToe

TikTakToe: player.o board.o rules.o game_engine.o visual.o main.o
	g++ -o TikTakToe.exe player.o board.o rules.o game_engine.o visual.o main.o

INCLUDES = -Iinclude

player.o: src/player.cpp
	g++ $(INCLUDES) src/player.cpp -o player.o -c



board.o: src/board.cpp
	g++ $(INCLUDES) src/board.cpp -o board.o -c

rules.o: src/rules.cpp
	g++ $(INCLUDES) src/rules.cpp -o rules.o -c

game_engine.o: src/game_engine.cpp
	g++ $(INCLUDES) src/game_engine.cpp -o game_engine.o -c

visual.o: src/visual.cpp
	g++ $(INCLUDES) src/visual.cpp -o visual.o -c

main.o: src/main.cpp
	g++ $(INCLUDES) src/main.cpp -o main.o -c

	

clean:
	rm -f *.o *.exe