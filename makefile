all: Game.o Fight.o Blackjack.o Basketball.o FightFunc.o BlackjackFunc.o BasketballFunc.o main.o
	g++ Game.o Fight.o Blackjack.o Basketball.o FightFunc.o BlackjackFunc.o BasketballFunc.o  main.cpp -o main -Wall

main: 
	clear
	g++ Basketball.cpp Game.cpp main.cpp Fight.cpp FightFunc.cpp -Wall -o run
	./run
	

# Basketball: Game.o Basketball.o BasketballFunc.o BasketballTest.o basketballInput.txt
# 	g++ Game.o Basketball.o BasketballFunc.o BasketballTest.o -o testBasketball -Wall
# 	./testBasketball < basketballInput.txt > basketballOutput.txt

basketballTestInput: Basketball.cpp Basketball.h basketballTest.cpp basketballInput.txt Game.cpp Game.h
	clear
	g++ Basketball.cpp basketballTest.cpp Game.cpp -Wall -o run
	./run < basketballInput.txt 

recordBasketballTestInput: Basketball.cpp Basketball.h basketballTest.cpp basketballInput.txt Game.cpp Game.h
	clear
	g++ Basketball.cpp basketballTest.cpp Game.cpp -Wall -o run
	./run < basketballInput.txt > basketballOutput.txt

Blackjack: Game.o Blackjack.o BlackjackFunc.o BlackjackTest.o BlackjackInput.txt
	g++ Game.o Blackjack.o BlackjackFunc.o BlackjackTest.o -o testBlackjack -Wall
	./testBlackjack 
	
FightTest1: Game.o Fight.o FightTest.o
	g++ Game.o Fight.o FightTest.o -o fightTest1 -Wall
	clear
	./fightTest1
	
FightTest2: Game.o Fight.o Blackjack.o Basketball.o FightFunc.o BlackjackFunc.o BasketballFunc.o main.o
	clear
	g++ Game.o Fight.o Blackjack.o Basketball.o FightFunc.o BlackjackFunc.o BasketballFunc.o  main.cpp -o fightTest2 -Wall
	bash testFight
	
test4: Game.o Fight.o Blackjack.o Basketball.o FightFunc.o BlackjackFunc.o BasketballFunc.o testAll.o
	g++ Game.o Fight.o Blackjack.o Basketball.o FightFunc.o BlackjackFunc.o BasketballFunc.o testAll.cpp -o testAll -Wall
	
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

BlackjackFunc.o:
	g++ -c BlackjackFunc.cpp
	
# BasketballFunc.o:
# 	g++ -c BasketballFunc.cpp
	
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
