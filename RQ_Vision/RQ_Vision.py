from cv2 import cv2
from HSV_Base_Grip import GripPipeline
from networktables import NetworkTablesInstance

# TODO1: Add new thread.

def extra_processing(showFrame, pipeline):
    m_table = NetworkTablesInstance.getDefault().getTable("JETSONNANO")

    # Get the biggest contor.
    if pipeline.filter_contours_output:
        m_MAXCnt = sorted(pipeline.filter_contours_output,
                          key=cv2.contourArea)[0]
        # Find the bounding boxes of the contour to get x, y, width, and height
        x, y, w, h = cv2.boundingRect(m_MAXCnt)
        m_table.putBoolean("isHaveTarget", True)
        m_table.putNumber("SpinError", (x + w / 2) - showFrame.shape[1])
        cv2.drawContours(showFrame, m_MAXCnt, -1, 255, 3)
        cv2.circle(
            showFrame, (int(x + w / 2), int(y + h / 2)), 3, (0, 0, 255), -1)
        print("Target Get!!! ","X:", int(x + w / 2), "Y:", int(y + h / 2))
    else:
        print("Target Lose QvQ")
        m_table.putBoolean("isHaveTarget", False)

    cv2.imshow("match?", showFrame)
    cv2.waitKey(1)


def main():
    print('Creating video capture')
    cap = cv2.VideoCapture(1)
    print("here")
    print('Creating pipeline')
    pipeline = GripPipeline()
    print('Running pipeline')
    while cap.isOpened():
        have_frame, frame = cap.read()
        if have_frame:
            pipeline.process(frame)
            extra_processing(frame, pipeline)

    print('Capture closed')

if __name__ == '__main__':
    main()