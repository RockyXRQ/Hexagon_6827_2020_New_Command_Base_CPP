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

    else:
        m_table.putBoolean("IsHaveTarget", False)


def main():

    cap = cv2.VideoCapture(1)

    while cap.isOpened():
        have_frame, showFrame = cap.read()
        if have_frame:
            pipeline.process(showFrame)
            extra_processing(showFrame)


if __name__ == '__main__':
    main()
