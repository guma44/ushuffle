import os
from setuptools import setup, find_packages, Extension

try:
    from Cython.Build import cythonize
    ext_type = Extension("ushuffle",
                         sources=["ushuffle.pyx",
                                  "src/ushuffle.c"])
    extensions = cythonize([ext_type])
    print("Cython installed. Building sources using Cython.")
except ImportError:
    print("No Cython installed. Building from pre-compiled sources.")
    ext_type = Extension("ushuffle",
                         sources=["ushuffle_cython.c",
                                  "src/ushuffle.c"])
    extensions = [ext_type]



with open('README.rst') as readme_file:
    readme = readme_file.read()

setup(name="ushuffle",
    version="1.1.0",
    description="A Cython wrapper over uShuffle - a useful tool for shuffling biological sequences while preserving the k-let counts.",
    long_description=readme,
    author="Rafal Gumienny",
    author_email='guma44@gmail.com',
    url='https://github.com/guma44/ushuffle',
    packages=find_packages(include=['ushuffle']),
    include_package_data=True,
    install_requires=list(),
    license="BSD license",
    zip_safe=False,
    keywords='ushuffle',
    classifiers=[
        'Development Status :: 4 - Beta',
        'Intended Audience :: Science/Research',
        'License :: OSI Approved :: BSD License',
        'Natural Language :: English',
        "Programming Language :: Python :: 2",
        'Programming Language :: Python :: 2.6',
        'Programming Language :: Python :: 2.7',
        'Programming Language :: Python :: 3',
        'Programming Language :: Python :: 3.3',
        'Programming Language :: Python :: 3.4',
        'Programming Language :: Python :: 3.5',
        'Programming Language :: Python :: 3.6',
    ],
      ext_modules=extensions)
