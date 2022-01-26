from PIL import Image
import sys, os

# This is an optional script which you can use. It is not required for you to use
# this script to complete the assignment. But, it might be helpful.

# To use this script to create your own PPM files you obviously need Python 
# installed as well as PIL.
  
def convert(filename):
  im = Image.open(filename)
  im = im.convert(mode='RGB')
  im.save(F"{os.path.splitext(filename)[0]}.ppm", "PPM")
  
print("View image [1] or convert image [2]. Enter choice: ", end="")
sys.stdout.flush()
task = sys.stdin.readline()[:-1]

print("Enter file name: ", end="")
sys.stdout.flush()
image_name = sys.stdin.readline()[:-1]

if task[0] == "1":
  convert(image_name)
else:
  im = Image.open(filename)
  im.show()