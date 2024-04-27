import cv2
import numpy


def readImage(pic):
    image = cv2.imread("hw1_picture/hw1_picture/" + pic)
    return image


def toGray(img, pic):
    image = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)
    cv2.imwrite("output_picture/gray_" + pic, image)
    return image


def toMedainFilter(img, pic):
    image = cv2.medianBlur(img, 9)
    cv2.imwrite("output_picture/filter_" + pic, image)


def toBinFilter(img, pic):
    image = cv2.bilateralFilter(img, 50, 50, 1000)
    cv2.imwrite("output_picture/filter_" + pic, image)
    return image


def toBlurFilter(img, pic):
    image = cv2.Blur(img, (15, 15))
    cv2.imwrite("output_picture/filter_" + pic, image)


def toThreshold(img, pic, maxval):
    ret, thresh = cv2.threshold(img, 100, maxval, cv2.THRESH_OTSU)
    cv2.imwrite("output_picture/binarization_" + pic, thresh)
    return thresh


def toMorphology(img, pic):
    kernal = numpy.ones((5, 5), numpy.uint8)
    image = cv2.morphologyEx(img, cv2.MORPH_OPEN, kernal, iterations=3)
    cv2.imwrite("output_picture/morphology_" + pic, image)
    # return image


def drawRectanglePutText(img, pic):
    image = cv2.rectangle(img, (150, 200), (600, 600), (0, 120, 120), 5)
    image2 = cv2.putText(image, "Face", (150, 190),
                         cv2.FONT_HERSHEY_SIMPLEX, 1, (0, 255, 0), 2)
    cv2.imwrite("output_picture/label_" + pic, image2)


def main():
    print("Start reading pictures")
    img1 = readImage('pic1.jpg')
    img2 = readImage('pic2.jpg')
    img3 = readImage('pic3.jpg')
    print("Finish reading")
    print("Start To Gary")
    G_img1 = toGray(img1, 'pic1.jpg')
    G_img2 = toGray(img2, 'pic2.jpg')
    G_img3 = toGray(img3, 'pic3.jpg')
    print("Finish to Gray")
    print("Start to Filter")
    B_img1 = toBinFilter(G_img1, 'pic1.jpg')
    B_img2 = toBinFilter(G_img2, 'pic2.jpg')
    B_img3 = toBinFilter(G_img3, 'pic3.jpg')
    print("Finish to Filter")
    print("Start to Threshold")
    T_img1 = toThreshold(B_img1, 'pic1.jpg', 300)
    T_img2 = toThreshold(B_img2, 'pic2.jpg', 300)
    T_img3 = toThreshold(B_img3, 'pic3.jpg', 300)
    print("Finish to Threshold")
    print("Start to Morphology")
    toMorphology(T_img1, 'pic1.jpg')
    toMorphology(T_img2, 'pic2.jpg')
    toMorphology(T_img3, 'pic3.jpg')
    print("Finish to Morphology")
    print("Start to Draw Rectangle")
    People_img = readImage('people.jpg')
    drawRectanglePutText(People_img, 'people.jpg')
    print("Finish drawing Rectangle and putting Text")


main()
