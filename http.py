import os
import sys

os.chdir(os.path.dirname(__file__))


if "retrieve" in sys.argv:
    path = sys.argv[2]
