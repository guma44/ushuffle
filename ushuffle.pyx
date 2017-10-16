cimport ushuffle_mod
from libc.stdlib cimport malloc, free

def shuffle(char *sequence, int let_size):
    """Shuffle the sequence while preserving k-let size.
    """
    cdef int length = len(s)
    cdef char *t = <char *>malloc((len(s)) * sizeof(char))
    ushuffle_mod.shuffle(sequence, t, length, let_size)
    try:
        py_t = t[:length]
    finally:
        free(t)
    return py_t

cdef class Shuffler:
    """A sequence shuffler with k-let size preservation."""
    cdef char *s
    cdef char *t
    cdef readonly int length
    cdef readonly int let_size

    def __cinit__(self, char *sequence, int length, int let_size):
        self.s = sequence
        self.let_size = let_size
        self.length = length
        self.t = <char *>malloc(self.length * sizeof(char))
        ushuffle_mod.shuffle1(self.s, self.length, self.let_size)

    def shuffle(self):
        ushuffle_mod.shuffle2(self.t)
        py_t = self.t[:self.length]
        return py_t

    property sequence:
        def __get__(self):
            return self.s[:self.length]


    def __dealloc__(self):
        free(<void *>self.t)
