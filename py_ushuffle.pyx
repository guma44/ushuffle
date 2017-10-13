cimport ushuffle_mod
from libc.stdlib cimport malloc, free

def shuffle(char *s, int k):
    cdef int length = len(s)
    cdef char *t = <char *>malloc((len(s)) * sizeof(char))
    ushuffle_mod.shuffle(s, t, length, k)
    try:
        py_t = t[:length]
    finally:
        free(t)
    return py_t

cdef class Shuffler:
    cdef char *s
    cdef char *t
    cdef int length
    cdef int k

    def __cinit__(self, char *s, int l, int k):
        self.s = s
        self.k = k
        self.length = l
        self.t = <char *>malloc(self.length * sizeof(char))
        ushuffle_mod.shuffle1(self.s, self.length, self.k)

    def shuffle(self):
        # print "data: ", self.s, self.length, self.k
        # print "before:", self.t
        ushuffle_mod.shuffle2(self.t)
        # print "after:", self.t
        py_t = self.t[:self.length]
        return py_t

    def __dealloc__(self):
        free(<void *>self.t)
