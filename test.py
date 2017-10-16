from ushuffle import Shuffler

seq = "ababcdcdabdcabvababab"

shuf = Shuffler(seq, len(seq), 2)
for i in range(10):
    seqres = shuf.shuffle()
    print "original:", shuf.sequence, "results:", seqres, shuf.sequence == seqres
