#!/bin/sh
# Author: ChienYu Lin
# Date: 2018.02.07

# build and test cy_queue_test
gcc -o cy_queue_test cy_queue.c cy_queue_test.c

if ./cy_queue_test
then
    echo test passed >&2
else
    echo test failed >&2
fi
