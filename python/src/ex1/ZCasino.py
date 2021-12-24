import random
import math
import os
from enum import Enum

class Color(Enum):
    UNKNOWN = 0
    GREEN = 1
    RED = 2
    BLACK = 3

class Player:
    def __init__(self, name, money):
        self.name = str(name)
        self.money = int(money)

    def addMoney(self, amount):
        print("Adding ${} from {}".format(amount, self.name))
        self.money+= amount

    def removeMoney(self, amount):
        print("Taking ${} from {}".format(amount, self.name))
        self.money-= amount

    def canStillPlay(self):
        canPlay = True
        if self.money <= 0:
            canPlay = False
        return canPlay


class Roulette:
    def __init__(self, max_number):
        self.max_number = max_number
        self.rand = random.seed(None)
    
    def spin(self):
        return random.randrange(self.max_number)

    def getColor(self, number):
        color = Color.UNKNOWN
        if self.isGreen(number):
            color = Color.GREEN
        if self.isBlack(number):
            color = Color.BLACK
        if self.isRed(number):
            color = Color.RED
        return color

    def isBlack(self, number):
        is_black = False
        if number != 0:
            is_black = (number % 2 == 0)
        return is_black

    def isRed(self, number):
        is_red = False
        if number != 0:
            is_red = (number % 2 == 1)
        return is_red

    def isGreen(self, number):
        is_green = False
        if number == 0:
            is_green = True
        return is_green


class Bet:
    def __init__(self, number, amount):
        self.number = int(number)
        self.amount = int(amount)
        self.isBetOk = True

    def evaluateValidity(self, roulette, player):
        if self.number > roulette.max_number :
            print("Invalid bet ! Roulette number too high !")
            self.isBetOk = False
        if self.amount > player.money :
            print("Invalid bet ! Player {} has not enough money !".format(player.name))
            self.isBetOk = False
        if self.amount < 0 :
            print("Invalid bet ! Player {} can't bet negative values !".format(player.name))
            self.isBetOk = False
        return self.isBetOk


class Game:
    def __init__(self):
        self.roundRank = 1
        self.roulette = Roulette(49)
        self.initial_player_money = int(500)
        self.keepPlaying = bool(True)

    def askPlayerName(self):
        return input("[GAME] What is your name ?")

    def askPlayerBet(self):
        output_text = "[GAME] On what Number would you like to bet ? [{}-{}]".format(0, self.roulette.max_number)
        return input(output_text)

    def askPlayerAmount(self, player):
        output_text = "[GAME] How much would you like to bet ? [{}-{}]".format(1, player.money)
        return input(output_text)

    def displayBetMessage(self, bet, player):
        output_text = "[GAME] {} has bet ${} on the number {} !".format(player.name, bet.amount, bet.number)
        print(output_text)

    def isBetWinning(self, bet, number_pulled):
        isWinning = False
        if bet.number == number_pulled:
            isWinning = True
        return isWinning

    def askPlayAgain(self):
        output_text = "[GAME] Play another round ? [y/n]"
        return input(output_text)

    def betBuilding(self, roulette, player):
        number = self.askPlayerBet()
        amount = self.askPlayerAmount(player)
        bet = Bet(number, amount)
        return bet

    def showGameStatus(self, player):
        output_text = "GAME : Roulette -- Round {}\nPlayer: {}\nPlayer wallet:{}\nCan still play ? {}".format(
            self.roundRank,
            player.name,
            player.money,
            player.canStillPlay())
        print(output_text)

    def start(self):
        pName = self.askPlayerName()
        p1 = Player(pName, self.initial_player_money)

        while(self.keepPlaying) :            
            bet_valid = False
            while not bet_valid:
                bet = self.betBuilding(self.roulette, p1)
                bet_valid = bet.evaluateValidity(self.roulette, p1)
                if not bet_valid:
                    print("[GAME] Your bet is invalid. Please do it again.")
            self.displayBetMessage(bet, p1)
               

            p1.removeMoney(bet.amount)

            print("[GAME] Game is set ! Rolling...")
            number_pulled = self.roulette.spin()
            print("[GAME] Pulled number : {}...".format(number_pulled))
            isWon = self.isBetWinning(bet, number_pulled)
            isSameColor = (self.roulette.getColor(number_pulled)) == (self.roulette.getColor(bet.number))

            if isWon:
                print("[GAME] {} wins ! Here is 3 times your bet".format(p1.name))
                p1.addMoney(bet.amount * 3)
            elif isSameColor:
                print("[GAME] {} has same color ! Here is half your bet".format(p1.name))
                p1.addMoney( math.ceil(bet.amount * .5) )
            else:
                print("[GAME] Sorry {}. Better luck next time !".format(p1.name))

            self.showGameStatus(p1)
            self.roundRank+=1
            print("-----------------------------------------------------------")
            if self.askPlayAgain() == "y":
                if p1.canStillPlay():
                    print("[GAME] Oh ! We have a winner ! Let's start round {}".format(self.roundRank))
                    self.keepPlaying = True
                else:
                    print("[GAME] Sorry {} you're not reaching minimal criteria for playing".format(p1.name))
                    os._exit(1)
            else:
                self.keepPlaying = False
                print("[GAME] Thank you for playing, we hope so see you soon !")

if __name__ == "__main__":
    game = Game()
    game.start()
