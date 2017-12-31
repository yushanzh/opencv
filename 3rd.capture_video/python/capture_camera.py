import numpy as np
import cv2 as cv
import sys

cap = cv.VideoCapture(0)
if(not cap.isOpened()):
	exit()

#get default width and hight of frame.
print "Cap Frame Width="+str(cap.get(cv.CAP_PROP_FRAME_WIDTH))
print "Cap Frame Hight="+str(cap.get(cv.CAP_PROP_FRAME_HEIGHT))

#set width and hight
width_ret = cap.set(cv.CAP_PROP_FRAME_WIDTH,640) 
hight_ret = cap.set(cv.CAP_PROP_FRAME_HEIGHT,480)
if not width_ret or not hight_ret:
	exit();

startRecord = False
endRecord = False

# Define the codec and create VideoWriter object
fourcc = cv.VideoWriter_fourcc(*'XVID')
out = cv.VideoWriter('output.avi',fourcc, 20.0, (640,480))

while(True):
	# Capture frame-by-frame
	ret, frame = cap.read()
	
	# change color space(not use in this program).
	gray = cv.cvtColor(frame, cv.COLOR_BGR2GRAY)
	
	# Display the resulting frame
	#cv.imshow('frame',gray)
	cv.imshow('frame',frame)
	
	event_key = cv.waitKey(1) & 0xFF;
	
	#press 's' to start record video
    #press 'e' to end record video
	#press 'q' to break 
	if event_key == ord('s'):
		startRecord = True
		print "start record frame."
	elif event_key == ord('e'):
		endRecord = True 	
		print "end record frame."
	elif event_key == ord('q'):
		break
	
	# write the flipped frame
	if startRecord and not endRecord:
		out.write(frame)	
	
# When everything done, release the capture
cap.release()
out.release()
cv.destroyAllWindows()


