#! /usr/local/bin/python3

import random
import time
import sys

rovers = []
playing = True
WIDTH = 40
HEIGHT = 20

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

class Rover():
    x = 0
    y = 0
    heading = "N"
    battery = 100

    def __init__(self, x, y):
        self.x = x
        self.y = y
    
    # moves rover forward
    def move(self):
        if (self.battery >= 10):
            if (self.heading == "N"):
                self.y += 1
            elif (self.heading == "S"):
                self.y -= 1
            elif (self.heading == "E"):
                self.x += 1
            elif (self.heading == "W"):
                self.x -= 1
            self.drainBattery(10)

    # turns rover right
    def turnRight(self):
        if (self.battery >= 5):
            if (self.heading == "N"):
                self.heading = "E"
            elif (self.heading == "S"):
                self.heading = "W"
            elif (self.heading == "E"):
                self.heading = "S"
            elif (self.heading == "W"):
                self.heading = "N"
            self.drainBattery(5)

    # turns rover left
    def turnLeft(self):
        if (self.battery >= 5):
            if (self.heading == "N"):
                self.heading = "W"
            elif (self.heading == "S"):
                self.heading = "E"
            elif (self.heading == "E"):
                self.heading = "N"
            elif (self.heading == "W"):
                self.heading = "S"
            self.drainBattery(5)

    # charge battery
    def chargeBattery(self, amount):
        self.battery += amount
        if (self.battery > 100):
            self.battery = 100

    # drain battery
    def drainBattery(self, amount):
        self.battery -= amount
        if (self.battery < 0):
            self.battery = 0
            
def createRovers(numberOfRovers):
    global rovers
    global WIDTH
    global HEIGHT

    for i in range(numberOfRovers):
        direction = random.randint(1, 4)
        rover = Rover(random.randint(0, WIDTH - 1), random.randint(0, HEIGHT - 1))
        if (direction == 1):
            rover.heading = "N"
        elif (direction == 2):
            rover.heading = "S"
        elif (direction == 3):
            rover.heading = "E"
        elif (direction == 4):
            rover.heading = "W"
        rovers.append(rover)

def worldTick():
  global rovers
  for rover in rovers:
    rover.chargeBattery(10)
        
def ifRoverExists(rover):
    global rovers
    try:
      value = int(rover)
    except ValueError:
      return False
    if (int(rover) > 0 and int(rover) < len(rovers) + 1):
      return True
    return False

def controlRover(rover, commands):
    global rovers

    for command in commands:
        if (command == "M"):
            rovers[rover - 1].move()
        elif (command == "R"):
            rovers[rover - 1].turnRight()
        elif (command == "L"):
            rovers[rover - 1].turnLeft()

def issueCommands():
    print("Which rover would you like to send commands to?")
    print("Press enter when ready. Type w to wait or q to quit.")
    command = input("Select rover: ")

    if (command == "q"):
        sys.exit()
    elif (command == "w"):
        print("You wait for 1 hour.")
        time.sleep(1)
    elif (ifRoverExists(command)):
        print("\nRover " + str(command) + " selected.")
        print("M: move forward, R: turn right, L: turn left.")
        controlRover(int(command), input("Commands: "))
    else:
        print("Rover does not exist.")

    print("")
    
    time.sleep(1)
    
def printMap():
    global rovers
    global WIDTH
    global HEIGHT

    # create empty map
    map = [[0] * HEIGHT for i in range(WIDTH)]
    for x in range(WIDTH):
        for y in range(HEIGHT):
            map[x][y] = "."

    # add rovers to map
    for i in range(len(rovers)):
      if (rovers[i].x < WIDTH and rovers[i].x > -1 and rovers[i].y < HEIGHT and rovers[i].y > -1):
        map[rovers[i].x][rovers[i].y] = str(i + 1)
            
    # print map
    for y in reversed(range(HEIGHT)):
        row = ""
        for x in range(WIDTH):
            row += " " + map[x][y]
        print(row)
    
def printStatus():
    global rovers

    printMap()
    print("")
    
    for i in range(len(rovers)):
        print("Rover " + str(i + 1) + ": " + rovers[i].heading + " " + str(rovers[i].x) + ", " + str(rovers[i].y))
        print("Battery: " + str(rovers[i].battery) + "%\n")
            
def main():
    global playing
    
    createRovers(4)
    
    while playing:
        print("\033[H\033[J")
        print("Mars Rover Technical Challenge\n")
        printStatus()
        issueCommands()
        worldTick()

main()
