all:
	python setup.py build_ext -if
clean:
	-rm -r build py_ushuffle.c py_ushuffle.so
