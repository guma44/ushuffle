from distutils.core import setup, Extension
from Cython.Build import cythonize

ext_type = Extension("py_ushuffle",
                     sources=["py_ushuffle.pyx",
                              "src/ushuffle.c"])

setup(name="py_ushuffle",
      version="1.0",
      ext_modules=cythonize([ext_type]))
