# %% Bubblesort implementation in Python

# Paket importieren
import numpy as np


# %% Erstellung einer zufaelligen Sequenz

sequenz = np.random.randint(1, 50, size=(7,))

print(sequenz)

# %% Dreieckstausch

def swap(seq, ii, jj):
    tmp = seq[ii]
    seq[ii] = seq[jj]
    seq[jj] = tmp

print(sequenz)
swap(sequenz, 0, 1)
print(sequenz)

# %% Bubblesort

def bubblesort(seq):
    L = len(seq)
    print(f'Length = {L}')
    # Der unsortierte Bereich wird bei jeder Wiederholung von rechts
    # um ein Element verkleinert.
    for right in range(L-1, -1, -1):
        print(f'right is now {right}')
        # Vergleiche von links nach rechts zwei Nachbarelemente und vertausche,
        # falls die Reihenfolge inkorrekt ist.
        for idx in range(right):
            print(f'  comparing index {idx} with {idx+1}')
            if (seq[idx] > seq[idx+1]):
                print(f'    swapping')
                swap(seq, idx, idx+1)
# %%

bubblesort(sequenz)
print(sequenz)

# %%
