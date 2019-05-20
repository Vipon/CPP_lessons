from gObject import *


class rectangle(gObject):
    def __init__(self, a_y, b_x, x=0, y=0):
        self.a_y = a_y
        self.b_x = b_x
        super().__init__(a_y, b_x, x, y)

    def axial_tension(self, t_x, t_y):
        self.a_y *= t_y
        self.b_x *= t_x
        return gObject.axial_tension(self, t_x, t_y)

    def __str__(self):
        return '{a=' + str(self.a_y) + ', b=' + str(self.b_x) + '}' + str(tuple(self.coordinates()))
