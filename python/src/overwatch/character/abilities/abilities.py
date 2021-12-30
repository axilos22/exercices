class Ability:
    def __init__(self, name) -> None:
        self.name = str()


class DamageAbility(Ability):
    def __init__(self, name, value) -> None:
        super().__init__(name)
        self.damage = value
        self.isProjectile = True


class FusionDriveShot(DamageAbility):
    def __init__(self) -> None:
        super().__init__("fusion_drive_shot", 11.0)
        self.speed = float(120.0)  # meter per second


class Halt(Ability):
    def __init__(self) -> None:
        super().__init__("halt")
        self.speed = float(25.0)  # meter per second
