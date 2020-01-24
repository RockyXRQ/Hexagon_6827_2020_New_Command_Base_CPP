from cv2 import cv2
from HSV_Base_Grip import GripPipeline


def delet_contours(contours, delete_list):
    delta = 0
    for i in range(len(delete_list)):
        # print("i= ", i)
        del contours[delete_list[i] - delta]
        delta = delta + 1
    return contours


def extra_processing(showFrame, pipeline):
    """
    Performs extra processing on the pipeline's outputs and publishes data to NetworkTables.
    :param pipeline: the pipeline that just processed an image
    :return: None
    """
    center_x_positions = []
    center_y_positions = []
    widths = []
    heights = []

    # Find the bounding boxes of the contours to get x, y, width, and height
    for contour in pipeline.filter_contours_output:
        x, y, w, h = cv2.boundingRect(contour)
        # X and Y are coordinates of the top-left corner of the bounding box
        center_x_positions.append(x + w / 2)
        center_y_positions.append(y + h / 2)
        widths.append(w)
        heights.append(y)
        cv2.drawContours(showFrame, contour, -1, 255, 3)
        cv2.circle(
            showFrame, (int(center_x_positions[0]), int(center_y_positions[0])), 3, (0, 0, 255), -1)
        cv2.imshow("match?", showFrame)
        cv2.waitKey(10)
    print("X:", center_x_positions, "Y", center_y_positions)


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
