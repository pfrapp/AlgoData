# %% Comparison of heapsort against bubblesort
#
# Copy over the already existing Python implemenetation.
# Remove debug statements.

# %% Packages

import numpy as np
from time import time

# %% Heapsort
class Heap:

    def __init__(self, seq):
        self.seq = seq
        self.length = len(self.seq)
    
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
            else:
                # Nur das linke Kind existiert ueberhaupt
                value_left = self.seq[left_idx]
                value_max = value_left
                idx_max = left_idx
            # Wenn die Kinderwerte kleiner gleich sind als der Index-Wert koennen wir stoppen
            if value_max <= self.seq[idx]:
                return
            self.swap(idx_max, idx)
            idx = idx_max
            

    def heapify(self):
        ''' Heapify '''
        for sub_heap_idx in range(self.getParentIndex(self.length), -1, -1):
            self.downheap(sub_heap_idx)
            # self.display()
    
    def sort(self):
        self.heapify()
        original_length = self.length
        for idx in range(original_length-1, -1, -1):
            self.swap(0, idx)
            self.length -= 1
            self.downheap(0)

# %% Bubblesort

def swap(seq, ii, jj):
    tmp = seq[ii]
    seq[ii] = seq[jj]
    seq[jj] = tmp

def bubblesort(seq):
    L = len(seq)
    # Der unsortierte Bereich wird bei jeder Wiederholung von rechts
    # um ein Element verkleinert.
    for right in range(L-1, -1, -1):
        # Vergleiche von links nach rechts zwei Nachbarelemente und vertausche,
        # falls die Reihenfolge inkorrekt ist.
        for idx in range(right):
            if (seq[idx] > seq[idx+1]):
                swap(seq, idx, idx+1)

# %% Test des Sortierens

L = 5000

seq = np.random.randint(-5500, 5500, size=(L,))
# seq = np.flip(np.arange(L))
# print(seq)
t0 = time()
heap = Heap(seq)
heap.sort()
t1 = time()
# print(heap.seq)
dt = t1 - t0
print(f'Heapsort took {dt*1000} ms for sequence length {L}')

seq = np.random.randint(-5500, 5500, size=(L,))
# seq = np.flip(np.arange(L))
# print(seq)
t0 = time()
bubblesort(seq)
t1 = time()
# print(heap.seq)
dt = t1 - t0
print(f'Bubblesort took {dt*1000} ms for sequence length {L}')



# %%
