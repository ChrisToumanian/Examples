#! /usr/local/bin/python3

import random
import time
import sys

class Unbuffered(object):
  def __init__(self, stream):
    self.stream = stream
  def write(self, data):
    self.stream.write(data)
    self.stream.flush()
  def writelines(self, datas):
    self.stream.writelines(datas)
    self.stream.flush()
  def __getattr__(self, attr):
    return getattr(self.stream, attr)

sys.stdout = Unbuffered(sys.stdout)

coins = 1000
username = ""

def rolldice():
  dice = [0, 0, 0, 0]
  matches = 0

  time.sleep(0.4)
  
  for i in range(4):
    time.sleep(0.7)
    dice[i] = random.randint(1,6)
    print("[" + str(dice[i]) + "]", end = " ")

  time.sleep(0.7)
    
  for l in range(4):
    for i in range(4):
      if dice[l] == dice[i]:
        matches += 1

  return matches / 2 - 2

def taketurn():
  global coins

  print("\033[H\033[J")
  print("DICE ROLL!\n")
  
  matches = rolldice()
  bonus = matches * 100
  coins += bonus

  time.sleep(0.25)
  print("\n\nMatches: " + str(int(matches)))
  time.sleep(0.25)
  print("Bonus Coins: +" + str(int(bonus)))
  
def main():
  global coins
  global username
  
  print("\033[H\033[J")
  print("DICE ROLL!\n")

  username = input("What is your username? ")
  
  while True:
    time.sleep(0.5)
    print("Coin Balance: " + str(int(coins)) + "\n")
    val = input("Would you like to roll for 125 coins? (y/n) ")[0]
    
    if val == "y" and coins >= 125:
      coins -= 125
      taketurn()
    else:
      print("\nThank you for playing, " + username + "! Your score is " + str(int(coins - 1000)) + " coins!")
      with open("scores.txt", "a") as myfile:
        myfile.write(username + ": " + str(int(coins - 1000)) + "\n")
      return
      
main()
