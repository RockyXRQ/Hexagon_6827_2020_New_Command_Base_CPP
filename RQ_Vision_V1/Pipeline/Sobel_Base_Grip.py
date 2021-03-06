from cv2 import cv2
import numpy
import math
from enum import Enum
# Not good to be used.


class GripPipeline:
    """
    An OpenCV pipeline generated by GRIP.
    """

    def __init__(self):
        """initializes all values to presets or None if need to be set
        """

        self.desaturate_output = None

        self.__cv_sobel_0_src = self.desaturate_output
        self.__cv_sobel_0_dx = 2.0
        self.__cv_sobel_0_dy = 0.0
        self.__cv_sobel_0_ksize = 1.0
        self.__cv_sobel_0_scale = 3.0
        self.__cv_sobel_0_delta = 0.0
        self.__cv_sobel_0_bordertype = cv2.BORDER_DEFAULT

        self.cv_sobel_0_output = None

        self.__cv_sobel_1_src = self.desaturate_output
        self.__cv_sobel_1_dx = 0.0
        self.__cv_sobel_1_dy = 1.0
        self.__cv_sobel_1_ksize = 1.0
        self.__cv_sobel_1_scale = 3.0
        self.__cv_sobel_1_delta = 0.0
        self.__cv_sobel_1_bordertype = cv2.BORDER_DEFAULT

        self.cv_sobel_1_output = None

        self.__cv_addweighted_src1 = self.cv_sobel_0_output
        self.__cv_addweighted_alpha = 0.5
        self.__cv_addweighted_src2 = self.cv_sobel_1_output
        self.__cv_addweighted_beta = 0.5
        self.__cv_addweighted_gamma = 0.0

        self.cv_addweighted_output = None

        self.__cv_threshold_src = self.cv_addweighted_output
        self.__cv_threshold_thresh = 40.0
        self.__cv_threshold_maxval = 255.0
        self.__cv_threshold_type = cv2.THRESH_BINARY

        self.cv_threshold_output = None

        self.__blur_input = self.cv_threshold_output
        self.__blur_type = BlurType.Median_Filter
        self.__blur_radius = 0.0

        self.blur_output = None

        self.__find_contours_input = self.blur_output
        self.__find_contours_external_only = True

        self.find_contours_output = None

        self.__filter_contours_contours = self.find_contours_output
        self.__filter_contours_min_area = 1.0
        self.__filter_contours_min_perimeter = 0.0
        self.__filter_contours_min_width = 1.0
        self.__filter_contours_max_width = 1000.0
        self.__filter_contours_min_height = 1.0
        self.__filter_contours_max_height = 1000.0
        self.__filter_contours_solidity = [0.0, 100.0]
        self.__filter_contours_max_vertices = 1000000.0
        self.__filter_contours_min_vertices = 0.0
        self.__filter_contours_min_ratio = 0.0
        self.__filter_contours_max_ratio = 1000.0

        self.filter_contours_output = None

    def process(self, source0):
        """
        Runs the pipeline and sets all outputs to new values.
        """
        # Step Desaturate0:
        self.__desaturate_input = source0
        (self.desaturate_output) = self.__desaturate(self.__desaturate_input)

        # Step CV_Sobel0:
        self.__cv_sobel_0_src = self.desaturate_output
        (self.cv_sobel_0_output) = self.__cv_sobel(self.__cv_sobel_0_src, self.__cv_sobel_0_dx, self.__cv_sobel_0_dy,
                                                   self.__cv_sobel_0_ksize, self.__cv_sobel_0_scale, self.__cv_sobel_0_delta, self.__cv_sobel_0_bordertype)

        # Step CV_Sobel1:
        self.__cv_sobel_1_src = self.desaturate_output
        (self.cv_sobel_1_output) = self.__cv_sobel(self.__cv_sobel_1_src, self.__cv_sobel_1_dx, self.__cv_sobel_1_dy,
                                                   self.__cv_sobel_1_ksize, self.__cv_sobel_1_scale, self.__cv_sobel_1_delta, self.__cv_sobel_1_bordertype)

        # Step CV_addWeighted0:
        self.__cv_addweighted_src1 = self.cv_sobel_0_output
        self.__cv_addweighted_src2 = self.cv_sobel_1_output
        (self.cv_addweighted_output) = self.__cv_addweighted(self.__cv_addweighted_src1, self.__cv_addweighted_alpha,
                                                             self.__cv_addweighted_src2, self.__cv_addweighted_beta, self.__cv_addweighted_gamma)

        # Step CV_Threshold0:
        self.__cv_threshold_src = self.cv_addweighted_output
        (self.cv_threshold_output) = self.__cv_threshold(self.__cv_threshold_src,
                                                         self.__cv_threshold_thresh, self.__cv_threshold_maxval, self.__cv_threshold_type)

        # Step Blur0:
        self.__blur_input = self.cv_threshold_output
        (self.blur_output) = self.__blur(
            self.__blur_input, self.__blur_type, self.__blur_radius)

        # Step Find_Contours0:
        self.__find_contours_input = self.blur_output
        (self.find_contours_output) = self.__find_contours(
            self.__find_contours_input, self.__find_contours_external_only)

        # Step Filter_Contours0:
        self.__filter_contours_contours = self.find_contours_output
        (self.filter_contours_output) = self.__filter_contours(self.__filter_contours_contours, self.__filter_contours_min_area, self.__filter_contours_min_perimeter, self.__filter_contours_min_width, self.__filter_contours_max_width,
                                                               self.__filter_contours_min_height, self.__filter_contours_max_height, self.__filter_contours_solidity, self.__filter_contours_max_vertices, self.__filter_contours_min_vertices, self.__filter_contours_min_ratio, self.__filter_contours_max_ratio)

    @staticmethod
    def __desaturate(src):
        """Converts a color image into shades of gray.
        Args:
            src: A color numpy.ndarray.
        Returns:
            A gray scale numpy.ndarray.
        """
        (a, b, channels) = src.shape
        if(channels == 1):
            return numpy.copy(src)
        elif(channels == 3):
            return cv2.cvtColor(src, cv2.COLOR_BGR2GRAY)
        elif(channels == 4):
            return cv2.cvtColor(src, cv2.COLOR_BGRA2GRAY)
        else:
            raise Exception("Input to desaturate must have 1, 3 or 4 channels")

    @staticmethod
    def __cv_sobel(src, dx, dy, k_size, scale, delta, border_type):
        """Find edges by calculating the requested derivative order for the given image.
        Args:
            src: A numpy.ndarray.
            k_size: Odd number that is size of the kernel.
            scale: Scaling factor for Sobel.
            delta: Offset for values in Sobel.
            border_type: Opencv enum.
        Returns:
            The result as a numpy.ndarray.
        """
        return cv2.Sobel(src, 0, (int)(dx + 0.5), (int)(dy + 0.5), (int)(k_size + 0.5),
                         scale=scale, delta=delta, borderType=border_type)

    @staticmethod
    def __cv_addweighted(src1, alpha, src2, beta, gamma):
        """Computes the weighted addition of two Mats.
        Args:
            src1: A numpy.ndarray.
            alpha: The weight for the first Mat.
            src2: A numpy.ndarray.
            beta: The weight for the second Mat.
            gamma: Constant to add to each sum.
        Returns:
            A numpy.ndarray.
        """
        return cv2.addWeighted(src1, alpha, src2, beta, gamma)

    @staticmethod
    def __cv_threshold(src, thresh, max_val, type):
        """Apply a fixed-level threshold to each array element in an image
        Args:
            src: A numpy.ndarray.
            thresh: Threshold value.
            max_val: Maximum value for THRES_BINARY and THRES_BINARY_INV.
            type: Opencv enum.
        Returns:
            A black and white numpy.ndarray.
        """
        return cv2.threshold(src, thresh, max_val, type)[1]

    @staticmethod
    def __blur(src, type, radius):
        """Softens an image using one of several filters.
        Args:
            src: The source mat (numpy.ndarray).
            type: The blurType to perform represented as an int.
            radius: The radius for the blur as a float.
        Returns:
            A numpy.ndarray that has been blurred.
        """
        if(type is BlurType.Box_Blur):
            ksize = int(2 * round(radius) + 1)
            return cv2.blur(src, (ksize, ksize))
        elif(type is BlurType.Gaussian_Blur):
            ksize = int(6 * round(radius) + 1)
            return cv2.GaussianBlur(src, (ksize, ksize), round(radius))
        elif(type is BlurType.Median_Filter):
            ksize = int(2 * round(radius) + 1)
            return cv2.medianBlur(src, ksize)
        else:
            return cv2.bilateralFilter(src, -1, round(radius), round(radius))

    @staticmethod
    def __find_contours(input, external_only):
        """Sets the values of pixels in a binary image to their distance to the nearest black pixel.
        Args:
            input: A numpy.ndarray.
            external_only: A boolean. If true only external contours are found.
        Return:
            A list of numpy.ndarray where each one represents a contour.
        """
        if(external_only):
            mode = cv2.RETR_EXTERNAL
        else:
            mode = cv2.RETR_LIST
        method = cv2.CHAIN_APPROX_SIMPLE
        im2, contours, hierarchy = cv2.findContours(
            input, mode=mode, method=method)
        return contours

    @staticmethod
    def __filter_contours(input_contours, min_area, min_perimeter, min_width, max_width,
                          min_height, max_height, solidity, max_vertex_count, min_vertex_count,
                          min_ratio, max_ratio):
        """Filters out contours that do not meet certain criteria.
        Args:
            input_contours: Contours as a list of numpy.ndarray.
            min_area: The minimum area of a contour that will be kept.
            min_perimeter: The minimum perimeter of a contour that will be kept.
            min_width: Minimum width of a contour.
            max_width: MaxWidth maximum width.
            min_height: Minimum height.
            max_height: Maximimum height.
            solidity: The minimum and maximum solidity of a contour.
            min_vertex_count: Minimum vertex Count of the contours.
            max_vertex_count: Maximum vertex Count.
            min_ratio: Minimum ratio of width to height.
            max_ratio: Maximum ratio of width to height.
        Returns:
            Contours as a list of numpy.ndarray.
        """
        output = []
        for contour in input_contours:
            x, y, w, h = cv2.boundingRect(contour)
            if (w < min_width or w > max_width):
                continue
            if (h < min_height or h > max_height):
                continue
            area = cv2.contourArea(contour)
            if (area < min_area):
                continue
            if (cv2.arcLength(contour, True) < min_perimeter):
                continue
            hull = cv2.convexHull(contour)
            if cv2.contourArea(hull) > 0:
                solid = 100 * area / cv2.contourArea(hull)
            if (solid < solidity[0] or solid > solidity[1]):
                continue
            if (len(contour) < min_vertex_count or len(contour) > max_vertex_count):
                continue
            ratio = (float)(w) / h
            if (ratio < min_ratio or ratio > max_ratio):
                continue
            output.append(contour)
        return output


BlurType = Enum(
    'BlurType', 'Box_Blur Gaussian_Blur Median_Filter Bilateral_Filter')
