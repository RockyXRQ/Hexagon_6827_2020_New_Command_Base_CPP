from cv2 import cv2
import Pipeline
from networktables import NetworkTablesInstance
import threading


pipeline = Pipeline.HSV_Base_Grip.GripPipeline()


def extra_processing(showFrame):
    global pipeline

    m_table = NetworkTablesInstance.getDefault().getTable("JETSONNANO")

    # Get the biggest contor and process.
    if pipeline.filter_contours_output:
        m_MAXCnt = sorted(pipeline.filter_contours_output,
                          key=cv2.contourArea)[0]
        # Find the bounding boxes of the contour to get x, y, width, and height.
        x, y, w, h = cv2.boundingRect(m_MAXCnt)

        # Dilver data to roborio by NetworkTable.
        m_table.putBoolean("IsHaveTarget", True)
        m_table.putNumber("SpinError", (x + w / 2) - showFrame.shape[1]/2)

        # Show the image when you need it.
        cv2.drawContours(showFrame, m_MAXCnt, -1, 255, 3)
        cv2.circle(
            showFrame, (int(x + w / 2), int(y + h / 2)), 3, (0, 0, 255), -1)
        print("Target Get!!! ", "X:", int(x + w / 2), "Y:",
              int(y + h / 2), "Error:", (x + w / 2) - showFrame.shape[1]/2)

    else:
        m_table.putBoolean("IsHaveTarget", False)
        print("Target Lose QvQ")


def main():

    print('Creating video capture')

    cap = cv2.VideoCapture(1)

    while cap.isOpened():
        timer = cv2.getTickCount()
        have_frame, showFrame = cap.read()
        if have_frame:
            pipeline.process(showFrame)
            extra_processing(showFrame)

        cv2.putText(showFrame, "FPS : " + str(int(cv2.getTickFrequency() / (cv2.getTickCount() - timer))), (100, 50),
                    cv2.FONT_HERSHEY_SIMPLEX, 0.75, (50, 170, 50), 2)
        cv2.imshow("match?", showFrame)
        cv2.waitKey(1)
    print('Capture closed')


if __name__ == '__main__':
    main()
