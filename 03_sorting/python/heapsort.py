# %% Heapsort in Python
import numpy as np


# %% Erstellung einer zufaelligen Sequenz

sequenz = np.random.randint(1, 50, size=(10,))

print(sequenz)

# %% Aufbau der Datenstruktur

# Wir transformieren die Sequenz in einen Heap, d.h. in einen binaeren Baum,
# auf dem die Heap-Bedingung gilt.
# Der binaere Baum wird intern als ein Array dargestellt, d.h.
# wir koennen die bisherige sequentielle Struktur beibehalten.

class Heap:

    def __init__(self, seq):
        self.seq = seq
        print(f"Heap erstellt fuer Sequenz {self.seq}")
    
    def nodes(self):
        return len(self.seq)
    
    def height(self):
        return np.floor(np.log2(self.nodes()))+1
    
    def display(self):
        # Breitentraversierung notwendig zur graphischen Darstellung
        old_level = 0
        output_string = ''
        for idx, value in enumerate(self.seq):
            level = np.floor(np.log2(idx+1))
            if (level > old_level):
                output_string += '\n\n'
                # print(f'new level for idx {idx}, value {value} is {level}')
            old_level = level
            padding = int(2**(self.height() + 1 - level)) - 2
            output_string += ''.join([' ' for i in range(padding)]) + f'{idx}:{value}' + ''.join([' ' for i in range(padding)])
        print(output_string)

    def heapify(self, start):
        ''' Heapify ab Index start '''
        print(f'heapify from {start}')
    
    def sort(self):
        for start_idx in range(int(self.nodes() / 2 - 1), 0, -1):
            self.heapify(start_idx)





heap = Heap(sequenz)
print(f'Heap has {heap.nodes()} nodes and height {heap.height()}')
heap.display()
heap.sort()



# %% 
