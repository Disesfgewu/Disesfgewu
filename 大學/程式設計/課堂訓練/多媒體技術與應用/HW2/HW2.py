import os
import cv2
import numpy
import shutil
from time import sleep


def addDir(folder):
    if os.path.isdir("./" + folder):
        shutil.rmtree("./" + folder)
        sleep(2)
    os.mkdir("./" + folder)


def readImage(image):
    img = cv2.imread("./pic/" + image)
    return img


def toGray(image):
    img = cv2.cvtColor(image, cv2.COLOR_BGR2GRAY)
    return img


image1 = readImage("1.jpg")
image2 = readImage("2.jpg")
image3 = readImage("3.jpg")
addDir("out_pic")
image1_gray = toGray(image1)
cv2.imwrite("./out_pic/gray_1.jpg", image1_gray)
image2_gray = toGray(image2)
cv2.imwrite("./out_pic/gray_2.jpg", image2_gray)
image3_gray = toGray(image3)
cv2.imwrite("./out_pic/gray_3.jpg", image3_gray)

image1_blurred = cv2.GaussianBlur(image1_gray, (11, 11), 1550)
cv2.imwrite("./out_pic/filter_1.jpg", image1_blurred)
image1_Canny = cv2.Canny(image1_blurred, 50, 55)
cv2.imshow("img", image1_Canny)
cv2.waitKey(1000)
cv2.destroyAllWindows()
cv2.imwrite("./out_pic/Canny_1.jpg", image1_Canny)
image1_morph = cv2.morphologyEx(
    image1_Canny, cv2.MORPH_CLOSE, numpy.ones((11, 11), numpy.uint8), iterations=1)

cv2.imwrite("./out_pic/morphology_1.jpg", image1_morph)
lines1 = cv2.HoughLinesP(image1_morph, 1, numpy.pi/180,
                         100, minLineLength=100, maxLineGap=10)
line1 = numpy.copy(readImage("1.jpg"))
if lines1 is not None:
    for i in lines1:
        for x1, y1, x2, y2 in i:
            cv2.line(line1, (x1, y1), (x2, y2), (0, 0, 200), 4)
cv2.imwrite("./out_pic/line1.png", line1)
"""
_, image1_bin = cv2.threshold(image1_blurred, 140, 240, type=cv2.THRESH_BINARY)
cv2.imwrite("./out_pic/bin_1.jpg", image1_bin)
image1_edges = cv2.Scharr(image1_bin, cv2.CV_64F, 0, 1)
image1_edges = cv2.convertScaleAbs(image1_edges)
cv2.imwrite("./out_pic/edge_1.jpg", image1_edges)
kernal = numpy.ones((5, 5), numpy.uint8)
"""
"""
#########################################################################################
image2_blurred = cv2.medianBlur(image2_gray, 39)
cv2.imwrite("./out_pic/filter_2.jpg", image2_blurred)
_, image2_bin = cv2.threshold(
    image2_blurred, 105, 250, type=cv2.THRESH_BINARY)
cv2.imwrite("./out_pic/bin_2.jpg", image2_bin)
image2_edges = cv2.Scharr(image2_bin, cv2.CV_32F, 0, 1)
image2_edges = cv2.convertScaleAbs(image2_edges)
cv2.imwrite("./out_pic/edge_2.jpg", image2_edges)
kernal = numpy.ones((11, 11), numpy.uint8)
image2_morph = cv2.morphologyEx(
    image2_edges, cv2.MORPH_CLOSE, kernal, iterations=15)
cv2.imwrite("./out_pic/morphology_2.jpg", image2_morph)
lines2 = cv2.HoughLinesP(image2_morph, 1, numpy.pi/180,
                         100, minLineLength=100, maxLineGap=10)
line2 = numpy.copy(readImage("2.jpg"))
if lines2 is not None:
    for i in lines2:
        for x1, y1, x2, y2 in i:
            if x1 != x2 and abs((y1 - y2)/(x1 - x2)) > 0.3:
                cv2.line(line2, (x1, y1), (x2, y2), (250, 0, 0), 2)
cv2.imwrite("./out_pic/line2.png", line2)
#########################################################################################
image3_blurred = cv2.bilateralFilter(image3_gray, 50, 50, 1000)
cv2.imwrite("./out_pic/filter_3.jpg", image3_blurred)
_, image3_bin = cv2.threshold(
    image3_blurred, 130, 250, type=cv2.THRESH_BINARY)
cv2.imwrite("./out_pic/bin_3.jpg", image3_bin)
image3_edges = cv2.Canny(image3_bin, 200, 100)
image3_edges = cv2.convertScaleAbs(image3_edges)
cv2.imwrite("./out_pic/edge_3.jpg", image3_edges)
kernal = numpy.ones((3, 3), numpy.uint8)
image3_morph = cv2.morphologyEx(
    image3_edges, cv2.MORPH_CLOSE, kernal, iterations=15)
cv2.imwrite("./out_pic/morphology_3.jpg", image3_morph)
lines3 = cv2.HoughLinesP(image3_morph, 1, numpy.pi/180,
                         100, minLineLength=100, maxLineGap=10)
line3 = numpy.copy(readImage("3.jpg"))
if lines3 is not None:
    for i in lines3:
        for x1, y1, x2, y2 in i:
            cv2.line(line3, (x1, y1), (x2, y2), (250, 0, 0), 4)
cv2.imwrite("./out_pic/line3.png", line3)
"""
