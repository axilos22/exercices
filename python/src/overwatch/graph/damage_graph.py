import matplotlib.pyplot as plt
import numpy as np

import ..character.tank

character_pri

plt.style.use('_mpl-gallery')

# make data
time = np.linspace(0, 10, 100)
acc_damage = []
acc_damage[0] = 0
for i in range(1, 100):
    acc_damage[i] = acc_damage[i - 1] + character.weapon.main_fire.damage

# plot
fig, ax = plt.subplots()

ax.plot(time, acc_damage, linewidth=2.0)

plt.show()
