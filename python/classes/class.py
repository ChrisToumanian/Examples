class Mob:
    health = 100
    armor = 25
    
    def heal(self, hp):
        self.health += hp
        print("Health: " + str(self.health)) # prints health
    
mob = Mob()
mob.armor += 10
mob.heal(10)

