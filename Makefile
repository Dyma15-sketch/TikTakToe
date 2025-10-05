all: TikTakToe

TikTakToe: player.o board.o rules.o game_engine.o visual.o main.o
	g++ -o TikTakToe.exe player.o board.o rules.o game_engine.o visual.o main.o

player.o:
	g++ player.cpp -o player.o -c

board.o:
	g++ board.cpp -o board.o -c

rules.o:
	g++ rules.cpp -o rules.o -c

game_engine.o:
	g++ game_engine.cpp -o game_engine.o -c

visual.o:
	g++ visual.cpp -o visual.o -c

main.o:
	g++ main.cpp -o main.o -c

clean:
	rm -f *.o *.exe