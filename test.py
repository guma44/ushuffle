from py_ushuffle import Shuffler

seq = "ababcdcdabdcabvababab"

shuf = Shuffler(seq, len(seq), 2)
for i in range(10):
    s = shuf.shuffle()
    print "results:", s
