from .character import Character
from .abilities.weapon import FusionDrive, Weapon


class Tank(Character):
    def __init__(self, name: str):
        super().__init__(name)
        self.health = 100


class Orisa(Tank):
    def __init__(self):
        super().__init__("Orisa")
        self.health = 200
        self.armor = 250
        self.shield = 0
        self.nationality = "Numbanian"
        self.age = 0.12  # years
        fd = FusionDrive()
        self.weapon: Weapon = fd
