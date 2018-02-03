# coding=utf-8
import numpy as np
import cv2


#定义滑动条的回调函数，这里什么也不做，直接pass即可。这里的x便是传递回来的滑动条的位置。我们可以print到控制台中。
def nothing(x):
	m_r = cv2.getTrackbarPos('R', 'Threshold Test')
	m_g = cv2.getTrackbarPos('G', 'Threshold Test')
	m_b = cv2.getTrackbarPos('B', 'Threshold Test')
	ret, result_r = cv2.threshold(r, m_r, 255, cv2.THRESH_TRUNC)
	ret, result_g = cv2.threshold(g, m_g, 255, cv2.THRESH_TRUNC)
	ret, result_b = cv2.threshold(b, m_b, 255, cv2.THRESH_TRUNC)
	img2 = cv2.merge((result_b,result_g,result_r))
	#img2 = cv2.merge((b,g,r))
	cv2.imshow("Threshold Test", img2)


# 首先读取一个图像用于处理
img = cv2.imread("./roma.jpg")
# 将图像转换为灰度图

#gray = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)

# 一些变量的初始化
threshold_r = 0
threshold_g = 0
threshold_b = 0
#result = gray

# 新建一个窗口，并命名为Threshold Test
cv2.namedWindow("Threshold Test")

# 创建三个进度条，分别用于控制阈值大小和效果开关
# 第一个参数是进度条的名字，也是识别进度条的唯一ID
# 第二个参数是需要绑定进度条的窗体的名字
# 第三个参数是进度条的初始值
# 第四个参数是进度条的最大值
# 第五个参数是回调函数，每次滑动都会调用回调函数。通常包含一个默认参数，即滑动条的位置。在这里我们不做任何事情直接定义一个函数然后pass即可
cv2.createTrackbar('R', 'Threshold Test', threshold_r, 255, nothing)
cv2.createTrackbar('G', 'Threshold Test', threshold_g, 255, nothing)
cv2.createTrackbar('B', 'Threshold Test', threshold_b, 255, nothing)


b,g,r = cv2.split(img)
cv2.imshow("Threshold Test",img)

cv2.waitKey(0)
# 最后完成之后别忘销毁窗口
cv2.destroyAllWindows()
