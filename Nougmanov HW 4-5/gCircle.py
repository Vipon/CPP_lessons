from gEllipse import *


class circle(ellipse):
    def __init__(self, r, x=0, y=0):
        # 'r' - radius
        self.r = r
        super().__init__(r, r, x, y)

    def axial_tension(self, t_x, t_y):
        ellipse.axial_tension(self, t_x, t_y)
        if t_x == t_y:
            self.r *= t_x
        else:
            # here is some magic with free typification
            self = ellipse(self.a, self.b, self.x, self.y)
        return self

    def __str__(self):
        return '{r=' + str(self.r) + '}' + str(tuple(self.coordinates()))
