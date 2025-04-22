


all:	impossible_battle_boss.out


impossible_battle_boss.out:	src/impossible_battle_boss.cpp olcPixelGameEngine.h lib/PlayerClass.o
	g++ -o impossible_battle_boss.out src/impossible_battle_boss.cpp lib/PlayerClass.o -lX11 -lGL -lpthread -lpng -lstdc++fs -std=c++17


include/PlayerClass.o:	src/PlayerClass.cpp include/PlayerClass.h
	g++ -c lib/PLayerClass.cpp


clean:
	rm *.out
	rm *.o

