cdef extern from "src/ushuffle.h":
    void shuffle(const char *s, char *t, int l, int k)
    void shuffle1(const char *s, int l, int k)
    void shuffle2(char *t)

    ctypedef long (*randfunc_t)()
    void set_randfunc(randfunc_t randfunc)

