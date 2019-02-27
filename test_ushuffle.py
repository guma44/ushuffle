#!/usr/bin/env python
# -*- coding: utf-8 -*-

"""Tests for `ushuffle` package."""


import unittest

from ushuffle import Shuffler


class TestUshuffle(unittest.TestCase):
    """Tests for `ushuffle` package."""

    def setUp(self):
        """Set up test fixtures, if any."""
        self.seq = b"ababcdcdabdcabvababab"
        self.shuffler = Shuffler(self.seq, 2)

    def test_sequence(self):
        """Test sequence."""
        self.assertEqual(self.shuffler.sequence, self.seq)

    def test_let_size(self):
        """Test let size."""
        self.assertEqual(self.shuffler.let_size, 2)

    def test_length(self):
        """Test length."""
        self.assertEqual(self.shuffler.length, len(self.seq))

    def test_print(self):
        """Just test the printing it is correct."""
        for i in range(10):
            seqres = self.shuffler.shuffle()
            print("original:",
                  self.shuffler.sequence,
                  "results:",
                  seqres,
                  "is the same?",
                  self.shuffler.sequence == seqres)


if __name__ == '__main__':
    unittest.main()
