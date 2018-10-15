from setuptools import setup, find_packages, Extension
from Cython.Build import cythonize

ext_type = Extension("ushuffle",
                     sources=["ushuffle.pyx",
                              "src/ushuffle.c"])

with open('README.rst') as readme_file:
    readme = readme_file.read()

requirements = [
    'Cython>=0.27'
]

setup(name="ushuffle",
    version="1.0.4",
    description="A Cython wrapper over uShuffle - a useful tool for shuffling biological sequences while preserving the k-let counts.",
    long_description=readme,
    author="Rafal Gumienny",
    author_email='guma44@gmail.com',
    url='https://github.com/guma44/ushuffle',
    packages=find_packages(include=['ushuffle']),
    include_package_data=True,
    install_requires=requirements,
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
      ext_modules=cythonize([ext_type]))
