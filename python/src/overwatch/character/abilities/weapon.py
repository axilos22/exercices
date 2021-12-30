from .abilities import Ability, DamageAbility, FusionDriveShot, Halt


class Weapon:
    def __init__(self, name: str, damage_ability: DamageAbility, alt_ability: Ability) -> None:
        self.name = str(name)
        self.damage_ability = damage_ability
        self.alt_ability = alt_ability
        self.spead_angle = float(.0)


class FusionDrive(Weapon):
    def __init__(self) -> None:
        super().__init__("fusion_drive", FusionDriveShot(), Halt())
