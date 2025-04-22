


all:	impossible_battle_boss.out


impossible_battle_boss.out:	impossible_battle_boss.cpp olcPixelGameEngine.h
	g++ -o impossible_battle_boss.out impossible_battle_boss.cpp -lX11 -lGL -lpthread -lpng -lstdc++fs -std=c++17


clean:
	rm *.out
	rm *.o

