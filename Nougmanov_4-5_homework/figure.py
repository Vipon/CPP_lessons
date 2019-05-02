class gObject:
    def __init__(self, height, width, x=0, y=0):
        if height < 0 or width < 0: raise ValueError
        self.height = height
        self.width = width
        # coordinates of our figure
        self.x = x
        self.y = y

    def draw(self):
        print(type(self).__name__ + ':' + str(self))

    def move(self, dx, dy):
        self.x += dx
        self.y += dy

    def axial_tension(self, t_x, t_y):
        self.height *= t_y
        self.y *= t_y
        self.width *= t_x
        self.x *= t_x
        return self

    def coordinates(self):
        return [self.x, self.y]

    def __str__(self):
        return '{width=' + str(self.width) + ', height=' + str(self.height) + '}' + str(tuple(self.coordinates()))


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


class rectangle(gObject):
    def __init__(self, a_y, b_x, x=0, y=0):
        self.a_y = a_y
        self.b_x = b_x
        super().__init__(self, a_y, b_x, x, y)

    def axial_tension(self, t_x, t_y):
        self.a_y *= t_y
        self.b_x *= t_x
        return gObject.axial_tension(self, t_x, t_y)

    def __str__(self):
        return '{a=' + str(self.a_y) + ', b=' + str(self.b_x) + '}' + str(tuple(self.coordinates()))


class square(rectangle):
    def __init__(self, a, x, y):
        self.a = a
        super().__init__(self, a, a, x, y)

    def axial_tension(self, t_x, t_y):
        if t_x == t_y:
            self.a *= t_x
        else:
            self = rectangle(self.a * t_y, self.a * t_x, self.x, self.y)
        return self

    def __str__(self):
        return '{a=' + str(self.a_y) + '}' + str(tuple(self.coordinates()))


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


E = triangle(1, 2, 3, 4, 5)
E.axial_tension(2, 2).draw()
