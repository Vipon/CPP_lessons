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
