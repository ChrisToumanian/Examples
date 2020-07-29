#! /usr/local/bin/python

import sys
import json

class Player:
  name = ""
  uuid = ""
  stats = []

players = []
statnames = ["kills", "custom", "mined", "crafted", "used"]

# load players
def LoadPlayers():
  # load players from user cache
  with open("./Minecraft/survival/usercache.json") as user_file:
    data = json.load(user_file)
    for i in data:
      player = Player()
      player.name = i["name"]
      player.uuid = i["uuid"]
      players.append(player)

  # load stats for each player
  for player in players:
    path = "./Minecraft/survival/world/stats/" + player.uuid + ".json"
    with open(path) as stat_file:
      statdata = json.load(stat_file)["stats"]
      player.stats = statdata

# print leaderboard
def PrintLeaderboard():
  print("Mob Kills:")
  for player in players:
    try:
      print player.name, ": ", player.stats["minecraft:custom"]["minecraft:mob_kills"]
    except:
      print "0"

# print all player's stats
def PrintAllStats():
  for player in players:
    for statname in statnames:
      print("<font size='4'>" + player.name + "</font>")
      print("<br><b>" + statname + "</b>")
      try:
        for key, value in player.stats["minecraft:" + statname].iteritems():
          print key.replace("minecraft:", ""), ": ", value
      except:
        print("0")

    # html white line divider
    print("<br>")
    print("<hr size='1' width='500px' align='left' color='white'>")

# main
def main():
  LoadPlayers()

  # command line arguments
  if sys.argv[1] == "leaderboard":
    PrintLeaderboard()
  elif sys.argv[1] == "allstats":
    PrintAllStats()

main()
