all: Game.o Fight.o Blackjack.o Basketball.o FightFunc.o BlackjackFunc.o BasketballFunc.o main.o
	clang++ Game.o Fight.o Blackjack.o Basketball.o FightFunc.o BlackjackFunc.o BasketballFunc.o  main.cpp -o main
	
Basketball: Game.o Basketball.o BasketballFunc.o BasketballTest.o
	clang++ Game.o Basketball.o BasketballFunc.o BasketballTest.o -o testBasketball

Blackjack: Game.o Blackjack.o BlackjackFunc.o BlackjackTest.o
	clang++ Game.o Blackjack.o BlackjackFunc.o BlackjackTest.o -o testBlackjack
	
Fight: Game.o Fight.o FightFunc.o FightTest.o
	clang++ Game.o Fight.o FightFunc.o FightTest.o -o testFight
	
testAll: Game.o Fight.o Blackjack.o Basketball.o FightFunc.o BlackjackFunc.o BasketballFunc.o testAll.o
	clang++ Game.o Fight.o Blackjack.o Basketball.o FightFunc.o BlackjackFunc.o BasketballFunc.o testAll.cpp -o testAll
	
Game.o:
	clang++ -c Game.cpp

Fight.o:
	clang++ -c Fight.cpp

Blackjack.o:
	clang++ -c Blackjack.cpp

Basketball.o:
	clang++ -c Basketball.cpp
	
FightFunc.o:
	clang++ -c FightFunc.cpp

BlackjackFunc.o:
	clang++ -c BlackjackFunc.cpp
	
BasketballFunc.o:
	clang++ -c BasketballFunc.cpp
	
main.o:
	clang++ -c main.cpp

BasketballTest.o:
	clang++ -c BasketballTest.cpp
	
BlackjackTest.o:
	clang++ -c BlackjackTest.cpp

FightTest.o:
	clang++ -c FightTest.cpp

testAll.o:
	clang++ -c testAll.cpp
	
clean:
	rm *.o
