all: Game.o Fight.o Blackjack.o Basketball.o FightFunc.o BlackjackFunc.o BasketballFunc.o main.o
	clang++ Game.o Fight.o Blackjack.o Basketball.o FightFunc.o BlackjackFunc.o BasketballFunc.o  main.cpp -o main
	
Basketball: Game.o Basketball.o BasketballFunc.o test1.o
	clang++ Game.o Basketball.o BasketballFunc.o test1.o -o testBasketball

Blackjack: Game.o Blackjack.o BlackjackFunc.o test2.o
	clang++ Game.o Blackjack.o BlackjackFunc.o test2.o -o testBlackjack
	
Fight: Game.o Fight.o FightFunc.o test3.o
	clang++ Game.o Fight.o FightFunc.o test3.o -o testFight
	
test4: Game.o Fight.o Blackjack.o Basketball.o FightFunc.o BlackjackFunc.o BasketballFunc.o test4.o
	clang++ Game.o Fight.o Blackjack.o Basketball.o FightFunc.o BlackjackFunc.o BasketballFunc.o test4.cpp -o test4
	
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

test1.o:
	clang++ -c test1.cpp
	
test2.o:
	clang++ -c test2.cpp

test3.o:
	clang++ -c test3.cpp

test4.o:
	clang++ -c test4.cpp
	
clean:
	rm *.o
