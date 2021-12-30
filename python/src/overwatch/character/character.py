from enum import Enum


class Specialization(Enum):
    NONE = 0
    TANK = 1
    DAMAGE = 2
    SUPPORT = 3


class Character:
    def __init__(self, name: str):
        self.name = str(name)
        self.health = int(1)
        self.armor = int(0)
        self.shield = int(0)
        self.nationality = str("None")
        self.age = float(.0)
