# USAGE
# python colorspaces.py --image ../images/beach.png

# Import the necessary packages
import numpy as np
import argparse
import cv2

# Load the image and show it
image = cv2.imread('./demo.jpg')
cv2.imshow("Original", image)
cv2.waitKey(0)

# Convert the image to grayscale
gray = cv2.cvtColor(image, cv2.COLOR_BGR2GRAY)
cv2.imshow("Gray", gray)
cv2.waitKey(0)

# Convert the image to the HSV (Hue, Saturation, Value)
# color spaces
hsv = cv2.cvtColor(image, cv2.COLOR_BGR2HSV)
cv2.imshow("HSV", hsv)
cv2.waitKey(0)

# Convert the image to the L*a*b* color spaces
lab = cv2.cvtColor(image, cv2.COLOR_BGR2LAB)
cv2.imshow("L*a*b*", lab)
cv2.waitKey(0)
