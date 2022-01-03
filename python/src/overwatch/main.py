import datetime
import matplotlib.pyplot as plt


def get_zarya_damage_tab(size):
    damage_per_shot = 8.5
    shot_fired_per_action = 1.0
    rate_of_fire = 20.0 / shot_fired_per_action
    reload_time = 1.6
    ammo_capacity = 100

    mag_emptying_time = ammo_capacity / rate_of_fire
    damage_per_second = damage_per_shot * rate_of_fire
    accumulated_damage = 0
    damage_tab = [0]
    for i in range(1, size):
        if mag_emptying_time < i < mag_emptying_time + reload_time or \
                2 * mag_emptying_time + reload_time < i < 2 * (mag_emptying_time + reload_time) or \
                3 * mag_emptying_time + 2 * reload_time < i < 3 * (mag_emptying_time + reload_time):
            accumulated_damage = 0
        else:
            accumulated_damage = accumulated_damage + damage_per_second
        damage_tab.append(accumulated_damage)
    return damage_tab


def get_hammond_damage_tab(size):
    damage_per_shot = 5.0
    shot_fired_per_action = 1.0
    rate_of_fire = 25.0 / shot_fired_per_action
    reload_time = 2.1
    ammo_capacity = 80

    mag_emptying_time = ammo_capacity / rate_of_fire
    damage_per_second = damage_per_shot * rate_of_fire
    accumulated_damage = 0
    damage_tab = [0]
    for i in range(1, size):
        if mag_emptying_time < i < mag_emptying_time + reload_time or \
                2 * mag_emptying_time + reload_time < i < 2 * (mag_emptying_time + reload_time) or \
                3 * mag_emptying_time + 2 * reload_time < i < 3 * (mag_emptying_time + reload_time):
            accumulated_damage = 0
        else:
            accumulated_damage = accumulated_damage + damage_per_second
        damage_tab.append(accumulated_damage)
    return damage_tab


def get_winston_damage_tab(size):
    damage_per_shot = 3.0
    shot_fired_per_action = 1.0
    rate_of_fire = 20.0 / shot_fired_per_action
    reload_time = 1.7
    ammo_capacity = 100

    mag_emptying_time = ammo_capacity / rate_of_fire
    damage_per_second = damage_per_shot * rate_of_fire
    accumulated_damage = 0
    damage_tab = [0]
    for i in range(1, size):
        if mag_emptying_time < i < mag_emptying_time + reload_time or \
                2 * mag_emptying_time + reload_time < i < 2 * (mag_emptying_time + reload_time) or \
                3 * mag_emptying_time + 2 * reload_time < i < 3 * (mag_emptying_time + reload_time):
            accumulated_damage = 0
        else:
            accumulated_damage = accumulated_damage + damage_per_second
        damage_tab.append(accumulated_damage)
    return damage_tab


def get_road_damage_tab(size):
    damage_per_shot = 165.0
    shot_fired_per_action = 1.0
    rate_of_fire = 1.18 / shot_fired_per_action
    reload_time = 2
    ammo_capacity = 5

    mag_emptying_time = ammo_capacity / rate_of_fire
    damage_per_second = damage_per_shot * rate_of_fire
    accumulated_damage = 0
    damage_tab = [0]
    for i in range(1, size):
        if mag_emptying_time < i < mag_emptying_time + reload_time or \
                2 * mag_emptying_time + reload_time < i < 2 * (mag_emptying_time + reload_time) or \
                3 * mag_emptying_time + 2 * reload_time < i < 3 * (mag_emptying_time + reload_time):
            accumulated_damage = 0
        else:
            accumulated_damage = accumulated_damage + damage_per_second
        damage_tab.append(accumulated_damage)
    return damage_tab


def get_rein_damage_tab(size):
    damage_per_shot = 85
    shot_fired_per_action = 1.0
    rate_of_fire = 0.96 / shot_fired_per_action

    damage_per_second = damage_per_shot * rate_of_fire
    accumulated_damage = 0
    damage_tab = [0]
    for i in range(1, size):
        accumulated_damage = accumulated_damage + damage_per_second
        damage_tab.append(accumulated_damage)
    return damage_tab


def get_dva_damage_tab(size):
    damage_per_shot = 2
    shot_fired_per_action = 1.0
    rate_of_fire = 6.67 / shot_fired_per_action

    damage_per_second = damage_per_shot * rate_of_fire
    accumulated_damage = 0
    damage_tab = [0]
    for i in range(1, size):
        accumulated_damage = accumulated_damage + damage_per_second
        damage_tab.append(accumulated_damage)
    return damage_tab


def get_sigma_damage_tab(size):
    damage_per_shot = 55
    shot_fired_per_action = 2.0
    rate_of_fire = 1.5 / shot_fired_per_action

    damage_per_second = damage_per_shot * rate_of_fire
    accumulated_damage = 0
    damage_tab = [0]

    for i in range(1, size):
        accumulated_damage = accumulated_damage + damage_per_second
        damage_tab.append(accumulated_damage)
    return damage_tab


def get_orisa_damage_tab(size):
    damage_per_shot = 11.0
    rate_of_fire = 12.0  # rounds per second
    reload_time = 2.55
    ammo_capacity = 150

    mag_emptying_time = ammo_capacity / rate_of_fire
    damage_per_second = damage_per_shot * rate_of_fire
    accumulated_damage = 0
    damage_tab = [0]
    for i in range(1, size):
        if mag_emptying_time < i < mag_emptying_time + reload_time or \
                2 * mag_emptying_time + reload_time < i < 2 * (mag_emptying_time + reload_time) or \
                3 * mag_emptying_time + 2 * reload_time < i < 3 * (mag_emptying_time + reload_time):
            accumulated_damage = 0
        else:
            accumulated_damage = accumulated_damage + damage_per_second
        damage_tab.append(accumulated_damage)
    return damage_tab


if __name__ == "__main__":
    # timeframe = 15s
    time = [datetime.datetime.now() + datetime.timedelta(seconds=i) for i in range(15)]

    # plot
    fig, ax = plt.subplots()

    ax.plot(time, get_orisa_damage_tab(len(time)), color='green', marker='.', linestyle='solid', label="Orisa")
    ax.plot(time, get_sigma_damage_tab(len(time)), color='blue', marker='.', linestyle='solid', label="Sigma")
    ax.plot(time, get_dva_damage_tab(len(time)), color='pink', marker='.', linestyle='solid', label="Dva")
    ax.plot(time, get_rein_damage_tab(len(time)), color='black', marker='.', linestyle='solid', label="Reinhart")
    ax.plot(time, get_road_damage_tab(len(time)), color='brown', marker='.', linestyle='solid', label="Roadhog")
    ax.plot(time, get_winston_damage_tab(len(time)), color='yellow', marker='.', linestyle='solid', label="Winston")
    ax.plot(time, get_hammond_damage_tab(len(time)), color='orange', marker='.', linestyle='solid', label="Hammond")
    ax.plot(time, get_zarya_damage_tab(len(time)), color='cyan', marker='.', linestyle='solid', label="Zarya")

    ax.set_xlabel('time')
    ax.set_ylabel('damage')
    ax.set_title("Cumulated damage (per reload cycle)")
    ax.legend()

    plt.grid(visible=True)
    plt.show()
