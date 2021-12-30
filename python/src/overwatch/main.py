import matplotlib.pyplot as plt
import numpy as np

from character.tank import Orisa

if __name__ == "__main__":
    character = Orisa()
    reload_time = 2.55
    mag_emptying_time = 12.5
    max_damage_in_one_mag = 11 * 150

    # timeframe = 20s
    time = np.linspace(0, 15, 15)
    print(time)
    acc_damage = [0]
    for i in range(1, len(time)):
        if mag_emptying_time < time[i] < mag_emptying_time + reload_time:
            acc_damage.append(0)
        else:
            acc_damage.append(acc_damage[i - 1] + character.weapon.damage_per_second())

    # plot
    fig, ax = plt.subplots()

    ax.plot(time, acc_damage, linewidth=2.0)

    plt.grid(visible=True)
    plt.show()
