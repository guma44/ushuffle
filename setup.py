#!/usr/bin/env python2.3

from distutils.core import setup, Extension

setup (name = "ushuffle",
       version = "1.0",
       ext_modules = [
        Extension('ushuffle',
                  sources=['ushufflemodule.c',
                           'ushuffle.c'
                           ]
                  )
        ]
       ) 
