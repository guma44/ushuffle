from distutils.core import setup, Extension
from Cython.Build import cythonize

ext_type = Extension("ushuffle",
                     sources=["ushuffle.pyx",
                              "src/ushuffle.c"])

setup(name="ushuffle",
      version="1.0",
      ext_modules=cythonize([ext_type]))
