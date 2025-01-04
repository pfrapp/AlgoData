# %% Beispiel aus der Vorlesung vom 04. Januar 2025

import numpy as np

# %% Multiplikationsmethode

A = 0.6
m = 27

x = np.array([13.0, 1.0, 139, 23, 57, 22, 45])
h = np.floor(m*(A*x%1)).astype('int')

print('Schluessel')
print(x)
print('Hashes')
print(h)

# %% Nutzung von Hashes 'under the hood'

# Tabelle
tab = dict()
# tab[Schluessel] = Wert
tab['heute'] = '04. Januar'
tab['themen'] = ['Sortieren', 'Suchen']
tab['temperatur'] = -4
tab[11.45] = 'Ende VL'

print(tab)

print('Alle Elemente')
print(list(tab.items()))
print('Alle Schluessel')
print(list(tab.keys()))
print('Alle Werte')
print(list(tab.values()))

tab[80000] = 32
print(tab)

# %%

for idx, item in enumerate(tab.items()):
    print(f'Item no. {idx}')
    print(item)

# %%
