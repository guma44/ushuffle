#include <Python.h>

#include "ushuffle.h"

static int l_ = 0;

static PyObject *ushuffle_shuffle1(PyObject *self, PyObject *args) {
	const char *s;
	const int l;
	const int k;

	/* example python call: ushuffle.shuffle1('string', 6, 2) */
	if (!PyArg_ParseTuple(args, "sii", &s, &l, &k)) {
		l_ = 0;
		return NULL;
	}

	l_ = l;
	shuffle1(s, l, k);
	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *ushuffle_shuffle2(PyObject *self, PyObject *args) {
	char *t;
	PyObject *T;

	if (l_ <= 0)
		return NULL;

	if ((t = malloc((l_ + 1) * sizeof(char))) == NULL)
		return NULL;

	shuffle2(t);
	t[l_] = '\0';
	T = Py_BuildValue("s", t);
	free(t);
	return T;
}

static PyObject *ushuffle_shuffle(PyObject *self, PyObject *args) {
	const char *s;
	const int l;
	const int k;
	char *t;
	PyObject *T;

	/* example python call: ushuffle.shuffle('string', 6, 2) */
	if (!PyArg_ParseTuple(args, "sii", &s, &l, &k))
		return NULL;
	l_ = l;
	if ((t = malloc((l_ + 1) * sizeof(char))) == NULL)
		return NULL;

	shuffle(s, t, l, k);
	t[l_] = '\0';
	T = Py_BuildValue("s", t);
	free(t);
	return T;
}

static PyMethodDef ushuffleMethods[] = {
    {"shuffle",  ushuffle_shuffle,  METH_VARARGS,
		"Calls shuffle1 and shuffle2."},
    {"shuffle1", ushuffle_shuffle1, METH_VARARGS,
		"Initialize a string for shuffling."},
	{"shuffle2", ushuffle_shuffle2, METH_VARARGS,
		"Return a new permutation."},
    {NULL, NULL, 0, NULL}        /* Sentinel */
};

PyMODINIT_FUNC initushuffle(void) {
  (void) Py_InitModule("ushuffle", ushuffleMethods);
}
