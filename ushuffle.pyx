cimport ushuffle

def shuffle(s, t, k):
    ushuffle.shuffle(s, t, len(s), k)

def shuffle1(s, l, k):
    ushuffle.shuffle1(s, l, k)

# cdef class Shuffle:
    # cdef *char sequence
