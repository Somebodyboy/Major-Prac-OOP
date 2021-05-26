all: Game.o Fight.o Blackjack.o Basketball.o FightFunc.o main.o
	g++ Game.o Fight.o Blackjack.o Basketball.o FightFunc.o  main.o -o main -Wall
	
basketballTestInput: Basketball.o basketballTest.o basketballInput.txt Game.o
	clear
	g++ Basketball.o basketballTest.o Game.o -Wall -o run
	./run < basketballInput.txt

recordBasketballTestInput: Basketball.o basketballTest.o basketballInput.txt Game.o
	clear
	g++ Basketball.o basketballTest.o Game.o -Wall -o run
	./run < basketballInput.txt > basketballOutput.txt

BlackjackTest: Game.o Blackjack.o BlackjackTest.o BlackjackInput.txt BlackjackOutput.txt
	clear
	g++ Game.o Blackjack.o BlackjackTest.o -o testBlackjack -Wall
	./testBlackjack < BlackjackInput.txt | diff - BlackjackOutput.txt

FightTest1: Game.o Fight.o FightTest.o
	clang++ Game.o Fight.o FightTest.o -o fightTest1 -Wall
	clear
	./fightTest1

FightTest2: Game.o Fight.o Blackjack.o Basketball.o FightFunc.o main.o testFight fightInput1.txt
	clear
	clang++ Game.o Fight.o Blackjack.o Basketball.o FightFunc.o main.o -o fightTest2 -Wall
	bash testFight

Game.o: Game.cpp Game.h
	g++ -c Game.cpp

Fight.o: Fight.cpp Fight.h
	g++ -c Fight.cpp

Blackjack.o: Blackjack.cpp Blackjack.h
	g++ -c Blackjack.cpp

Basketball.o: Basketball.cpp Basketball.h
	g++ -c Basketball.cpp

FightFunc.o: FightFunc.cpp
	g++ -c FightFunc.cpp

main.o: main.cpp
	g++ -c main.cpp

basketballTest.o: basketballTest.cpp
	g++ -c basketballTest.cpp

BlackjackTest.o: BlackjackTest.cpp
	g++ -c BlackjackTest.cpp

FightTest.o: FightTest.cpp
	g++ -c FightTest.cpp

clean:
	rm *.o
