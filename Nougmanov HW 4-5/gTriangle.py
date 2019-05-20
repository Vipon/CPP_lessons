from gObject import *


class triangle(gObject):
    def __init__(self, a, b, c, x=0, y=0):
        # 'a, b, c' - are sides of this triangle
        self.a = a
        self.b = b
        self.c = c
        from math import sqrt
        # height can be found from Geron's formula
        p = (a + b + c) / 2
        super().__init__(sqrt(p * (p - a) * (p - b) * (p - c)) * 2 / b, b, x, y)

    def axial_tension(self, t_x, t_y):
        from math import sqrt
        self.a = sqrt((self.height * t_y) ** 2 + (self.a ** 2 - self.height ** 2) * t_x ** 2)
        self.b *= t_x
        self.c = sqrt((self.height * t_y) ** 2 + (self.c ** 2 - self.height ** 2) * t_x ** 2)
        return gObject.axial_tension(self, t_x, t_y)

    def __str__(self):
        return '{a=' + str(self.a) + ', b=' + str(self.b) + ', c=' + str(self.c) + '}' + str(tuple(self.coordinates()))
