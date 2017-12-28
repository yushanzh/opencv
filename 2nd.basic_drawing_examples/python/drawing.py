# USAGE
# python drawing.py

# Import the necessary packages
import numpy as np
import cv2

def draw_line():
	# Draw a green line from the top-left corner of our canvas
	# to the bottom-right
	green = (0, 255, 0)
	cv2.line(canvas, (0, 0), (300, 300), green)
	cv2.imshow("Canvas", canvas)
	cv2.waitKey(0)

def draw_rectangle():
	# Draw a green 50x50 pixel square, starting at 10x10 and
	# ending at 60x60
	green = (0, 255, 0)
	cv2.rectangle(canvas, (10, 10), (60, 60), green)
	cv2.imshow("Canvas", canvas)
	cv2.waitKey(0)

def draw_ellipse():
	red = (255, 0, 0)
	cx,cy = 201,113
	ax1,ax2 = 37,27
	angle = -108
	center = (cx,cy)
	axes = (ax1,ax2)
	cv2.ellipse(canvas, center, axes, angle, 0, 360, red, 2)

def draw_circle():
	# Reset our canvas and draw a white circle at the center
	# of the canvas with increasing radii - from 25 pixels to
	# 150 pixels
	(centerX, centerY) = (canvas.shape[1] / 2, canvas.shape[0] / 2)
	white = (255, 255, 255)
	for r in xrange(0, 175, 25):
		cv2.circle(canvas, (centerX, centerY), r, white)
	cv2.imshow("Canvas", canvas)
	cv2.waitKey(0)

def draw_fillpoly():
	pts = np.array([[10,5],[20,30],[70,20],[50,10]], np.int32)  
	pts = pts.reshape((-1,1,2))  
	cv2.polylines(canvas,[pts],True,(0,255,255),3)
	cv2.imshow("Canvas", canvas)
 	cv2.waitKey(0)
	
	

def draw_color():
	# Let's go crazy and draw 25 random circles
	for i in xrange(0, 25):
		# randomly generate a radius size between 5 and 200,
		# generate a random color, and then pick a random
		# point on our canvas where the circle will be drawn
		radius = np.random.randint(5, high = 200)
		color = np.random.randint(0, high = 256, size = (3,)).tolist()
		pt = np.random.randint(0, high = 300, size = (2,))
		# draw our random circle
		cv2.circle(canvas, tuple(pt), radius, color, -1)

	# Show our masterpiece
	cv2.imshow("Canvas", canvas)
	cv2.waitKey(0)

def put_text():
	font = cv2.FONT_HERSHEY_SIMPLEX  
	cv2.putText(canvas, 'Hello zhangyushan', (10,50), font, 1, (255,255,255) , 2, cv2.LINE_AA)
	#cv2.putText(canvas, "Hello Zhangyushan", (50,50), cv2.FONT_HERSHEY_SIMPLEX, .6, (0, 255, 0), 1, 2)
	cv2.imshow("Canvas", canvas)
	cv2.waitKey(0)


if __name__=="__main__":
	#ap = argparse.ArgumentParser()
 	#ap.add_argument("-i", "--image", required = True,
	#	help = "Path to the image")
	#args = vars(ap.parse_args())
	
	# Initialize our canvas as a 300x300 with 3 channels,
	# Red, Green, and Blue, with a black background
	canvas = np.zeros((400, 400, 3), dtype = "uint8")
	draw_line();
	draw_rectangle()
	draw_ellipse()
	draw_circle()
	draw_fillpoly()
	draw_color()
	put_text()
