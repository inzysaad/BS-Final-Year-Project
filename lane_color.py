import cv2
import numpy as np
import math

theta = 0
minLineLength = 5
maxLineGap = 10

cap = cv2.VideoCapture(0)

while True:
    ret, image = cap.read()
    image=cv2.resize(image,(640, 480))
    frame = cv2.GaussianBlur(image, (5, 5), 0)
    hsv = cv2.cvtColor(frame, cv2.COLOR_BGR2HSV)
    low_yellow = np.array([18, 94, 140])
    up_yellow = np.array([48, 255, 255])
    mask = cv2.inRange(hsv, low_yellow, up_yellow)
    edges = cv2.Canny(mask, 75, 150)

    lines = cv2.HoughLinesP(edges, 1, np.pi / 180, 50,maxLineGap=50)
    if lines is not None:
        for x in range(0, len(lines)):
            for x1, y1, x2, y2 in lines[x]:
                cv2.line(image, (x1, y1), (x2, y2), (0, 255, 0), 2)
                theta = theta + math.atan2((y2 - y1), (x2 - x1))

    threshold = 6
    if theta > threshold:
        print("left")
    if theta < -threshold:
        print("right")
    if abs(theta) < threshold:
        print("straight")
    theta = 0
    cv2.imshow("Frame", image)
    key = cv2.waitKey(1) & 0xFF
    if key == ord("q"):
        break
