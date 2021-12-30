from .abilities import Ability, DamageAbility, FusionDriveShot, Halt


class Weapon:
    def __init__(self, name: str, damage_ability: DamageAbility, alt_ability: Ability) -> None:
        self.name = str(name)
        self.damage_ability = damage_ability
        self.alt_ability = alt_ability
        self.spead_angle = float(0)
        self.capacity = float(0)

    def damage_per_second(self):
        pass


class FusionDrive(Weapon):
    def __init__(self) -> None:
        super().__init__("fusion_drive", FusionDriveShot(), Halt())
        self.capacity = 150
        self.damage_ability_rate_of_fire = 12  # per second
        self.reload_time = 2.55  # second

    def damage_per_second(self):
        one_shot_damage = self.damage_ability.damage
        return one_shot_damage * self.damage_ability_rate_of_fire
