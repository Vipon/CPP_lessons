from gObject import *


class ellipse(gObject):
    def __init__(self, a, b, x=0, y=0):
        # 'a' and 'b' are half shafts
        self.a = a
        self.b = b
        super().__init__(2 * a, 2 * b, x, y)

    def axial_tension(self, t_x, t_y):
        self.a *= t_x
        self.b *= t_y
        return gObject.axial_tension(self, t_x, t_y)

    def __str__(self):
        return '{a=' + str(self.a) + ', b=' + str(self.b) + '}' + str(tuple(self.coordinates()))
