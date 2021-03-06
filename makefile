all: Game.o Fight.o Blackjack.o Basketball.o FightFunc.o main.o
	g++ Game.o Fight.o Blackjack.o Basketball.o FightFunc.o  main.o -o main -Wall

mainTest1: Game.o Fight.o Blackjack.o Basketball.o FightFunc.o main.o mainInput1.txt
	#Boundary tests for all games and all options
	clear
	g++ Game.o Fight.o Blackjack.o Basketball.o FightFunc.o main.o -o main -Wall
	./main < mainInput1.txt
	./main < mainInput1.txt > mainOutput1.txt
	
mainTest2: Game.o Fight.o Blackjack.o Basketball.o FightFunc.o main.o mainInput2.txt
	#Tests prize system for the game using two games
	clear
	g++ Game.o Fight.o Blackjack.o Basketball.o FightFunc.o main.o -o main -Wall
	./main < mainInput2.txt
	./main < mainInput2.txt > mainOutput2.txt
	
basketballTestInput: Basketball.o basketballTest.o basketballInput.txt Game.o
	clear
	g++ Basketball.o basketballTest.o Game.o -Wall -o run
	./run < basketballInput.txt
	./run < basketballInput.txt > basketballOutput.txt

BlackjackTest: Game.o Blackjack.o BlackjackTest.o BlackjackInput.txt BlackjackOutput.txt
	clear
	g++ Game.o Blackjack.o BlackjackTest.o -o testBlackjack -Wall
	./testBlackjack < BlackjackInput.txt | diff - BlackjackOutput.txt

FightTest1: Game.o Fight.o FightTest.o
	#expected and actual outputs of class methods
	clang++ Game.o Fight.o FightTest.o -o fightTest1 -Wall
	clear
	./fightTest1

FightTest2: Game.o Fight.o Blackjack.o Basketball.o FightFunc.o main.o testFight fightInput1.txt fightInput2.txt
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
