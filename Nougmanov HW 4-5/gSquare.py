from gRectangle import *


class square(rectangle):
    def __init__(self, a, x=0, y=0):
        self.a = a
        super().__init__(a, a, x, y)

    def axial_tension(self, t_x, t_y):
        if t_x == t_y:
            self.a *= t_x
        else:
            self = rectangle(self.a * t_y, self.a * t_x, self.x, self.y)
        return self

    def __str__(self):
        return '{a=' + str(self.a_y) + '}' + str(tuple(self.coordinates()))
