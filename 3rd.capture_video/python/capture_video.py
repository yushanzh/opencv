# -*- coding: utf-8 -*-  
import numpy as np
import cv2 as cv
import sys

cap = cv.VideoCapture("/Users/zhangyushan/Downloads/傲骨之战.The.Good.Fight.S01E06.中英字幕.WEBrip.720P.mp4")
#cap = cv.VideoCapture("/Users/zhangyushan/Downloads/opencv/samples/data/Megamind_bugy.avi");

if not cap.isOpened():
	print 'Open video false.'
	exit()

#get default width and hight of frame.
print "Cap Frame Width="+str(cap.get(cv.CAP_PROP_FRAME_WIDTH))
print "Cap Frame Hight="+str(cap.get(cv.CAP_PROP_FRAME_HEIGHT))

totalFrameNumber = cap.get(cv.CAP_PROP_FRAME_COUNT);
print 'totalFrameNumber='+str(totalFrameNumber)

startRecord = False
endRecord = False

i = 0
while(True):
	# Capture frame-by-frame
	ret, frame = cap.read()
	if not ret:
		exit()
	# change color space(not use in this program).
	#gray = cv.cvtColor(frame, cv.COLOR_BGR2GRAY)
	
	# Display the resulting frame
	#cv.imshow('frame',gray)
	cv.imshow('frame',frame)
	print "DDDDDDDD"
	event_key = cv.waitKey(1) & 0xFF;
	
	i = i + 1
	
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
	
# When everything done, release the capture
cv.waitKey(0)
cap.release()
#out.release()
cv.destroyAllWindows()


