all:
	python setup.py build_ext -if
clean:
	-rm -r build ushuffle.c ushuffle.so
