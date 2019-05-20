from gObject import *


class segment(gObject):
    def __init__(self, x_1, y_1, x_2, y_2):
        self.x_1 = x_1
        self.x_2 = x_2
        self.y_1 = y_1
        self.y_2 = y_2
        super().__init__(abs(y_2 - y_1), abs(x_1 - x_2), (x_1 + x_2) / 2, (y_1 + y_2) / 2)

    def axial_tension(self, t_x, t_y):
        self.x_1 *= t_x
        self.x_2 *= t_x
        self.y_1 *= t_y
        self.y_2 *= t_y
        return super().axial_tension(t_x, t_y)

    def __str__(self):
        return '{A:(' + str(self.x_1) + ',' + str(self.y_1) + '), B:(' + str(self.x_2) + ',' + str(
            self.y_2) + ')}' + str(tuple(self.coordinates()))
