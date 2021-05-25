all: Game.o Fight.o Blackjack.o Basketball.o FightFunc.o main.o
	g++ Game.o Fight.o Blackjack.o Basketball.o FightFunc.o  main.cpp -o main -Wall

main:
	clear
	g++ Basketball.cpp Game.cpp main.cpp Fight.cpp FightFunc.cpp -Wall -o run
	./run

basketballTestInput: Basketball.cpp Basketball.h basketballTest.cpp basketballInput.txt Game.cpp Game.h
	clear
	g++ Basketball.cpp basketballTest.cpp Game.cpp -Wall -o run
	./run < basketballInput.txt

recordBasketballTestInput: Basketball.cpp Basketball.h basketballTest.cpp basketballInput.txt Game.cpp Game.h
	clear
	g++ Basketball.cpp basketballTest.cpp Game.cpp -Wall -o run
	./run < basketballInput.txt > basketballOutput.txt

BlackjackTest: Game.o Blackjack.o BlackjackTest.o BlackjackInput.txt BlackjackOutput.txt
	clear
	g++ Game.o Blackjack.o BlackjackTest.o -o testBlackjack -Wall
	./testBlackjack < BlackjackInput.txt | diff - BlackjackOutput.txt

FightTest1: Game.o Fight.o FightTest.o
	clang++ Game.o Fight.o FightTest.o -o fightTest1 -Wall
	clear
	./fightTest1

FightTest2: Game.o Fight.o Blackjack.o Basketball.o FightFunc.o BlackjackFunc.o BasketballFunc.o main.o
	clear
	clang++ Game.o Fight.o Blackjack.o Basketball.o FightFunc.o BlackjackFunc.o BasketballFunc.o  main.cpp -o fightTest2 -Wall
	bash testFight

Game.o:
	g++ -c Game.cpp

Fight.o:
	g++ -c Fight.cpp

Blackjack.o:
	g++ -c Blackjack.cpp

Basketball.o:
	g++ -c Basketball.cpp

FightFunc.o:
	g++ -c FightFunc.cpp

main.o:
	g++ -c main.cpp

BasketballTest.o:
	g++ -c BasketballTest.cpp

BlackjackTest.o:
	g++ -c BlackjackTest.cpp

FightTest.o:
	g++ -c FightTest.cpp

testAll.o:
	g++ -c testAll.cpp

clean:
	rm *.o
