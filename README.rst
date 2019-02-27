uShuffle
========

.. image:: https://img.shields.io/pypi/v/ushuffle.svg
        :target: https://pypi.python.org/pypi/ushuffle

A Cython wrapper around uShuffle - a useful tool for shuffling biological sequences while preserving the k-let counts

This is just a bundle of files downloaded from `ushuffle <http://digital.cs.usu.edu/~mjiang/ushuffle/>`_
and wrapped in Cython for easy installation and use.

Installation
------------

.. code-block :: bash

    git clone https://github.com/guma44/ushuffle.git
    cd ushuffle
    python setup.py install [ --user ]

or

.. code-block :: bash

    pip install [--user] ushuffle

Usage
-----

The library exposes a shuffling function shuffle and a Shuffler object used to
make shuffling many times eg.:

.. code-block :: python

    from ushuffle import shuffle, Shuffler
    seq = "ababcdcdabdcabvababab"
    shuffler = Shuffler(seq, 2)
    for i in range(10):
        seqres = shuffler.shuffle()
        print("results:", seqres)
    print shuffle(seq, 2)

The library exposes also the function to set the random seed called `set_seed`.
This sets the seed globally once and subsequent call to this function will not
change the seed anymore.

References
----------

If you use this tool please refer to the original paper and authors:
Minghui Jiang, James Anderson, Joel Gillespie, and Martin Mayne. `uShuffle: a useful tool for shuffling biological sequences while preserving the k-let counts. <http://bmcbioinformatics.biomedcentral.com/articles/10.1186/1471-2105-9-192>`_ BMC Bioinformatics, 9:#192, 2008.

