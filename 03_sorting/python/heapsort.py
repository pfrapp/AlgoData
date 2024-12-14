# %% Heapsort in Python

# Paket importieren
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
        self.length = len(self.seq)
        print(f"Heap erstellt fuer Sequenz {self.seq}, Laenge {self.length}")
    
    def nodes(self):
        return self.length
    
    def height(self):
        return np.floor(np.log2(self.nodes()))+1
    
    def getLevelOfNodeIdx(self, idx):
        ''' Get the level of the node with the given index idx'''
        return np.floor(np.log2(idx+1))
    
    def getLeftChildIndex(self, idx):
        return 2*idx + 1
    
    def getRightChildIndex(self, idx):
        return 2*idx + 2

    def getParentIndex(self, idx):
        return int((idx-1)/2)
    
    def isLeaf(self, idx):
        if (self.getLeftChildIndex(idx) >= self.length):
            return True
        else:
            return False
    
    # Hilfsfunktion zur graphischen Darstellung des Heaps.
    # Hat mit dem eigentlichen Sortieralgorithmus nichts zu tun.
    def display(self):
        # Breitentraversierung notwendig zur graphischen Darstellung
        old_level = 0
        output_string = ''
        for idx, value in enumerate(self.seq):
            level = self.getLevelOfNodeIdx(idx)
            if (level > old_level):
                output_string += '\n\n'
                # print(f'new level for idx {idx}, value {value} is {level}')
            old_level = level
            padding = int(2**(self.height() + 1 - level)) - 2
            output_string += ''.join([' ' for i in range(padding)]) + f'{idx}:{value}' + ''.join([' ' for i in range(padding)])
        print(output_string)

    def swap(self, ii, jj):
        tmp = self.seq[ii]
        self.seq[ii] = self.seq[jj]
        self.seq[jj] = tmp
    
    def downheap(self, idx):
        while not self.isLeaf(idx):
            left_idx, right_idx = self.getLeftChildIndex(idx), self.getRightChildIndex(idx)
            if right_idx < self.length:
                # Das rechte Kind existiert, damit existieren beide Kinder
                value_left, value_right = self.seq[left_idx], self.seq[right_idx]
                if value_left > value_right:
                    value_max = value_left
                    idx_max = left_idx
                else:
                    value_max = value_right
                    idx_max = right_idx
                print(f'both children exist, the max value is {value_max}')
            else:
                # Nur das linke Kind existiert ueberhaupt
                value_left = self.seq[left_idx]
                value_max = value_left
                idx_max = left_idx
                print(f'only left child exists, the max value is {value_max}')
            # Wenn die Kinderwerte kleiner gleich sind als der Index-Wert koennen wir stoppen
            if value_max <= self.seq[idx]:
                print('children are already small')
                return
            self.swap(idx_max, idx)
            idx = idx_max
            

    def heapify(self):
        ''' Heapify '''
        for sub_heap_idx in range(self.getParentIndex(self.length), -1, -1):
            print(f'Downheaping from {sub_heap_idx}')
            self.downheap(sub_heap_idx)
            # self.display()
    
    def sort(self):
        self.heapify()
        original_length = self.length
        for idx in range(original_length-1, -1, -1):
            self.swap(0, idx)
            print(f'last element is now {self.seq[self.length-1]}')
            self.length -= 1
            self.downheap(0)



heap = Heap(sequenz)
print(f'Heap has {heap.nodes()} nodes and height {heap.height()}')
heap.display()
heap.sort()
print('sorted output')
print(heap.seq)


# %% 
