cimport ushuffle_mod

def shuffle(s, t, k):
    print ushuffle_mod.shuffle(s, t, len(s), k)

def shuffle1(s, l, k):
    print ushuffle_mod.shuffle1(s, l, k)

# cdef class Shuffle:
    # cdef *char sequence
