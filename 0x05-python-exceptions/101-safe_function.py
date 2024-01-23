#!/usr/bin/python3
from _future_ import print_function
import sys

def safe_function(fct, *args):
try:
res = fct(*args)
except Exception as e:
print("Exception: {}".format(e), file=sys.stderr)
return None
else:
return res
